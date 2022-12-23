#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <cstdio>
#include <stack>
#include "calculator.h"

MainWindow::MainWindow(const std::vector<std::string>& parts, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    double fromGraphicX = 0;
    double toGraphicX = 0;
    double fromGraphicY = 0;
    double toGraphicY = 0;
    double fromFunctionX = 0;
    double toFunctionX = 0;
    for (bool status = false; !status; fromGraphicX = QInputDialog::getDouble(this, tr("enter value"), tr("from graphic x"), 0, -1000000, 1000000, 1, &status)) {}
    for (bool status = false; !status; toGraphicX = QInputDialog::getDouble(this, tr("enter value"), tr("to graphic x"), 0, -1000000, 1000000, 1, &status)) {}
    for (bool status = false; !status; fromGraphicY = QInputDialog::getDouble(this, tr("enter value"), tr("from graphic y"), 0, -1000000, 1000000, 1, &status)) {}
    for (bool status = false; !status; toGraphicY = QInputDialog::getDouble(this, tr("enter value"), tr("to graphic y"), 0, -1000000, 1000000, 1, &status)) {}

    for (bool status = false; !status; fromFunctionX = QInputDialog::getDouble(this, tr("enter value"), tr("from function x"), 0, -1000000, 1000000, 1, &status)) {}
    for (bool status = false; !status; toFunctionX = QInputDialog::getDouble(this, tr("enter value"), tr("to function x"), 0, -1000000, 1000000, 1, &status)) {}
    ui->widget->xAxis->setRange(fromGraphicX, toGraphicX);
    ui->widget->yAxis->setRange(fromGraphicY, toGraphicY);
    for (double p = fromFunctionX; p < toFunctionX; p += 0.1 ) {
        std::stack<double> numbers;
        for (auto& part : parts) {
            if ('0' <= part[0] && part[0] <= '9') {
                numbers.push(QString(part.c_str()).toDouble());
            } else if (part[0] == 'x') {
                numbers.push(p);
            } else {
                if (isBinary(part[0])) {
                    numbers.push(binary(stackWrap(numbers), stackWrap(numbers), part[0]));
                } else {
                    numbers.push(unary(stackWrap(numbers), part[0]));
                }
            }
        }
        x.push_back(p);
        y.push_back(numbers.top());
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}
