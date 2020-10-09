//
// Created by kiper220 on 24.09.2020.
//

#ifndef REDTEXT_LEXER_H
#define REDTEXT_LEXER_H

/// Using Pattern Visitor
#include <string>
#include <memory>
#include <vector>
#include <list>

using namespace std;

namespace RT{
    namespace Lexer{

        class AnalyzerVisitor;
        enum LexiconType {
            INTEGER_LITERAL,
            KEYWORD,
            SYMWORD,
            STRING_LITERAL,
            CHARACTER_LITERAL,
            HEX_STRING,
            WYSIWYG_STRING,
            WYSIWYG_CHARACTER,
            HEX_CHARACTER,
            OPERATOR,
            NEWLINE,
            EOC
        };

        class LexerInstance{
        public:
            LexerInstance(string::iterator iterator_begin, string::iterator iterator_end);
            void setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector);

            virtual void acceptAll() = 0;

            virtual explicit operator string() = 0;
            virtual explicit operator list<pair<LexiconType, string>>&() = 0;

            virtual string::iterator& begin() = 0;
            virtual string::iterator& end() = 0;

            virtual list<pair<LexiconType, string>>& getData() = 0;


        protected:
            virtual void accept(AnalyzerVisitor& visitor) = 0;

            list<pair<LexiconType, string>> lexicalData;

            string::iterator iterator_begin;
            string::iterator iterator_end;

            vector<shared_ptr<AnalyzerVisitor>> visitorList;
        };
        class STDLexer : public LexerInstance{
        public:
            STDLexer(string::iterator iterator_begin, string::iterator iterator_end);

            void addLexerOutput(LexiconType lexiconType, string lexicon);

            void acceptAll() override;

            string::iterator& begin() override;
            string::iterator& end() override;

            list<pair<LexiconType, string>>& getData() override;

            explicit operator string() override;
            explicit operator list<pair<LexiconType, string>>&() override;

        protected:
            void accept(AnalyzerVisitor& visitor) override;
        };

        class AnalyzerVisitor{
        public:
            virtual bool visitLexer(STDLexer& lexer) = 0;
        };
        class IntegerLiteral: public AnalyzerVisitor{
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class KeyWord: public AnalyzerVisitor{
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class StringLiteral: public AnalyzerVisitor{
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class CharacterLiteral: public AnalyzerVisitor{
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class WysiwygString: public AnalyzerVisitor{    // TODO: Make WysiwygString lexicon
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class WysiwygCharacter: public AnalyzerVisitor{ // TODO: Make WysiwygCharacter lexicon
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class HexString: public AnalyzerVisitor{        // TODO: Make HexString lexicon
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class HexCharacter: public AnalyzerVisitor{     // TODO: Make HexCharacter lexicon
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class Operator: public AnalyzerVisitor{
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
        class Comments: public AnalyzerVisitor{
        public:
            bool visitLexer(STDLexer& lexer) override;
        };
    }
}


#endif //REDTEXT_LEXER_H
