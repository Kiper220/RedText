//
// Created by kiper220 on 21.02.2021.
//

#include <RLexer/Lexicons/Symword.h>

namespace RT::Lexer::RLexer{

    bool RedText_KeySym_Lexicon::checkSimilarity(LexerInterface& lexerInstance) {
        return
            lexerInstance.getStringView()[0] > 'A' && lexerInstance.getStringView()[0] < 'Z' ||
            lexerInstance.getStringView()[0] > 'a' && lexerInstance.getStringView()[0] < 'z' ||
            lexerInstance.getStringView()[0] == '_';
    }
    static inline bool checkSymwordChar(char sym){
        return (sym >= 'A' && sym <= 'Z' ||
                sym >= 'a' && sym <= 'z' ||
                sym >= '0' && sym <= '9' ||
                sym == '_');
    }

    pair<bool, LexiconData> RedText_KeySym_Lexicon::getLexicon(LexerInterface& lexerInstance, unsigned int &line, unsigned int &column) {
        if(this->checkSimilarity(lexerInstance)){
            auto string = lexerInstance.getStringView();
            unsigned int i = 0;

            for(; checkSymwordChar(string[i]); i++);

            lexerInstance.getStringView().remove_prefix(i);
            string.remove_suffix(string.size() - i);
            column += i;
            return pair(true, LexiconData((std::string)string, LexiconData::SYMWORD, line, column - i));
        }
        return pair(false, LexiconData("", LexiconData::UNKNOWN, 0,0));
    }
}