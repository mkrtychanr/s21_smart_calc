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
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_acButton_clicked();
    void on_backSpaceButton_clicked();
    void on_dotButton_clicked();
    void on_zeroButton_clicked();
    void on_oneButton_clicked();
    void on_twoButton_clicked();
    void on_threeButton_clicked();
    void on_fourButton_clicked();
    void on_fiveButton_clicked();
    void on_sixButton_clicked();
    void on_sevenButton_clicked();
    void on_eightButton_clicked();
    void on_nineButton_clicked();
    void on_plusButton_clicked();
    void on_minusButton_clicked();
    void on_mulButton_clicked();
    void on_divButton_clicked();
    void on_powButton_clicked();
    void on_modButton_clicked();
    void on_closeBracketButton_clicked();
    void on_openBracketButton_clicked();
    void on_xButton_clicked();
    void on_sqrtButton_clicked();
    void on_sinButton_clicked();
    void on_cosButton_clicked();
    void on_tanButton_clicked();
    void on_asinButton_clicked();
    void on_acosButton_clicked();
    void on_atanButton_clicked();
    void on_lnButton_clicked();
    void on_logButton_clicked();
    void on_equalsButton_clicked();

private:
    QVector<graphic*> g;
    Ui::Calculator *ui;
    QString str;
    std::vector<Moment> moments;
    bool is_func();
    void toFile();
    void addOpenBracket();
    void addCloseBracket();
    void addDigit(int caseValueNumber);
    void addDot();
    void addX();
    void addUnary(int sizeOfUnary);
    void addBinary();
    void almostAnyButton(const std::string& handeledString);
    void branch0(const std::string& handeledString, bool& status, std::string& additional);
    void branch1(const std::string& handeledString, bool& status, char lastCharacter);
    void branch2(const std::string& handeledString, bool& status, char lastCharacter);
    void branch3(const std::string& handeledString, bool& status, char lastCharacter);
    void branch4(const std::string& handeledString, bool& status, char lastCharacter);
    void branch5(const std::string& handeledString, bool& status, char lastCharacter, std::string& additional);
    void branching(int toCheck, bool &status, const std::string& handeledString, char lastCharacter, std::string& additional);
    void fillMomentsAfterCalcualte(const std::string& resultOfCalculation);

};

std::vector<std::string> parseFromFile();
double calculate(bool hasX, QVector<graphic*>& g);
double stackWrap(std::stack<double>& number);
double withoutX(const std::vector<std::string>& parts);
bool isBinary(const char op);
double binary(const double rhs, const double lhs, const char op);
double unary(const double number, const char op);

#endif // CALCULATOR_H
