//
// Created by kiper220 on 24.09.2020.
//

#include "Lexer.h"
#include <iostream>
#include <set>
#include "string.h"

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

        LexElement::LexElement(string::iterator iterator_begin, string::iterator iterator_end): iterator_begin(move(iterator_begin)), iterator_end(move(iterator_end)) {}
        void LexElement::setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector) {
            this->visitorList = move(visitorVector);
        }
        Lexer::Lexer(string::iterator iterator_begin, string::iterator iterator_end): LexElement(iterator_begin, iterator_end) {}
        void Lexer::accept(AnalyzerVisitor& visitor) {
            if(this->iterator_begin < this->iterator_end){
                visitor.visitLexer(*this);
            }
        }
        void Lexer::acceptAll() {
            int Line = 0;
            while(this->iterator_begin < this->iterator_end){
                bool successful = false;
                for(auto visitor: this->visitorList){
                    while((*iterator_begin == ' ' || *iterator_begin == '\n' || *iterator_begin == '\t') && *iterator_begin != '\0'){
                        if(*iterator_begin == '\n') {
                            this->lexerOutput += "[NEWLINE]\n";
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
            this->lexerOutput += "[EOF]";
        }
        void Lexer::addLexerOutput(string data) {
            this->lexerOutput += data;
        }

        Lexer::operator string() {
            return this->lexerOutput;
        }

        string::iterator& Lexer::begin() {
            return this->iterator_begin;
        }
        string::iterator& Lexer::end() {
            return this->iterator_end;
        }

        bool IntegerLiteral::visitLexer(Lexer& lexer){
            if(*lexer.begin() >= '0' && *lexer.begin() <= '9' || *lexer.begin() == '-'){
                string data = "[IntegerLiteral, ";
                data += *lexer.begin();

                int j = 1;
                lexer.begin()++;

                while (*lexer.begin() >= '0' && *lexer.begin() <= '9'){
                    data += *lexer.begin();

                    j++;
                    lexer.begin()++;
                }
                if(*lexer.begin() == '.'){
                    lexer.begin() -= j;
                    return false;
                }
                data += "]\n";
                lexer.addLexerOutput(data);
                return true;
            }
            return false;
        }
        bool KeyWord::visitLexer(Lexer& lexer){
            if((*lexer.begin() >= 'A' && *lexer.begin() <= 'Z') || (*lexer.begin() >= 'a' && *lexer.begin() <= 'z')) {

                set<string>::iterator it;
                it = KeyWords.find(string(lexer.begin(), getFirstName(lexer.begin())));

                if (it != KeyWords.end()) {
                    string data = "[KeyWord, \"" + *it + "\"]\n";

                    lexer.addLexerOutput(data);
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

            string data = "[SymWord, \"";
            data.append(lexer.begin(), lexer.begin() + i);
            data += "\"]\n";

            lexer.addLexerOutput(data);
            lexer.begin() += i;
            return true;
        }
        bool StringLiteral::visitLexer(Lexer& lexer){
            if(lexer.begin()[0] == '"'){
                if(lexer.begin()[1] == '"'){
                    if(lexer.begin()[2] == '"')
                        return false;

                    lexer.addLexerOutput("[StringLiteral, \"\"]\n");
                    lexer.begin() += 2;
                    return true;
                }
                int i = 1;
                while(lexer.begin()[i] != '"' && lexer.begin()[i] != '\n' && lexer.begin()[i] != '\0') i++;

                if(lexer.begin()[i] == '\n' || lexer.begin()[i] == '\0')
                    return false;

                string data = "[StringLiteral, \"";
                data.append(lexer.begin() + 1, lexer.begin() + i);
                data += "\"]\n";

                lexer.addLexerOutput(data);
                lexer.begin() += i + 1;
                return true;
            }
            return false;
        }
        bool CharacterLiteral::visitLexer(Lexer& lexer){
            if(lexer.begin()[0] == '\''){
                if(lexer.begin()[1] == '\'')
                    return false;
                int i = 1;
                while(lexer.begin()[i] != '\'' && lexer.begin()[i] != '\n' && lexer.begin()[i] != '\0') i++;

                if(lexer.begin()[i] == '\n' || lexer.begin()[i] == '\0')
                    return false;

                string data = "[CharacterLiteral, '";
                data.append(lexer.begin() + 1, lexer.begin() + i);
                data += "']\n";

                lexer.addLexerOutput(data);
                lexer.begin() += i + 1;
                return true;
            }
            return false;
        }
        bool WysiwygString::visitLexer(Lexer& lexer){

        }
        bool WysiwygCharacter::visitLexer(Lexer& lexer){

        }
        bool HexString::visitLexer(Lexer& lexer){

        }
        bool HexCharacter::visitLexer(Lexer& lexer){

        }
        bool Operator::visitLexer(Lexer& lexer){
            if(!((*lexer.begin() >= 'A' && *lexer.begin() <= 'Z') ||
               (*lexer.begin() >= 'a' && *lexer.begin() <= 'z') ||
               (*lexer.begin() >= '0' && *lexer.begin() <= '9'))){
                auto it = Operators.find(string(lexer.begin(), getFirstOperator(lexer.begin())));
                if(it != Operators.end()){
                    lexer.addLexerOutput(string("[Operator, \"") + *it + "\"]\n");
                    lexer.begin() += (*it).size();
                    return true;
                }
            }
            return false;
        }
        bool Comments::visitLexer(Lexer& lexer){
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