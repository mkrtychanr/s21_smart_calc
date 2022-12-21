#include "calculator.h"
#include <stack>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

Calculator::Calculator (QWidget *parent) : QWidget(parent) {
    displaystring = new QLabel("|");
    displaystring->setMinimumSize (150, 50);
    QString aButtons[5][6] = {
        {"^", "%", "x", "(",   ")",   "sqrt"},
        {"7", "8", "9", "/", "sin", "asin"},
        {"4", "5", "6", "*", "cos", "acos"},
        {"1", "2", "3", "-", "tan", "atan"},
        {"0", ".", "=", "+", "ln",  "log"}
    };

    QGridLayout *myLayout = new QGridLayout;
    myLayout->addWidget(displaystring, 0, 0, 1, 6);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            myLayout->addWidget(createButton(aButtons[i][j]), i + 1, j);
        }
    }
    myLayout->addWidget(createButton("<-", 40, 40), 1, 7);
    myLayout->addWidget(createButton("CE", 40, 152), 2, 7);
    setLayout(myLayout);
    str = "";
    moments.push_back(Moment(0, 0, 0));
}

QPushButton* Calculator::createButton (const QString& str, int i, int j) {
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(i, j);
    connect(pcmd, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
    return pcmd;
}

bool is_func(const std::string& str) {
    for (auto c : str) {
        if (c == 'x') {
            return true;
        }
    }
    return false;
}

void toFile(const std::string& str) {
    auto file = fopen(".expression", "w");
    fprintf(file, "%s",str.c_str());
    fclose(file);
    system("./graph");
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


double Calculator::calculate(bool hasX) {
    std::vector<std::string> parts = parseFromFile();
    if (hasX) {
        return 0;
    } else {
        return withoutX(parts);
    }
}

void addOpenBracket(std::vector<Moment>& moments) {
    moments.push_back(Moment(moments.back().bracketCounter + 1, 0, 1));
}

void addDigit(std::vector<Moment>& moments, int caseValueForNumber) {
    moments.push_back(Moment(moments.back().bracketCounter, 1, caseValueForNumber));
}

void addCloseBracket(std::vector<Moment>& moments) {
    moments.push_back(Moment(moments.back().bracketCounter - 1, 4, 1));
}

void addX(std::vector<Moment>& moments) {
    moments.push_back(Moment(moments.back().bracketCounter, 3, 1));
}

void addUnary(std::vector<Moment>& moments, int sizeOfUnary) {
    moments.push_back(Moment(moments.back().bracketCounter + 1, 0, sizeOfUnary + 1));
}

void addDot(std::vector<Moment>& moments) {
    moments.push_back(Moment(moments.back().bracketCounter, 2, 1));
}

void addBinary(std::vector<Moment>& moments) {
    moments.push_back(Moment(moments.back().bracketCounter, 5, 1));
}

void branch0(const std::string& handeledString, std::vector<Moment>& moments, bool& status, char lastCharacter, std::string& additional) {
    int caseValueForNumber = 1;
    if (handeledString == "(") {
        addOpenBracket(moments);
    } else if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(moments, caseValueForNumber);
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket(moments);
    } else if (handeledString == "x") {
        addX(moments);
    } else {
        additional = "(";
        if (handeledString == "-") {
            addUnary(moments, 1);
        } else if (handeledString == "ln") {
            addUnary(moments, 2);
        } else if (handeledString == "sin" || handeledString == "cos" || handeledString == "tan" || handeledString == "log") {
            addUnary(moments, 3);
        } else if (handeledString == "sqrt" || handeledString == "asin" || handeledString == "acos" || handeledString == "atan") {
            addUnary(moments, 4);
        } else {
            status = false;
        }
    }
}

void branch1(const std::string& handeledString, std::vector<Moment>& moments, bool& status, char lastCharacter) {
    int caseValueForNumber = 1;
    if (handeledString == ".") {
        addDot(moments);
    } else if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(moments, caseValueForNumber);
    } else if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary(moments);
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket(moments);
    } else {
        status = false;
    }
}

