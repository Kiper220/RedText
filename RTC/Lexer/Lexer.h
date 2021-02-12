/**
 * Created by kiper220 on 24.09.2020.
 * \author Kiper220
 * \date 24.09.2020
 * \bug не выявленно
*/

#ifndef REDTEXT_LEXER_H
#define REDTEXT_LEXER_H

/// Using Pattern Visitor
#include <string>
#include <memory>
#include <vector>
#include <list>

using namespace std;

/**
 * Пространство имён классов относящихся к модулю лексера.
 */
namespace RT::Lexer{
    /**
     * \brief Класс, содержащий информацию лексикона.
     */
    class LexiconData{
    public:
        /**
         * \brief Тип данных типа лексикона.
         */
        enum LexiconType{
            UNKNOWN,
            STRING_LITERAL,
            OPERATOR,
            KEYWORD,
            SYMWORD,
            /*...*/
        };
    public:
        /**
         * \brief Стандартный конструктор.
         */
        LexiconData ();
        /**
         * \brief Стандартный конструктор с параметрами.
         */
        LexiconData (std::string lexiconData, LexiconType lexiconType, int Line = 0, int Column = 0);
        /**
         * \brief Конструктор копирования.
         */
        LexiconData (const LexiconData& LexiconData);
        /**
         * \brief Конструктор перемещения данных.
         */
        LexiconData (LexiconData&& LexiconData) noexcept;

    public:
        /**
         * \brief Гетер строковых данных лексикона.
         * \return Ссылка на строку.
         */
        string&         GetLexiconData      ();
        /**
         * \brief Гетер типа лексикона.
         * \return Ссылка на тип лексикона.
         */
        LexiconType&    GetLexiconType      ();
        /**
         * \brief Гетер строки в коде лексикона.
         * \return Ссылка на числовое значение строки в коде.
         */
        int&            GetLexiconLine      ();
        /**
         * \brief Гетер колонки в коде лексикона.
         * \return Ссылка на числовое значение колонки в коде.
         */
        int&            GetLexiconColumn    ();
        /**
         * \brief Перегрузка оператора возрата строки.
         * \return Отладочная информация для консоли или вывода в файл для сохранения.
         */
        operator        string();
        /**
         * \brief Установка данных из отладочной информации.
         * \return Положительный результат, если операция выполнилась без ошибок.
         * \warning Функция загружает только один лексикон.
         * \todo написать реализацию данного метода
         */
        bool            setFromString(const string &string1) = delete;
    private:
        /**
         * \brief Строка данных лексикона.
         */
        string          lexiconData;
        /**
         * \brief Тип лексикона.
         */
        LexiconType     lexiconType;
        /**
         * \brief Номер строки в коде.
         */
        int             Line;
        /**
         * \brief Номер колонки в коде.
         */
        int             Column;
    };
    class LexerInterface;

    /**
     * \brief Класс интерфейса лексикон.
     * \details Этот класс создаёт интерфейс для дочерних классов лексон. Используется при обработке в лексическом анализаторе.
     */
    class LexiconInterface{
    public:
        /**
         * \brief Метод проверки совместимости лексикона по первому символу.
         * \return Возвращает true, если первый симвл совместим с данным лексиконом.
         */
        virtual bool                    CheckSimilarity(LexerInterface& lexerInstance) = 0;
        /**
         * \brief Возвращает данные лексикона..
         * \returns first - true, если данные получить удалось, иначе несоответствие, second - возвращаемые данные. Смещение применяется, если лексикон получить удалось
         */
        virtual pair<bool, LexiconData> GetLexicon(LexerInterface& lexerInstance) = 0;
    };

    /**
     * \brief Класс интерфейса лексера.
     * \details Данный класс создан, как класс интерфейс для дочерних классов являющихся лексером
     */
    class LexerInterface{
    private:
        LexerInterface() = default;
    public:
        /**
         * \brief Стандартный конструктор
         * \warning СТРОКА, НА КОТОРУЮ ВЫ ССЫЛАЕТЕСЬ ДОЛЖНА СУЩЕСТВОВАТЬ, ПОКА ОНА НЕ ПРОШЛА ОПЕРАЦИЮ ЛЕКСИРОВАНИЯ
         */
        LexerInterface(string& string1);

        /**
         * \brief Устанавливает все объекты классов лексикон
         * \arg \c lexiconInstance - вектор объектов лексикон
         * \arg \c deleteOnEnd - true, если вы хотите, чтобы для каждого объекта вектора вы хотите вызвать оператор delete, иначе false(default).
         * \warning см. аргумент \c deleteOnEnd. Если вылетит segmentation fault, то пинайте на себя
         */
        bool                        setAllLexicons(vector<LexiconInterface*> lexiconList, bool deleteOnEnd = false);

        /**
         * \brief Гетер класса просмотра строки
         * \return Ссылка на класс просмотра строки внутри лексера
         */
        std::string_view&           GetStringView();

        /**
         * \brief Вызывает цикл лексического анализа кода
         * \return \с first - вернёт true, если закончилось без ошибок, иначе false.
         * \return \c second - строка со всеми ошибками лексического анализа.
         */
        virtual pair<bool, string>  LexingAllCode() = 0;

        /**
         * \brief Стандартный деструктор. Вызывает оператор delete для каждого лексикона, если deleteOnEnd равен true
         */
         ~LexerInterface();

    protected:

        /**
         *  \brief Класс просмотра строки.
         */
        std::string_view stringView;
        /**
         *  \brief Список лексикон
         */
        std::vector<LexiconInterface*> lexiconList;
        /**
         *  \brief Переменная условия удаления данных
         */
        bool deleteOnEnd = false;
    };

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
        pair<bool, string>  LexingAllCode() override;

        /**
         * \brief Гетер списка токенов, после синтаксического анализа
         * \return Возвращает сыллку на вектор токенов
         */
         std::vector<LexiconData>& GetTokens();

    private:
        std::vector<LexiconData> tokens;
    };


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
        bool                            CheckSimilarity(LexerInterface& lexerInstance) override;
        /**
         * \brief Возвращает данные лексикона..
         * \returns first - true, если данные получить удалось, иначе несоответствие, second - возвращаемые данные. Смещение применяется, если лексикон получить удалось
         */
        virtual pair<bool, LexiconData> GetLexicon(LexerInterface& lexerInstance) override;
    };
}


#endif //REDTEXT_LEXER_H
