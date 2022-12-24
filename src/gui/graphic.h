#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <vector>

namespace Ui {
class graphic;
}

class graphic : public QWidget
{
    Q_OBJECT

public:
    explicit graphic(std::vector<std::string>& p, QWidget *parent = nullptr);
    ~graphic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::graphic *ui;
    std::vector<std::string> parts;
};

#endif // GRAPHIC_H
