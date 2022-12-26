/*!
\file
\brief Заголовочный файл с объявлениям класса калькулятора (главного окна программы)
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QVector>
#include <vector>
#include <stack>
#include "moment.h"
#include "graphic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор нового объекта калькулятора
     * 
     * @param parent – Указатель на родительский виджет
     */
    Calculator(QWidget *parent = nullptr);

    /**
     * @brief Декструктор объекта
     * 
     */
    ~Calculator();

private slots:

    /**
     * @brief Кнопка AC
     * 
     */
    void on_acButton_clicked();

    /**
     * @brief Кнопка <-
     * 
     */
    void on_backSpaceButton_clicked();

    /**
     * @brief Кнопка .
     * 
     */
    void on_dotButton_clicked();

    /**
     * @brief Кнопка 0
     * 
     */
    void on_zeroButton_clicked();

    /**
     * @brief Кнопка 1
     * 
     */
    void on_oneButton_clicked();

    /**
     * @brief Кнопка 2
     * 
     */
    void on_twoButton_clicked();

    /**
     * @brief Кнопка 3
     * 
     */
    void on_threeButton_clicked();

    /**
     * @brief Кнопка 4
     * 
     */
    void on_fourButton_clicked();

    /**
     * @brief Кнопка 5
     * 
     */
    void on_fiveButton_clicked();

    /**
     * @brief Кнопка 6
     * 
     */
    void on_sixButton_clicked();

    /**
     * @brief Кнопка 7
     * 
     */
    void on_sevenButton_clicked();

    /**
     * @brief Кнопка 8
     * 
     */
    void on_eightButton_clicked();

    /**
     * @brief Кнопка 9
     * 
     */
    void on_nineButton_clicked();

    /**
     * @brief Кнопка +
     * 
     */
    void on_plusButton_clicked();

    /**
     * @brief Кнопка -
     * 
     */
    void on_minusButton_clicked();

    /**
     * @brief Кнопка *
     * 
     */
    void on_mulButton_clicked();

    /**
     * @brief Кнопка /
     * 
     */
    void on_divButton_clicked();

    /**
     * @brief Кнопка ^
     * 
     */
    void on_powButton_clicked();

    /**
     * @brief Кнопка %
     * 
     */
    void on_modButton_clicked();

    /**
     * @brief Кнопка )
     * 
     */
    void on_closeBracketButton_clicked();

    /**
     * @brief Кнопка (
     * 
     */
    void on_openBracketButton_clicked();

    /**
     * @brief Кнопка x
     * 
     */
    void on_xButton_clicked();

    /**
     * @brief Кнопка sqrt
     * 
     */
    void on_sqrtButton_clicked();

    /**
     * @brief Кнопка sin
     * 
     */
    void on_sinButton_clicked();

    /**
     * @brief Кнопка cos
     * 
     */
    void on_cosButton_clicked();

    /**
     * @brief Кнопка tan
     * 
     */
    void on_tanButton_clicked();

    /**
     * @brief Кнопка asin
     * 
     */
    void on_asinButton_clicked();

    /**
     * @brief Кнопка acos
     * 
     */
    void on_acosButton_clicked();

    /**
     * @brief Кнопка atan
     * 
     */
    void on_atanButton_clicked();

    /**
     * @brief Кнопка ln
     * 
     */
    void on_lnButton_clicked();

    /**
     * @brief Кнопка log
     * 
     */
    void on_logButton_clicked();

    /**
     * @brief Кнопка =
     * 
     */
    void on_equalsButton_clicked();

