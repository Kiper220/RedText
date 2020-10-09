//
// Created by kiper220 on 09.10.2020.
//

#include "Parser.h"
#include <iostream>

namespace RT{
    namespace Parser{
        ParserInstance::ParserInstance(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end): iterator_begin(iterator_begin), iterator_end(iterator_end){}
        void ParserInstance::setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector){
            this->visitorList = std::move(visitorVector);
        }

        STDParser::STDParser(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end): ParserInstance(iterator_begin, iterator_end){}

        void STDParser::acceptAll(){
            int Line = 0;
            while(this->iterator_begin->first != Lexer::EOC && this->iterator_begin != this->iterator_end){
                while(iterator_begin->first == Lexer::NEWLINE || iterator_begin->first == Lexer::EOC ) {
                    if(iterator_begin->first == Lexer::NEWLINE) Line++, iterator_begin++;
                    else return;
                }

                bool successful = false;
                for(const auto& visitor: this->visitorList){
                    if(visitor->visitParser(*this)){
                        successful = true;
                        break;
                    }
                }
                if(!successful){
                    cerr << "Parsing error in line " << Line << ";\n";
                    exit(-12);
                }
            }
        }

        list<pair<Lexer::LexiconType, string>>::iterator& STDParser::begin(){
            return this->iterator_begin;
        }
        list<pair<Lexer::LexiconType, string>>::iterator& STDParser::end(){
            return this->iterator_end;
        }

        STDParser::operator string(){
            return this->parsingData.dump(4);
        }
        STDParser::operator nlohmann::json&(){
            return this->parsingData;
        }

        void STDParser::accept(AnalyzerVisitor& visitor){
            if(this->iterator_begin != this->iterator_end){
                visitor.visitParser(*this);
            }
        }

        bool ImportToken::visitParser(STDParser& parser){
            if(parser.begin()->first == Lexer::KEYWORD && parser.begin()->second == "import"){
                parser.begin()++;
                nlohmann::json data {{"type", "import"}, {"namespaces", {}}};
                while(parser.begin()->first == Lexer::SYMWORD) {
                    data["namespaces"].push_back(parser.begin()->second);
                    parser.begin()++;
                }
                if(parser.begin()->second != ";")
                    return false;
                parser.begin()++;
                ((nlohmann::json&)parser).push_back(data);
                return true;
            }
            return false;
        }
    }
}
