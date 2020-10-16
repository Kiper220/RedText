//
// Created by kiper220 on 24.09.2020.
//

#include "Lexer.h"
#include <iostream>
#include <set>

namespace RT{
    namespace Lexer{
        const set<string> KeyWords = {
            "abstract","alias","align","asm","assert",
            "auto","body","bool","break","byte","case",
            "cast","catch","cdouble","cent","cfloat",
            "char","class","const","continue","creal",
            "dchar","debug","default","delegate","delete",
            "deprecated","do","double","else","enum",
            "export","extern","false","final","finally",
            "float","for","foreach","foreach_reverse",
            "function","goto","idouble","if","ifloat",
            "immutable","import","in","inout","int",
            "interface","invariant","ireal","is","lazy",
            "long","mixin","module","new","nothrow",
            "null","out","override","package","pragma",
            "private","protected","public","pure","real",
            "ref","return","scope","shared","short",
            "singleton","static","struct","super","switch",
            "synchronized","template","this","throw",
            "true","try","typeid","typeof","ubyte","ucent",
            "uint","ulong","union","unittest","ushort",
            "version","void","wchar","while","with",
            "__FILE__","__FILE_FULL_PATH__","__MODULE__",
            "__LINE__","__FUNCTION__","__PRETTY_FUNCTION__",
            "__gshared","__traits","__vector",
            "__parameters"
        };
        const set<string> Operators = {
            "/","/=",".","..","...","&","&=","&&",
            "|","|=","||","-","-=","--","+","+=",
            "++","<","<=","<<","<<=",">",">=",">>=",
            ">>>=",">>",">>>","!","!=","(",")","[",
            "]","{","}","?",",",";",":","$","=","==",
            "*","*=","%","%=","^","^=","^^","^^=",
            "~","~=","@","=>","#"
        };
        static string::iterator getFirstName(string::iterator iterator){
            int i;
            for(i = 0;(iterator[i] >= 'A' && iterator[i] <= 'Z') || (iterator[i] >= 'a' && iterator[i] <= 'z'); i++);

            return iterator+i;
        }
        static string::iterator getFirstOperator(string::iterator iterator){
            int i;
            for(i = 0;
            !(iterator[i] >= 'A' && iterator[i] <= 'Z') &&
            !(iterator[i] >= 'a' && iterator[i] <= 'z') &&
            !(iterator[i] >= '0' && iterator[i] <= '9') &&
            !(iterator[i] == ' ' || iterator[i] == '\n' ||
            iterator[i] == '\t' || iterator[i] == '\0'); i++){
                switch (iterator[i]) {
                    case '[':
                        return iterator+i+1;
                    case ']':
                        return iterator+i+1;
                    case '(':
                        return iterator+i+1;
                    case ')':
                        return iterator+i+1;
                    case '{':
                        return iterator+i+1;
                    case '}':
                        return iterator+i+1;
                    case '?':
                        return iterator+i+1;
                    case ',':
                        return iterator+i+1;
                    case ':':
                        return iterator+i+1;
                    case ';':
                        return iterator+i+1;
                    case '$':
                        return iterator+i+1;
                    case '@':
                        return iterator+i+1;
                    case '#':
                        return iterator+i+1;
                }
            }

            return iterator+i;
        }

        LexerInterface::LexerInterface(string::iterator iterator_begin, string::iterator iterator_end): iterator_begin(move(iterator_begin)), iterator_end(move(iterator_end)) {}
        void LexerInterface::setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector) {
            this->visitorList = move(visitorVector);
        }
        STDLexer::STDLexer(string::iterator iterator_begin, string::iterator iterator_end): LexerInterface(iterator_begin, iterator_end) {}
        void STDLexer::accept(AnalyzerVisitor& visitor) {
            if(this->iterator_begin < this->iterator_end){
                visitor.visitLexer(*this);
            }
        }
        void STDLexer::acceptAll() {
            int Line = 0;
            while(this->iterator_begin < this->iterator_end){
                bool successful = false;
                for(const auto& visitor: this->visitorList){
                    while((*iterator_begin == ' ' || *iterator_begin == '\n' || *iterator_begin == '\t') && *iterator_begin != '\0'){
                        if(*iterator_begin == '\n') {
                            this->addLexerOutput(NEWLINE, "");
                            Line++;
                        }
                        iterator_begin++;
                    }
                    if(visitor->visitLexer(*this)){
                        successful = true;
                        break;
                    }
                }
                if(*iterator_begin == '\0') break;
                if(!successful){
                    cerr << "Lexing error in line " << Line << ";\n";
                    exit(-11);
                }
            }
            this->addLexerOutput(EOC, "");
        }
        void STDLexer::addLexerOutput(LexiconType lexiconType, string lexicon){
            this->lexicalData.emplace_back(lexiconType, lexicon);
        }

        STDLexer::operator string() {
            auto it = this->lexicalData.begin();
            string returnData;

            while(it != this->lexicalData.end()){
                switch (it->first) {
                    case INTEGER_LITERAL:
                        returnData += "[IntegerLiteral, " + it->second + "]\n";
                        break;
                    case KEYWORD:
                        returnData += "[KeyWord, " + it->second + "]\n";
                        break;
                    case SYMWORD:
                        returnData += "[SymWord, \"" + it->second + "\"]\n";
                        break;
                    case STRING_LITERAL:
                        returnData += "[StringLiteral, \"" + it->second + "\"]\n";
                        break;
                    case CHARACTER_LITERAL:
                        returnData += "[CharacterLiteral, \'" + it->second + "\']\n";
                        break;
                    case HEX_STRING:
                        returnData += "[HexString, \"" + it->second + "\"]\n";
                        break;
                    case WYSIWYG_STRING:
                        returnData += "[WysiwygString, \"" + it->second + "\"]\n";
                        break;
                    case WYSIWYG_CHARACTER:
                        returnData += "[WysiwygCharacter, \'" + it->second + "\']\n";
                        break;
                    case HEX_CHARACTER:
                        returnData += "[HexCharacter, \'" + it->second + "\']\n";
                        break;
                    case OPERATOR:
                        returnData += "[Operator, \"" + it->second + "\"]\n";
                        break;
                    case NEWLINE:
                        returnData += "[NEWLINE]\n";
                        break;
                    case EOC:
                        returnData += "[EOC]\n";
                        break;
                }
                it++;
            }
            return returnData;
        }
        STDLexer::operator list<pair<LexiconType, string>>&() {
            return this->lexicalData;
        }

