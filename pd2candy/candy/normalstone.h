#ifndef NORMALSTONE_H
#define NORMALSTONE_H
#include"stone.h"

class normalstone:public stone
{
  Q_OBJECT
public:
    normalstone(QWidget *parent,int colar,int col ,int row);

    void solve();
signals:
   void click(int,int);
   void slo(int,int,int);
public slots:
    void check(bool);
    };

#endif // NORMALSTONE_H
