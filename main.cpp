#include <iostream>
#include <string>
#include <Lexer/Lexer.h>

using namespace std;
using namespace RT::Lexer;

int main() {
    string code =

            "import io;\n"
            "\n"
            "int main(){\n"
            "   int i = 0;\n"
            "   scan >> i;\n"
            "   if(i > 23){\n"
            "      print << \"true\";\n"
            "   }\n"
            "   else print << \"false\";\n"
            "   return 0;\n"
            "}\n";

    Lexer lexer(string::iterator(code.begin()), string::iterator(code.end()));
    lexer.setVisitorList(
            {
                    shared_ptr<AnalyzerVisitor>(new IntegerLiteral),
                    shared_ptr<AnalyzerVisitor>(new KeyWord),
                    shared_ptr<AnalyzerVisitor>(new StringLiteral),
                    shared_ptr<AnalyzerVisitor>(new CharacterLiteral),
                    //shared_ptr<AnalyzerVisitor>(new HexString),
                    //shared_ptr<AnalyzerVisitor>(new WysiwygString),
                    //shared_ptr<AnalyzerVisitor>(new WysiwygCharacter),
                    //shared_ptr<AnalyzerVisitor>(new HexCharacter),
                    shared_ptr<AnalyzerVisitor>(new Operator),
                    shared_ptr<AnalyzerVisitor>(new Comments),
            });
    lexer.acceptAll();
    std::cout << "Code on lex:\n-----------------\n" << code << "-----------------\nLex code: \n-----------------\n" << (string)lexer << "\n-----------------";

    return 0;
}
