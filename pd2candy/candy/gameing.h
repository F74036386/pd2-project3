
#ifndef GAMEING_H
#define GAMEING_H

#include <QWidget>
#include<QLabel>
#include<QLCDNumber>
#include<ctime>
#include<QTime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<fstream>
#include"stone.h"
#include"normalstone.h"
#include"columnstone.h"
#include"rowstone.h"
#include"tntstone.h"
#include"score.h"
#include"colarcleanstone.h"
#include<iostream>
using namespace std;



namespace Ui {
class gameing;
}

class gameing : public QWidget
{
    Q_OBJECT

public:
    explicit gameing(QWidget *parent = 0);
     void makelab(int row,int col,int cola,int type);
     void newlab(int row,int col);
     void scorechange();
     void stepchange();
     void connectall(int row,int col);
     bool isfill();
     void falling();
     bool checkcomb();
     void sleep(unsigned int);
     bool isgameover();
     void gameover();
    ~gameing();
signals:
     void quit(int star,int score);
private slots:
    void restart();
    void check(int ,int);
    void solve(int ,int ,int);
    void checkbest();


private:
    Ui::gameing *ui;
    stone* lab[10][10];
    int colar[10][10];
    int tcolar[10][10];
    Score score;
    int step;
    int temrow,temcol;
    int chitest;
    int go;
    QLabel *gameoverlab;
    int best;
};

#endif // GAMEING_H

