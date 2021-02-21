//
// Created by kiper220 on 21.02.2021.
//

#ifndef REDTEXT_SYMWORD_H
#define REDTEXT_SYMWORD_H

#include <RLexer/RLexer.h>

namespace RT::Lexer::RLexer{
    /**
     * \brief Класс интерфейса лексикон.
     * \details Этот класс создаёт интерфейс для дочерних классов лексон. Используется при обработке в лексическом анализаторе.
     */
    class RedText_KeySym_Lexicon : LexiconInterface{
    public:
        /**
         * \brief Метод проверки совместимости лексикона по первому символу.
         * \return Возвращает true, если первый симвл совместим с данным лексиконом.
         */
        bool                    checkSimilarity(LexerInterface& lexerInstance) override;
        /**
         * \brief Возвращает данные лексикона..
         * \returns first - true, если данные получить удалось, иначе несоответствие, second - возвращаемые данные. Смещение применяется, если лексикон получить удалось
         */
        pair<bool, LexiconData> getLexicon(LexerInterface& lexerInstance, unsigned int &line, unsigned int &column) override;
    };
}

#endif //REDTEXT_SYMWORD_H
