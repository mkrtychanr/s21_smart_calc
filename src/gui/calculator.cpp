#include "calculator.h"
#include <iostream>
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
 myLayout->addWidget(createButton("CE", 40, 188), 1, 7);
 setLayout(myLayout);
 str = "";
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
    printf("%p\n", file);
    fprintf(file, "%s",str.c_str());
    fclose(file);
//      std::cout<<str.size()<<std::endl;
//      system("./test");
}

void Calculator::calculate() {
}

void Calculator::slotButtonClicked() {
    std::string handeledString = ((QPushButton*)sender())->text().toStdString();
    if (handeledString == "CE") {
        str = "";
        displaystring->setText("|");
    }
    else if (handeledString != "=") {
        str += handeledString;
        displaystring->setText(QString(str.c_str()) + "|");
    } else {
        toFile(str);
        if (!is_func(str)) {
            std::cout<<"Win"<<std::endl;
        } else {
            std::cout<<"Lose"<<std::endl;
        }
        displaystring->setText("|");
        str = "";
    }
}
