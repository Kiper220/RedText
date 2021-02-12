#include <Lexer.h>

namespace RT::Lexer{
    static string LexiconTypeToString(LexiconData::LexiconType data){
        switch(data){
            case LexiconData::UNKNOWN:
                return "UNKNOWN";

            case LexiconData::STRING_LITERAL:
                return "STRING_LITERAL";

            case LexiconData::OPERATOR:
                return "OPERATOR";

            case LexiconData::KEYWORD:
                return "KEYWORD";

            case LexiconData::SYMWORD:
                return "SYMWORD";

        }
    }

    LexiconData::LexiconData(): lexiconType(UNKNOWN), Line(0), Column(0){}

    LexiconData::LexiconData (std::string lexiconData, LexiconData::LexiconType lexiconType, int Line, int Column):
    lexiconData(lexiconData), lexiconType(lexiconType), Line(Line), Column(Column){}

    LexiconData::LexiconData (const LexiconData& LexiconData):
    lexiconData(LexiconData.lexiconData), lexiconType(LexiconData.lexiconType), Line(LexiconData.Line), Column(LexiconData.Column){}

    LexiconData::LexiconData (LexiconData&& LexiconData) noexcept:
    lexiconData(std::move(LexiconData.lexiconData)), lexiconType(LexiconData.lexiconType), Line(LexiconData.Line), Column(LexiconData.Column){
        LexiconData.Column = 0;
        LexiconData.Line = 0;
        LexiconData.lexiconType = UNKNOWN;
    }


    string& LexiconData::GetLexiconData(){
        return this->lexiconData;
    }

    LexiconData::LexiconType& LexiconData::GetLexiconType(){
        return this->lexiconType;
    }

    int& LexiconData::GetLexiconLine(){
        return this->Line;
    }

    int& LexiconData::GetLexiconColumn(){
        return this->Column;
    }

    LexiconData::operator string(){
        return
        "[" + LexiconTypeToString(this->lexiconType) + ", \"" + this->lexiconData +
        "\", line: " + std::to_string(this->Line) + ", column: " + std::to_string(this->Column) + "]";
    }



    LexerInterface::LexerInterface(string& string1): stringView(string1){}

    bool LexerInterface::setAllLexicons(vector<LexiconInterface*> lexiconList, bool deleteOnEnd){
        this->lexiconList = lexiconList;
        this->deleteOnEnd = deleteOnEnd;
    }

    std::string_view& LexerInterface::GetStringView(){
        return this->stringView;
    }

    LexerInterface::~LexerInterface(){
        if(this->deleteOnEnd)
            for(auto *s: this->lexiconList)
                delete s;
    }

    RedTextLexer::RedTextLexer(string& string1): LexerInterface(string1){}

    pair<bool, string> RedTextLexer::LexingAllCode(){
        string errors;
        int line = 0;
        int column = 0;
        volatile bool success;

        while(this->stringView[0] != '\0'){
            success = false;

            for(auto s: this->lexiconList)
                if(s->CheckSimilarity(*this)){
                    auto data = s->GetLexicon(*this);

                    if(data.first) {
                        success = true;
                        this->tokens.emplace_back(move(data.second));
                        break;
                    }

                }
            if(success){
                success = false;
            }else {
                errors += "Lexical error on line: " + to_string(line) + ", on column: " + to_string(column) + "\n";
                while (this->stringView[0] != '\n' && this->stringView[0] != '\0')
                    this->stringView.remove_prefix(1);
            }
        }

        return pair<bool, string>(!errors.empty(), errors);
    }

    std::vector<LexiconData>& RedTextLexer::GetTokens(){
        return this->tokens;
    }

    bool CheckSimilarity(LexerInterface& lexerInstance) {
        auto s = lexerInstance.GetStringView();
        return (s[0] >= 'A' && s[0] >= 'Z') || (s[0] >= 'a' && s[0] >= 'z');
    }

    pair<bool, LexiconData> GetLexicon(LexerInterface& lexerInstance) {
        int i = 0;
    }

    bool RedText_KeySym_Lexicon::CheckSimilarity(LexerInterface& lexerInstance) {

    }

    pair<bool, LexiconData> RedText_KeySym_Lexicon::GetLexicon(LexerInterface& lexerInstance) {

    }
}