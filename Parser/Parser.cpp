//
// Created by kiper220 on 09.10.2020.
//

#include "Parser.h"
#include <iostream>

namespace RT{
    namespace Parser{
        ParserInterface::ParserInterface(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end): iterator_begin(iterator_begin), iterator_end(iterator_end){}
        void ParserInterface::setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector){
            this->visitorList = std::move(visitorVector);
        }

        STDParser::STDParser(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end): ParserInterface(iterator_begin, iterator_end){}

        pair<nlohmann::json, int> STDParser::acceptAllReturn() {
            pair<nlohmann::json, int> Return;
            while(this->iterator_begin->first != Lexer::EOC && this->iterator_begin != this->iterator_end){
                while(iterator_begin->first == Lexer::NEWLINE || iterator_begin->first == Lexer::EOC ) {
                    if(iterator_begin->first == Lexer::NEWLINE) Return.second++, iterator_begin++;
                    else return Return;
                }

                bool successful = false;
                for(const auto& visitor: this->visitorList){
                    pair<nlohmann::json, bool> tmp;

                    if((tmp = visitor->visitParser(*this)).second){
                        successful = true;
                        Return.first.push_back(tmp.first);
                        break;
                    }
                }
                if(!successful){
                    cerr << "Parsing error in line " << Return.second << ";\n";
                    exit(-12);
                }
            }
            return Return;
        }
        void STDParser::acceptAll(){
            this->parsingData = std::move(acceptAllReturn().first);
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

    }
}
