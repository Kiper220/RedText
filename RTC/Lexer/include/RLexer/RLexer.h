//
// Created by kiper220 on 21.02.2021.
//

#ifndef REDTEXT_RLEXER_H
#define REDTEXT_RLEXER_H

#include <InterfaceLexer/LexerInterface.h>

namespace RT::Lexer::RLexer{


    /**
     * \brief Класс RedText лексера.
     * \details Данный класс является лексером языка программирования RedText.
     */
    class RedTextLexer : public LexerInterface{
    private:
        RedTextLexer() = default;
    public:
        /**
         * \brief Стандартный конструктор
         * \warning СТРОКА, НА КОТОРУЮ ВЫ ССЫЛАЕТЕСЬ ДОЛЖНА СУЩЕСТВОВАТЬ, ПОКА ОНА НЕ ПРОШЛА ОПЕРАЦИЮ ЛЕКСИРОВАНИЯ
         */
        RedTextLexer(string& string1);

        /**
         * \brief Вызывает цикл лексического анализа кода
         * \return \с first - вернёт true, если закончилось без ошибок, иначе false.
         * \return \c second - строка со всеми ошибками лексического анализа.
         */
        pair<bool, string>  lexingAllCode() override;

        /**
         * \brief Гетер списка токенов, после синтаксического анализа
         * \return Возвращает сыллку на вектор токенов
         */
        std::vector<LexiconData>& getTokens();

    private:
        std::vector<LexiconData> tokens;
    };
}

#endif //REDTEXT_RLEXER_H
