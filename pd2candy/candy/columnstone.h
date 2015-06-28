#ifndef COLUMNSTONE_H
#define COLUMNSTONE_H
#include"stone.h"

class columnstone:public stone
{  Q_OBJECT
public:
    columnstone(QWidget *parent,int colar,int col ,int row);

    void solve();
signals:
   void click(int,int);
   void slo(int,int,int);
public slots:
    void check(bool);
};

#endif // COLUMNSTONE_H
