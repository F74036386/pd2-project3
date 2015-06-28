#ifndef ROWSTONE_H
#define ROWSTONE_H
#include"stone.h"

class rowstone:public stone
{  Q_OBJECT
public:
    rowstone(QWidget *parent,int colar,int col ,int row);

    void solve();
signals:
   void click(int,int);
   void slo(int,int,int);
public slots:
    void check(bool);
};

#endif // ROWSTONE_H
