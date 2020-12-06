#include <iostream>
#include <string>
#include <Lexer/Lexer.h>
#include <Parser/Parser.h>

using namespace std;
using namespace RT;

int main() {
    std::cout << (string)Lexer::LexiconData("test", RT::Lexer::LexiconData::STRING_LITERAL, 15, 23);

    return 0;
}
