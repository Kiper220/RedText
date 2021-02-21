#include <iostream>
#include <Lexer.h>

using namespace std;
using namespace RT::Lexer;

int main() {
    string code = "test string to lex\n"
                  "\ttest\n"
                  "123 rwar 3543";

    cout << "Code:\n" << code << "\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";

    RLexer::RedTextLexer lexer(code);
    lexer.setAllLexicons({(LexiconInterface*)new RLexer::RedText_KeySym_Lexicon}, true);

    auto error = lexer.lexingAllCode();
    auto data = lexer.getTokens();

    cerr << "Errors:\n\n" << error.second << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
    cout << "Tokens:\n";

    for(auto &s: data){
        cout << (string)s << '\n';
    }
    cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";


    return 0;
}
