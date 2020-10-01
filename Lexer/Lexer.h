//
// Created by kiper220 on 24.09.2020.
//

#ifndef REDTEXT_LEXER_H
#define REDTEXT_LEXER_H

/// Using Pattern Visitor
#include <string>
#include <memory>
#include <vector>

using namespace std;

namespace RT{
    namespace Lexer{

        class AnalyzerVisitor;
        enum LexiconType {

        };

        class LexElement{
        public:
            LexElement(string::iterator iterator_begin, string::iterator iterator_end);
            void setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector);

            virtual void accept(AnalyzerVisitor& visitor) = 0;
            virtual void acceptAll() = 0;

            virtual explicit operator string() = 0;

            virtual string::iterator& begin() = 0;
            virtual string::iterator& end() = 0;


        protected:
            vector<pair<LexiconType, string>> lexicalData;
            string::iterator iterator_begin;
            string::iterator iterator_end;
            vector<shared_ptr<AnalyzerVisitor>> visitorList;
        };
        class Lexer : public LexElement{
        public:
            Lexer(string::iterator iterator_begin, string::iterator iterator_end);
            void accept(AnalyzerVisitor& visitor) override;
            void acceptAll() override;
            void addLexerOutput(string data);

            explicit operator string() override;

            virtual string::iterator& begin() override;
            virtual string::iterator& end() override;

        private:
            string lexerOutput;
        };

        class AnalyzerVisitor{
        public:
            virtual bool visitLexer(Lexer& lexer) = 0;
        };
        class IntegerLiteral: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class KeyWord: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class StringLiteral: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class CharacterLiteral: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class WysiwygString: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class WysiwygCharacter: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class HexString: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class HexCharacter: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class Operator: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
        class Comments: public AnalyzerVisitor{
        public:
            bool visitLexer(Lexer& lexer) override;
        };
    }
}


#endif //REDTEXT_LEXER_H
