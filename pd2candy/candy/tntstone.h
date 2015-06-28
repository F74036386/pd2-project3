#ifndef TNTSTONE_H
#define TNTSTONE_H
#include"stone.h"

class tntstone:public stone
{  Q_OBJECT
public:
    tntstone(QWidget *parent,int colar,int col ,int row);

    void solve();
signals:
   void click(int,int);
   void slo(int,int,int);
public slots:
    void check(bool);
};

#endif // TNTSTONE_H