        string::iterator& STDLexer::begin() {
            return this->iterator_begin;
        }
        string::iterator& STDLexer::end() {
            return this->iterator_end;
        }

        list<pair<LexiconType, string>>& STDLexer::getData(){
            return this->lexicalData;
        }

        bool IntegerLiteral::visitLexer(STDLexer& lexer){
            if(*lexer.begin() >= '0' && *lexer.begin() <= '9' || *lexer.begin() == '-'){
                string value;

                int j = 1;
                lexer.begin()++;

                while (*lexer.begin() >= '0' && *lexer.begin() <= '9'){
                    value += *lexer.begin();

                    j++;
                    lexer.begin()++;
                }
                if(*lexer.begin() == '.'){
                    lexer.begin() -= j;
                    return false;
                }
                lexer.addLexerOutput(KEYWORD, value);
                return true;
            }
            return false;
        }
        bool KeyWord::visitLexer(STDLexer& lexer){
            if((*lexer.begin() >= 'A' && *lexer.begin() <= 'Z') || (*lexer.begin() >= 'a' && *lexer.begin() <= 'z')) {

                set<string>::iterator it;
                it = KeyWords.find(string(lexer.begin(), getFirstName(lexer.begin())));

                if (it != KeyWords.end()) {
                    lexer.addLexerOutput(KEYWORD, *it);
                    lexer.begin() += it->size();
                    return true;
                }

            }
            else return false;

            int i = 0;
            for(i = 0;
            (lexer.begin()[i] >= 'A' && lexer.begin()[i] <= 'Z') ||
            (lexer.begin()[i] >= 'a' && lexer.begin()[i] <= 'z') ||
            (lexer.begin()[i] >= '0' && lexer.begin()[i] <= '9'); i++);

            lexer.addLexerOutput(SYMWORD, string(lexer.begin(), lexer.begin() + i));
            lexer.begin() += i;
            return true;
        }
        bool StringLiteral::visitLexer(STDLexer& lexer){
            if(lexer.begin()[0] == '"'){
                if(lexer.begin()[1] == '"'){
                    if(lexer.begin()[2] == '"')
                        return false;

                    lexer.addLexerOutput(STRING_LITERAL, "");
                    lexer.begin() += 2;
                    return true;
                }
                int i = 1;
                while(lexer.begin()[i] != '"' && lexer.begin()[i] != '\n' && lexer.begin()[i] != '\0') i++;

                if(lexer.begin()[i] == '\n' || lexer.begin()[i] == '\0')
                    return false;

                lexer.addLexerOutput(STRING_LITERAL, string(lexer.begin() + 1, lexer.begin() + i));
                lexer.begin() += i + 1;
                return true;
            }
            return false;
        }
        bool CharacterLiteral::visitLexer(STDLexer& lexer){
            if(lexer.begin()[0] == '\''){
                if(lexer.begin()[1] == '\'')
                    return false;
                int i = 1;
                while(lexer.begin()[i] != '\'' && lexer.begin()[i] != '\n' && lexer.begin()[i] != '\0') i++;

                if(lexer.begin()[i] == '\n' || lexer.begin()[i] == '\0')
                    return false;

                lexer.begin() += i + 1;
                lexer.addLexerOutput(CHARACTER_LITERAL, string(lexer.begin() + 1, lexer.begin() + i));
                return true;
            }
            return false;
        }
        bool WysiwygString::visitLexer(STDLexer& lexer){
            return false;
        }
        bool WysiwygCharacter::visitLexer(STDLexer& lexer){
            return false;
        }
        bool HexString::visitLexer(STDLexer& lexer){
            return false;
        }
        bool HexCharacter::visitLexer(STDLexer& lexer){
            return false;
        }
        bool Operator::visitLexer(STDLexer& lexer){
            if(!((*lexer.begin() >= 'A' && *lexer.begin() <= 'Z') ||
               (*lexer.begin() >= 'a' && *lexer.begin() <= 'z') ||
               (*lexer.begin() >= '0' && *lexer.begin() <= '9'))){
                auto it = Operators.find(string(lexer.begin(), getFirstOperator(lexer.begin())));
                if(it != Operators.end()){
                    lexer.begin() += (*it).size();

                    lexer.addLexerOutput(OPERATOR, *it);
                    return true;
                }
            }
            return false;
        }
        bool Comments::visitLexer(STDLexer& lexer){
            if(lexer.begin()[0] == '/' && lexer.begin()[1] == '/'){
                int i = 0;
                while(lexer.begin()[i] != '\n' && lexer.begin()[i] != '\0') i++;
                lexer.begin() += i;
                return true;
            }
            else if(lexer.begin()[0] == '/' && lexer.begin()[1] == '*'){
                int i = 2;
                while(lexer.begin()[i] != '\0'){
                    if(lexer.begin()[i - 1] == '*' && lexer.begin()[i] == '/')
                        break;
                    i++;
                }
                if(lexer.begin()[i] == '\0')
                    return false;

                lexer.begin() += i + 1;
                return true;
            }
            return false;
        }
    }
}