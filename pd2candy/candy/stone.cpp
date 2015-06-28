#include "stone.h"

stone::stone()
{
int a=0;
}

stone::~stone(){
delete button;
}
void stone::check(bool a){
    if (a==false) return;
    emit click(rowlo,collo);
}

 void stone ::move(int tergetrow,int tergetcol){
     rowlo=tergetrow;
     collo=tergetcol;

 }

 void stone:: movelab(int tergetrow,int tergetcol,int movetimes){
     double a=((double)tergetrow-(double)rowlo)/(double)movetimes;
      double b=((double)tergetcol-(double)collo)/(double)movetimes;
     button->setGeometry(60*rowlo+60+a*60,60*collo+100+b*60,50,50);


 }

