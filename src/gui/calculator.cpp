#include <QtCore>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);
    str = "";
    ui -> textEdit -> setText(str);
    moments.push_back(Moment(0, 0, 0));
}

Calculator::~Calculator() {
    delete ui;
}

bool Calculator::is_func() {
    for (auto& i : str) {
        if (i == 'x') {
            return true;
        }
    }
    return false;
}

void Calculator::toFile() {
    auto file = fopen(".expression", "w");
    fprintf(file, "%s", str.toStdString().c_str());
    fclose(file);
    system("./graph");
}

void Calculator::addOpenBracket() {
    moments.push_back(Moment(moments.back().bracketCounter + 1, 0, 1));
}

void Calculator::addCloseBracket() {
    moments.push_back(Moment(moments.back().bracketCounter - 1, 4, 1));
}

void Calculator::addDigit(int caseValueNumber) {
    moments.push_back(Moment(moments.back().bracketCounter, caseValueNumber, 1));
}

void Calculator::addDot() {
    moments.push_back(Moment(moments.back().bracketCounter, 2, 1));
}

void Calculator::addX() {
    moments.push_back(Moment(moments.back().bracketCounter, 3, 1));
}

void Calculator::addUnary(int sizeOfUnary) {
    moments.push_back(Moment(moments.back().bracketCounter + 1, 0, sizeOfUnary + 1));
}

void Calculator::addBinary() {
    moments.push_back(Moment(moments.back().bracketCounter, 5, 1));
}

void Calculator::branch0(const std::string& handeledString, bool& status, std::string& additional) {
    int caseValueForNumber = 1;
    if (handeledString == "(") {
        addOpenBracket();
    } else if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(caseValueForNumber);
    } else if (handeledString == "x") {
        addX();
    } else {
        additional = "(";
        if (handeledString == "-") {
            addUnary(1);
        } else if (handeledString == "ln") {
            addUnary(2);
        } else if (handeledString == "sin" || handeledString == "cos" || handeledString == "tan" || handeledString == "log") {
            addUnary(3);
        } else if (handeledString == "sqrt" || handeledString == "asin" || handeledString == "acos" || handeledString == "atan") {
            addUnary(4);
        } else {
            status = false;
        }
    }
}

void Calculator::branch1(const std::string& handeledString, bool& status, char lastCharacter) {
    int caseValueForNumber = 1;
    if (handeledString == ".") {
        addDot();
    } else if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(caseValueForNumber);
    } else if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary();
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket();
    } else {
        status = false;
    }
}

void Calculator::branch2(const std::string& handeledString, bool& status, char lastCharacter) {
    int caseValueForNumber = 2;
    if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(caseValueForNumber);
    } else if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary();
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket();
    } else {
        status = false;
    }
}

void Calculator::branch3(const std::string& handeledString, bool& status, char lastCharacter) {
    if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary();
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket();
    } else {
        status = false;
    }
}

void Calculator::branch4(const std::string& handeledString, bool& status, char lastCharacter) {
    if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary();
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket();
    } else {
        status = false;
    }
}

void Calculator::branch5(const std::string& handeledString, bool& status, char lastCharacter, std::string& additional) {
    int caseValueForNumber = 1;
    if (handeledString == "(") {
        addOpenBracket();
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket();
    } else if (handeledString == "x") {
        addX();
    } else if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(caseValueForNumber);
    } else {
        additional = "(";
        if (handeledString == "ln") {
            addUnary(2);
        } else if (handeledString == "sin" || handeledString == "cos" || handeledString == "tan" || handeledString == "log") {
            addUnary(3);
        } else if (handeledString == "sqrt" || handeledString == "asin" || handeledString == "acos" || handeledString == "atan") {
            addUnary(4);
        } else {
            status = false;
        }
    }
}


void Calculator::branching(int toCheck, bool &status, const std::string& handeledString, char lastCharacter, std::string& additional) {
    if (toCheck == 0) {
        branch0(handeledString, status, additional);
    } else if (toCheck == 1) {
        branch1(handeledString, status, lastCharacter);
    } else if (toCheck == 2) {
        branch2(handeledString, status, lastCharacter);
    } else if (toCheck == 3) {
        branch3(handeledString, status, lastCharacter);
    } else if (toCheck == 4) {
        branch4(handeledString, status, lastCharacter);
    } else if (toCheck == 5) {
        branch5(handeledString, status, lastCharacter, additional);
    }
}

void Calculator::fillMomentsAfterCalcualte(const std::string& resultOfCalculation) {
    bool statusPlug = false;
    std::string stringPlug = "";
    for (auto i : resultOfCalculation) {
        std::string handeledString;
        handeledString.push_back(i);
        branching(moments.back().status, statusPlug, handeledString, 0, stringPlug);
    }
}

void Calculator::almostAnyButton(const std::string& handeledString) {
    std::string additional = "";
    bool status = true;
    branching(moments.back().status, status, handeledString, str.toStdString().back(), additional);
    if (status) {
        str += QString(handeledString.c_str());
        str += QString(additional.c_str());
    }
    ui -> textEdit -> setText(str);
    ui -> textEdit -> setAlignment(Qt::AlignRight);
}

void Calculator::on_acButton_clicked() {
    moments.clear();
    moments.push_back(Moment(0, 0 ,0));
    str = "";
    ui -> textEdit -> setText(str);
}


void Calculator::on_backSpaceButton_clicked() {
    if (moments.back().characters != 0) {
        str.resize(str.length() - moments.back().characters);
        moments.pop_back();
        ui -> textEdit -> setText(str);
        ui -> textEdit -> setAlignment(Qt::AlignRight);
    }
}






