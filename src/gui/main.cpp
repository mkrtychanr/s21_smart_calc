#include "calculator.h"
#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QtWidgets>
#include <QPainter>
#include <QtMath>
#include <QPalette>

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   Calculator calculator;
   calculator.setWindowTitle("Calculator");
   calculator.resize(230,200);
   calculator.setFixedSize(700,250);
   calculator.show();
   return app.exec();
   // return 0;
}
