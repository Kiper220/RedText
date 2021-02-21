#include <InterfaceLexer/LexerInterface.h>

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

    std::string_view& LexerInterface::getStringView(){
        return this->stringView;
    }

    LexerInterface::~LexerInterface(){
        if(this->deleteOnEnd)
            for(auto *s: this->lexiconList)
                delete s;
    }
}