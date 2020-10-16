//
// Created by kiper220 on 09.10.2020.
//

#ifndef REDTEXT_PARSER_H
#define REDTEXT_PARSER_H
#include <nlohmann/json.hpp>
#include <Lexer.h>

namespace RT{
    namespace Parser{
        class AnalyzerVisitor;

        class ParserInterface{
        public:
            ParserInterface(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end);
            void setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector);

            virtual pair<nlohmann::json, int> acceptAllReturn() = 0;
            virtual void acceptAll() = 0;

            virtual list<pair<Lexer::LexiconType, string>>::iterator& begin() = 0;
            virtual list<pair<Lexer::LexiconType, string>>::iterator& end() = 0;

            virtual explicit operator string() = 0;
            virtual explicit operator nlohmann::json&() = 0;

        protected:
            virtual void accept(AnalyzerVisitor& visitor) = 0;

            nlohmann::json parsingData;

            list<pair<Lexer::LexiconType, string>>::iterator iterator_begin;
            list<pair<Lexer::LexiconType, string>>::iterator iterator_end;

            vector<shared_ptr<AnalyzerVisitor>> visitorList;
        };

        class STDParser : public ParserInterface{
        public:
            STDParser(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end);

            pair<nlohmann::json, int> acceptAllReturn() override;
            void acceptAll() override;

            list<pair<Lexer::LexiconType, string>>::iterator& begin() override;
            list<pair<Lexer::LexiconType, string>>::iterator& end() override;

            explicit operator string() override;
            explicit operator nlohmann::json&() override;

        protected:

            void accept(AnalyzerVisitor& visitor) override;
        };

        class AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) = 0;
        };

        class ImportToken : public AnalyzerVisitor{
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };

    }
}

#endif //REDTEXT_PARSER_H