void Calculator::on_dotButton_clicked() {
    almostAnyButton(".");
}


void Calculator::on_zeroButton_clicked()
{
    almostAnyButton("0");
}


void Calculator::on_oneButton_clicked()
{
    almostAnyButton("1");
}


void Calculator::on_twoButton_clicked()
{
    almostAnyButton("2");
}


void Calculator::on_threeButton_clicked()
{
    almostAnyButton("3");
}


void Calculator::on_fourButton_clicked()
{
    almostAnyButton("4");
}


void Calculator::on_fiveButton_clicked()
{
    almostAnyButton("5");
}


void Calculator::on_sixButton_clicked()
{
    almostAnyButton("6");
}


void Calculator::on_sevenButton_clicked()
{
    almostAnyButton("7");
}


void Calculator::on_eightButton_clicked()
{
    almostAnyButton("8");
}


void Calculator::on_nineButton_clicked()
{
    almostAnyButton("9");
}


void Calculator::on_plusButton_clicked()
{
    almostAnyButton("+");
}


void Calculator::on_minusButton_clicked()
{
    almostAnyButton("-");
}


void Calculator::on_mulButton_clicked()
{
    almostAnyButton("*");
}


void Calculator::on_divButton_clicked()
{
    almostAnyButton("/");
}


void Calculator::on_powButton_clicked()
{
    almostAnyButton("^");
}


void Calculator::on_modButton_clicked()
{
    almostAnyButton("%");
}


void Calculator::on_closeBracketButton_clicked()
{
    almostAnyButton(")");
}

void Calculator::on_openBracketButton_clicked()
{
    almostAnyButton("(");
}


void Calculator::on_xButton_clicked()
{
    almostAnyButton("x");
}


void Calculator::on_sqrtButton_clicked()
{
    almostAnyButton("sqrt");
}


void Calculator::on_sinButton_clicked()
{
    almostAnyButton("sin");
}


void Calculator::on_cosButton_clicked()
{
    almostAnyButton("cos");
}


void Calculator::on_tanButton_clicked()
{
    almostAnyButton("tan");
}


void Calculator::on_asinButton_clicked()
{
    almostAnyButton("asin");
}


void Calculator::on_acosButton_clicked()
{
    almostAnyButton("acos");
}


void Calculator::on_atanButton_clicked()
{
    almostAnyButton("atan");
}


void Calculator::on_lnButton_clicked()
{
    almostAnyButton("ln");
}


void Calculator::on_logButton_clicked()
{
    almostAnyButton("log");
}


void Calculator::on_equalsButton_clicked()
{
    if (str.size() != 0) {
        toFile();
        bool xStatus = is_func();
        auto a = calculate(xStatus, g);
        moments.clear();
        moments.push_back(Moment(0, 0, 0));
        if (!xStatus) {
            str = QString(std::to_string(a).c_str());
            ui -> textEdit -> setText(str);
            ui -> textEdit -> setAlignment(Qt::AlignRight);
            if (str != "nan" && str != "inf") {
                fillMomentsAfterCalcualte(str.toStdString());
            } else {
                str = "";
            }
        } else {
            str = "";
        }
    }
}

std::vector<std::string> parseFromFile() {
    std::vector<std::string> result;
    std::string word;
    std::ifstream expression("output.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(expression.rdbuf());
    while (std::cin>>word) {
        result.push_back(word);
    }
    std::cin.rdbuf(cinbuf);
    return result;
}

double calculate(bool hasX, QVector<graphic*>& g) {
    std::vector<std::string> parts = parseFromFile();
    if (hasX) {
        auto temp = new graphic(parts);
        g.push_back(temp);
        g.back() -> show();
        return 0;
    } else {
        return withoutX(parts);
    }
}

double stackWrap(std::stack<double>& number) {
    auto result = number.top();
    number.pop();
    return result;
}

double withoutX(const std::vector<std::string>& parts) {
    std::stack<double> numbers;
    for (auto& part : parts) {
        if ('0' <= part[0] && part[0] <= '9') {
            numbers.push(QString(part.c_str()).toDouble());
        } else {
            if (isBinary(part[0])) {
                numbers.push(binary(stackWrap(numbers), stackWrap(numbers), part[0]));
            } else {
                numbers.push(unary(stackWrap(numbers), part[0]));
            }
        }
    }
    return numbers.top();
}

bool isBinary(const char op) {
    switch (op) {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '*':
            return true;
            break;
        case '/':
            return true;
            break;
        case '^':
            return true;
            break;
        case '%':
            return true;
            break;
        default:
            return false;
    }
}

double binary(const double rhs, const double lhs, const char op) {
    if (op == '+') {
        return lhs + rhs;
    } else if (op == '-') {
        return lhs - rhs;
    } else if (op == '*') {
        return lhs * rhs;
    } else if (op == '/') {
        return lhs / rhs;
    } else if (op == '^') {
        return std::pow(lhs, rhs);
    } else if (op == '%') {
        return std::fmod(lhs, rhs);
    }
    return 0;
}

double unary(const double number, const char op) {
    if (op == 'a') {
        return std::sin(number);
    } else if (op == 's') {
        return std::cos(number);
    } else if (op == 'd') {
        return std::tan(number);
    } else if (op == 'g') {
        return std::sqrt(number);
    } else if (op == 'h') {
        return std::log(number);
    } else if (op == 'j') {
        return std::asin(number);
    } else if (op == 'k' ) {
        return std::acos(number);
    } else if (op == 'l') {
        return std::atan(number);
    } else if (op == 'z') {
        return std::log10(number);
    }
    return 0;
}