void branch2(const std::string& handeledString, std::vector<Moment>& moments, bool& status, char lastCharacter) {
    int caseValueForNumber = 2;
    if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(moments, caseValueForNumber);
    } else if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary(moments);
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket(moments);
    } else {
        status = false;
    }
}

void branch3(const std::string& handeledString, std::vector<Moment>& moments, bool& status, char lastCharacter) {
    if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary(moments);
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket(moments);
    } else {
        status = false;
    }
}

void branch4(const std::string& handeledString, std::vector<Moment>& moments, bool& status, char lastCharacter) {
    if (handeledString == "+" || handeledString == "-" || handeledString == "*" || handeledString == "/" || handeledString == "^" || handeledString == "%") {
        addBinary(moments);
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket(moments);
    } else {
        status = false;
    }
}

void branch5(const std::string& handeledString, std::vector<Moment>& moments, bool& status, char lastCharacter, std::string& additional) {
    int caseValueForNumber = 1;
    if (handeledString == "(") {
        addOpenBracket(moments);
    } else if (handeledString == ")" && moments.back().bracketCounter > 0 && lastCharacter != '(') {
        addCloseBracket(moments);
    } else if (handeledString == "x") {
        addX(moments);
    } else if ('0' <= handeledString[0] && handeledString[0] <= '9') {
        addDigit(moments, caseValueForNumber);
    } else {
        additional = "(";
        if (handeledString == "ln") {
            addUnary(moments, 2);
        } else if (handeledString == "sin" || handeledString == "cos" || handeledString == "tan" || handeledString == "log") {
            addUnary(moments, 3);
        } else if (handeledString == "sqrt" || handeledString == "asin" || handeledString == "acos" || handeledString == "atan") {
            addUnary(moments, 4);
        } else {
            status = false;
        }
    }
}


void branching(int toCheck, bool &status, const std::string& handeledString, std::vector<Moment>& moments, char lastCharacter, std::string& additional) {
    if (toCheck == 0) {
        branch0(handeledString, moments, status, lastCharacter, additional);
    } else if (toCheck == 1) {
        branch1(handeledString, moments, status, lastCharacter);
    } else if (toCheck == 2) {
        branch2(handeledString, moments, status, lastCharacter);
    } else if (toCheck == 3) {
        branch3(handeledString, moments, status, lastCharacter);
    } else if (toCheck == 4) {
        branch4(handeledString, moments, status, lastCharacter);
    } else if (toCheck == 5) {
        branch5(handeledString, moments, status, lastCharacter, additional);
    }
}

void Calculator::slotButtonClicked() {
    std::string handeledString = ((QPushButton*)sender())->text().toStdString();
    if (handeledString == "CE") {
        str = "";
        displaystring->setText("|");
        moments.clear();
        moments.push_back(Moment(0, 0, 0));
    } else if (handeledString != "=") {
        std::string additional = "";
        bool status = true;
        branching(moments.back().status, status, handeledString, moments, str.back(), additional);
        if (status) {
            str += handeledString;
            str += additional;
        }
        displaystring->setText(QString(str.c_str()) + "|");
    } else {
        if (str.size() != 0) {
            toFile(str);
            auto a = calculate(is_func(str));
            str = std::to_string(a);
            displaystring->setText(str.c_str());
        }
    }
}

// bracketSCounter = 0
// разрешены цифры, запрещена точка, переменная и унарные функции разрешены status 0
// также, как и статус 2, но разерешена точка status 1
// после точки, разрешены цифры, закрытая скобка по возможности, бинарные фукнции status 2
// нажата переменная, разрешены бинарные функции, возможна закрытая скобка status 3
// после закрытой скобки, разрешены только бинарные функции status 4
// после бинарного знака, разрешены цифры и унарные знаки, минус запрещен status 5