private:

    /**
     * @brief Объект графического интерфейса
     * 
     */
    Ui::Calculator *ui;

    /**
     * @brief Строка с выражением
     * 
     */
    QString str;

    /**
     * @brief Вектор со снимками состояния строки для валидации ввода в любой момент времени
     * 
     */
    std::vector<Moment> moments;

    /**
     * @brief Является ли функция функцией или просто обычным выражением
     * 
     * @return true – функция
     * @return false – выражение
     */
    bool is_func();

    /**
     * @brief Запись в файл полученной строки для дальшейшей обработки парсером
     * 
     */
    void toFile();

    /**
     * @brief Добавление в слепок состояний инфорацию о открытой скобке
     * 
     */
    void addOpenBracket();

    /**
     * @brief Добавление в слепок состояний инфорацию о закрытой скобке
     * 
     */
    void addCloseBracket();

    /**
     * @brief Добавление в слепок состояний инфорацию о цифре
     * 
     */
    void addDigit(int caseValueNumber);

    /**
     * @brief Добавление в слепок состояний инфорацию о точке
     * 
     */
    void addDot();

    /**
     * @brief Добавление в слепок состояний инфорацию об x
     * 
     */
    void addX();

    /**
     * @brief Добавление в слепок состояний инфорацию об унарном операторе
     * 
     */
    void addUnary(int sizeOfUnary);

    /**
     * @brief Добавление в слепок состояний инфорацию об бинарном операторе
     * 
     */
    void addBinary();

    /**
     * @brief Единый обработчик почти для любой кнопки
     * 
     * @param handeledString – Строка в кнопке
     */
    void almostAnyButton(const std::string& handeledString);

    /**
     * @brief Ветка для нулевого статуса состояния снимка
     * 
     * @param handeledString – Пришедшая строка
     * @param status – Если на выходе true, то можно печатать
     * @param additional – Добавочное значение (нужно для унарных функций)
     */
    void branch0(const std::string& handeledString, bool& status, std::string& additional);

    /**
     * @brief Ветка для первого статуса состояния снимка
     * 
     * @param handeledString – Пришедшая строка
     * @param status – Если на выходе true, то можно печатать
     * @param lastCharacter – Последний символ строки
     */


    void branch1(const std::string& handeledString, bool& status, char lastCharacter);

    /**
     * @brief Ветка для второго статуса состояния снимка
     * 
     * @param handeledString – Пришедшая строка
     * @param status – Если на выходе true, то можно печатать
     * @param lastCharacter – последний символ строки
     */
    void branch2(const std::string& handeledString, bool& status, char lastCharacter);

    /**
     * @brief Ветка для третьего статуса состояния снимка
     * 
     * @param handeledString – Пришедшая строка
     * @param status – Если на выходе true, то можно печатать
     * @param lastCharacter – Последний символ строки
     */
    void branch3(const std::string& handeledString, bool& status, char lastCharacter);

    /**
     * @brief Ветка для четвертого статуса состояния снимка
     * 
     * @param handeledString – Пришедшая строка
     * @param status – Если на выходе true, то можно печатать
     * @param lastCharacter – Последний символ строки
     */
    void branch4(const std::string& handeledString, bool& status, char lastCharacter);

    /**
     * @brief Ветка для пятого статуса состояния снимка
     * 
     * @param handeledString – Пришедшая строка
     * @param status – Если на выходе true, то можно печатать
     * @param lastCharacter – Последний символ строки
     */
    void branch5(const std::string& handeledString, bool& status, char lastCharacter, std::string& additional);

    /**
     * @brief Мастер ветка для ветвления по состояниям снимка
     * 
     * @param toCheck – Сотояние снимка
     * @param status – Если на выходе true, то можно печатать
     * @param handeledString – Пришедшая строка
     * @param lastCharacter – Последний символ строки
     * @param additional – Добавочное значение (нужно для унарных функций)
     */
    void branching(int toCheck, bool &status, const std::string& handeledString, char lastCharacter, std::string& additional);

    /**
     * @brief Функция заглушка для восстановления валидности снимков состояний после подсчета обычного выражения
     * 
     * @param resultOfCalculation – Результат вычисления, по которому будут валидироваться снимки состояний
     */
    void fillMomentsAfterCalcualte(const std::string& resultOfCalculation);

};

/**
 * @brief Парсинг постфиксной строки после ее компиляции в вектор строк
 * 
 * @return std::vector<std::string>
 */
std::vector<std::string> parseFromFile();

/**
 * @brief Подсчет значений
 * 
 * @param hasX – Имеется ли x в выражении
 * @return Значение, если x отсутствует, в обратном случае 0 + вызов графика
 */
double calculate(bool hasX);

/**
 * @brief Обертка над стеком для удобства
 * 
 * @param number – Стек
 * @return Значение стека сверху + удаление его из стека
 */
double stackWrap(std::stack<double>& number);

/**
 * @brief Калькуляция выражения без x
 * 
 * @param parts – Части строк
 * @return double
 */
double withoutX(const std::vector<std::string>& parts);

/**
 * @brief Проверка на то, что символ строки является бинарным оператором
 * 
 * @param op – Символ строки
 * @return true – Бинарный оператор
 * @return false – Не бинарный оператор
 */
bool isBinary(const char op);

/**
 * @brief Подсчет значения для бинарного оператора
 * 
 * @param rhs – Правое значение выражения
 * @param lhs – Левое значение выражения
 * @param op – Оператор
 * @return double 
 */
double binary(const double rhs, const double lhs, const char op);

/**
 * @brief Подсчет значения для унарного оператора
 * 
 * @param number – Значение для подсчета
 * @param op – Оператор
 * @return double
 */
double unary(const double number, const char op);

#endif // CALCULATOR_H
