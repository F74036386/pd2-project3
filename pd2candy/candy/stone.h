
#ifndef STONE_H
#define STONE_H
#include<QLabel>

#include<QPushButton>
#include<QObject>
#include<QWidget>
#include <QWidget>

class stone :public QObject
{
public:

    stone();
    ~stone();

    void move(int tergetrow,int tergetcol);
    void movelab(int tergetrow,int tergetcol,int movetimes);
   virtual void solve()=0;
signals:
   void click(int,int);
   void slo(int,int,int);
public slots:
    void check(bool);
protected:
    int colaror;
    QPushButton* button;

    int rowlo;
    int collo;
    int type;
};

#endif // STONE_H




