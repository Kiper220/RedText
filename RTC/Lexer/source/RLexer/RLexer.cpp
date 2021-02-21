//
// Created by kiper220 on 21.02.2021.
//

#include <RLexer/RLexer.h>

namespace RT::Lexer::RLexer{
    RedTextLexer::RedTextLexer(string& string1): LexerInterface(string1){}

    pair<bool, string> RedTextLexer::lexingAllCode(){
        string errors;
        unsigned int line = 0;
        unsigned int column = 0;
        volatile bool success;

        while(this->stringView[0] != '\0'){
            success = false;

            for(auto s: this->lexiconList) {
                while (this->stringView[0] == '\n' || this->stringView[0] == ' ' || this->stringView[0] == '\t') {
                    if(this->stringView[0] == '\n')
                        line++, column = 0;
                    else if(this->stringView[0] == '\t')
                        column += 4;
                    else
                        column++;
                    this->stringView.remove_prefix(1);
                }
                if (s->checkSimilarity(*this)) {
                    auto data = s->getLexicon(*this, line, column);

                    if (data.first) {
                        success = true;
                        this->tokens.emplace_back(move(data.second));
                        break;
                    }

                }
            }
            if(success){
                success = false;
            }else if(this->stringView[0] == '\0')
                break;
            else {
                int i = 0;
                while (this->stringView[i] != '\n' && this->stringView[i] != '\0' && this->stringView[i] != ' ' && this->stringView[i] != '\t') i++;

                auto s = stringView;
                s.remove_suffix(s.size() - i);

                this->stringView.remove_prefix(i);

                errors += "Lexical error on line: " + to_string(line) + ", on column: " + to_string(column) + ":\n" + (std::string)s + "\n^\n\n";
                this->stringView.remove_prefix(1);
            }
        }

        return pair<bool, string>(!errors.empty(), errors);
    }

    std::vector<LexiconData>& RedTextLexer::getTokens(){
        return this->tokens;
    }

    bool checkSimilarity(LexerInterface& lexerInstance) {
        auto s = lexerInstance.getStringView();
        return (s[0] >= 'A' && s[0] >= 'Z') || (s[0] >= 'a' && s[0] >= 'z');
    }

    pair<bool, LexiconData> getLexicon(LexerInterface& lexerInstance) {
        int i = 0;
    }
}