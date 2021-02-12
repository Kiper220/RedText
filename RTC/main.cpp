#include <iostream>
#include <string>
#include <Lexer/Lexer.h>
#include <Parser/Parser.h>

using namespace std;
using namespace RT;

int main() {
    string code = "test string to lex";

    cout << code + '\n';

    Lexer::RedTextLexer lexer(code);
    lexer.LexingAllCode();


    return 0;
}
