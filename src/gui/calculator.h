#ifndef _Calculator_h_
 #define _Calculator_h_
 #include <QWidget>
 #include <QStack>
 #include <QLabel>
 #include <QPushButton>
 #include <QGridLayout>
#include <string>

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
  Q_OBJECT //макрос, нужен в начале всех наших классов
  private:
   QLabel *displaystring;
   QStack <QString> stack;
   std::string str;
   std::vector<Moment> moments;
  public:
   Calculator (QWidget* pwgt = 0);
   QPushButton* createButton (const QString& str, int i = 40, int j = 40);
   double calculate (bool hasX);
  public slots: //Общедоступные обработчики событий
   void slotButtonClicked();
 };
#endif
