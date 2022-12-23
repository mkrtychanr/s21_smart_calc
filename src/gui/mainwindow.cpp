#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QVector<double> x_, QVector<double> y_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h = 0.1;
    xBegin = -3000;
    xEnd = 3000 + h;

    ui->widget->xAxis->setRange(-1000000, 1000000);
    ui->widget->yAxis->setRange(-1000000, 1000000);
    x = QVector<double>(std::move(x_));
    y = QVector<double>(std::move(y_));
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

