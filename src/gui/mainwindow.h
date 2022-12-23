#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const std::vector<std::string>& parts, QWidget *parent = nullptr);
    void on_pushButton_clicked();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double xBegin = 0;
    double xEnd = 0;
    double h = 0;
    QVector<double> x;
    QVector<double> y;
};
#endif // MAINWINDOW_H
