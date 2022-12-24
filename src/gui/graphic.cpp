#include "calculator.h"
#include "graphic.h"
#include "ui_graphic.h"
#include <iostream>

graphic::graphic(std::vector<std::string>& p, QWidget *parent) : QWidget(parent), ui(new Ui::graphic)
{
    ui->setupUi(this);
    parts = p;
}

graphic::~graphic()
{
    delete ui;
}

void graphic::on_pushButton_clicked()
{
    ui->graph->removeGraph(ui->graph->graph());
    ui->graph->xAxis->setRange(ui->xFrom->text().toInt(), ui->xTo->text().toInt());
    ui->graph->yAxis->setRange(ui->yFrom->text().toInt(), ui->yTo->text().toInt());
    QVector<double> x;
    QVector<double> y;
    double fromFunctionX = ui->fFrom->text().toDouble();
    double toFunctionX = ui->fTo->text().toDouble();

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
        ui->graph->addGraph();
        ui->graph->graph(0)->addData(x, y);
        ui->graph->replot();
}

