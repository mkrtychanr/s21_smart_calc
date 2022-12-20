#ifndef _Calculator_h_
 #define _Calculator_h_
 #include <QWidget>
 #include <QStack>
 #include <QLabel>
 #include <QPushButton>
 #include <QGridLayout>
#include <string>

 class Calculator : public QWidget {
  Q_OBJECT //макрос, нужен в начале всех наших классов
  private:
   QLabel *displaystring;
   QStack <QString> stack;
   std::string str;
  public:
   Calculator (QWidget* pwgt = 0);
   QPushButton* createButton (const QString& str, int i = 40, int j = 40);
   void calculate ();
  public slots: //Общедоступные обработчики событий
   void slotButtonClicked();
 };
#endif
