#ifndef _Calculator_h_
 #define _Calculator_h_
 #include <QWidget>
 #include <QStack>
 #include <QLabel>
 #include <QPushButton>
 #include <QGridLayout>
#include <string>
#include "mainwindow.h"

struct Moment {
    int bracketCounter = 0;
    int status = 0;
    int characters = 0;
    Moment(int bracketCounter, int status, int characters) {
      this->bracketCounter = bracketCounter;
      this->status = status;
      this->characters = characters;
    }
};

class Calculator : public QWidget {
    Q_OBJECT
    private:
        QLabel *displaystring;
        QStack <QString> stack;
        std::string str;
        std::vector<Moment> moments;
        QVector<double> x;
        QVector<double> y;
        void withX(const std::vector<std::string> &parts);
    public:
        Calculator (QWidget* pwgt = 0);
        QPushButton* createButton (const QString& str, int i = 40, int j = 40);
        double calculate (bool hasX);
        QVector<MainWindow*> w;
        ~Calculator();
    public slots:
        void slotButtonClicked();
};
#endif
