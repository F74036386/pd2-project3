#include "score.h"

Score::Score()
{
   scor=0;
   star=0;
}
int Score::getscore(){
    return scor;
}

int Score::getstar(){
    return star;
}
void Score::operator+(int a){
    scor+=a;
    star=scor/1000;
    if(star>3)star=3;
}
void Score::zero(){
    star=0;
    scor=0;
}
