#include <iostream>
#include <string>
#include <Lexer/Lexer.h>
#include <Parser/Parser.h>

using namespace std;
using namespace RT;

int main() {
    string code =

            "import io;\n"
            "import test;";

    Lexer::STDLexer lexer(string::iterator(code.begin()), string::iterator(code.end()));
    lexer.setVisitorList(
            {
                    shared_ptr<Lexer::AnalyzerVisitor>(new Lexer::IntegerLiteral),
                    shared_ptr<Lexer::AnalyzerVisitor>(new Lexer::KeyWord),
                    shared_ptr<Lexer::AnalyzerVisitor>(new Lexer::StringLiteral),
                    shared_ptr<Lexer::AnalyzerVisitor>(new Lexer::CharacterLiteral),
                    //shared_ptr<Lexer::AnalyzerVisitor>(new HexString),
                    //shared_ptr<Lexer::AnalyzerVisitor>(new WysiwygString),
                    //shared_ptr<Lexer::AnalyzerVisitor>(new WysiwygCharacter),
                    //shared_ptr<Lexer::AnalyzerVisitor>(new HexCharacter),
                    shared_ptr<Lexer::AnalyzerVisitor>(new Lexer::Operator),
                    shared_ptr<Lexer::AnalyzerVisitor>(new Lexer::Comments),
            });
    lexer.acceptAll();

    Parser::STDParser parser(lexer.getData().begin(), lexer.getData().end());

    parser.setVisitorList(
                {
                    shared_ptr<Parser::AnalyzerVisitor>(new Parser::ImportToken)
                }
            );
    parser.acceptAll();

    std::cout << (string)parser;

    return 0;
}
