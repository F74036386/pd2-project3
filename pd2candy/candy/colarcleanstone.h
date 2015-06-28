#ifndef COLARCLEANSTONE_H
#define COLARCLEANSTONE_H
#include"stone.h"

class colarcleanstone:public stone
{  Q_OBJECT
public:
    colarcleanstone(QWidget *parent,int colar,int col ,int row);
    void solve();
signals:
   void click(int,int);
   void slo(int,int,int);
public slots:
    void check(bool);
};

#endif // COLARCLEANSTONE_H
