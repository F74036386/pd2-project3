#include "rowstone.h"

rowstone::rowstone(QWidget *parent,int colar,int col ,int row)
{
    button =new QPushButton(parent);
    button->setGeometry(60*row+60,60*col+100,60,60);
    button->setFlat(true);

  char aaa[30];
   sprintf(aaa,":/%d2.png",colar);
    button->setIcon(QIcon(QPixmap(aaa)));
  connect(button,SIGNAL(clicked(bool)),this,SLOT(check(bool)));
         button->show();

           rowlo=row;
           colaror=colar;
           type=1;
           type=3;
}

void rowstone::solve(){
  emit slo(rowlo,collo,type);


}
void rowstone::check(bool a){

    emit click(rowlo,collo);
}
