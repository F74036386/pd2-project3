#include "gameing.h"
#include "ui_gameing.h"

gameing::gameing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameing)
{
    ui->setupUi(this);
    this->setFixedSize(800,700);
    this->setWindowTitle("hahaha");
   for(int i=0;i<10;i++){
       for(int j=0;j<10;j++){
           lab[i][j]=NULL;
           colar[i][j]=0;
       }
   }
    chitest=0;
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(restart()));
  gameoverlab=NULL;
    restart();
}

gameing::~gameing()
{
    delete ui;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(lab[i][j]!=NULL)
                delete lab[i][j];
        }
    }
}



void gameing::restart(){
    chitest=1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(lab[i][j]!=NULL){
                delete lab[i][j];
            }
            colar[i][j]=0;
        }
    }

    step=6;
    stepchange();
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
           newlab(i,j);
        }
    }
    temrow=-2;
    temcol=-2;
    score.zero();
    scorechange();

    if(gameoverlab!=NULL){
        delete gameoverlab;
        gameoverlab=NULL;
    }
   checkcomb();
   score.zero();
   scorechange();
   chitest=0;
   go=0;

}


void gameing::newlab(int row,int col){
    srand((unsigned)time(NULL)+rand());
    int cola=rand()%4+1;
    makelab(row, col,cola, 1);
}
 void gameing::makelab(int row,int col,int cola,int type){
     switch(type){
     case 1:{
       lab[col][row]=new normalstone(this,cola,col,row);
        colar[col][row]=cola;
        break;
        }

     case 2:{
       lab[col][row]=new columnstone(this,cola,col,row);
        colar[col][row]=cola;
        break;
        }

     case 3:{
       lab[col][row]=new rowstone(this,cola,col,row);
        colar[col][row]=cola;
        break;
        }

     case 4:{
       lab[col][row]=new tntstone(this,cola,col,row);
        colar[col][row]=cola;
        break;
        }
     case 5:{
       lab[col][row]=new colarcleanstone(this,-1,col,row);
        colar[col][row]=-1;
        break;
        }

     }
  connectall(row,col);

 }
 void gameing::connectall(int row,int col){

     connect(lab[col][row],SIGNAL(click(int,int)),this,SLOT(check(int,int)));
     connect(lab[col][row],SIGNAL(slo(int,int,int)),this,SLOT(solve(int ,int,int)));
 }

 void gameing::check(int row,int col){
     if(go!=0)return;
     if(chitest!=0)return;
     chitest=1;
     if(isgameover())gameover();
     if(temrow==-2||temcol==-2){
         temcol=col;
         temrow=row;
     }
     else{
        int flk=1;
         if((abs(temcol-col)+abs(temrow-row))==1){

             for(int i=0;i<1;i++){
              lab[col][row]->movelab(temrow,temcol,1);
              lab[temcol][temrow]->movelab(row,col,1);
              sleep(500);
             }
             lab[col][row]->move(temrow,temcol);
             lab[temcol][temrow]->move(row,col);
             stone* tem=lab[col][row];
             lab[col][row]=lab[temcol][temrow];
            lab[temcol][temrow]=tem;
             int temm=colar[col][row];
             colar[col][row]=colar[temcol][temrow];
             colar[temcol][temrow]=temm;
             if(colar[col][row]==-1||colar[temcol][temrow]==-1){
                 if(colar[col][row]==-1&&colar[temcol][temrow]==-1){
                     for(int i=0;i<10;i++){
                         for(int j=0;j<10;j++){
                             if(colar[i][j]!=0||lab[i][j]!=NULL){
                                 delete lab[i][j];
                                 lab[i][j]=0;
                                 colar[i][j]=0;
                             }
                         }
                     }
                 }
                 else if(colar[col][row]==-1){
                     delete lab[col][row];
                     lab[col][row]=NULL;
                     colar[col][row]=0;
                     int tt=colar[temcol][temrow];
                     for(int i=0;i<10;i++){
                         for(int j=0;j<10;j++){
                             if(colar[i][j]!=0||lab[i][j]!=NULL){
                                 if(colar[i][j]==tt){
                                 lab[i][j]->solve();

                              }
                            }
                         }
                     }

                 }
                 else if(colar[temcol][temrow]==-1){
                     delete lab[temcol][temrow];
                     lab[temcol][temrow]=NULL;
                     colar[temcol][temrow]=0;
                     int tt=colar[col][row];
                     for(int i=0;i<10;i++){
                         for(int j=0;j<10;j++){
                             if(colar[i][j]!=0||lab[i][j]!=NULL){
                                 if(colar[i][j]==tt){
                                 lab[i][j]->solve();
                              }
                            }
                         }
                     }

                 }
             checkcomb();

             }
             //////////////////////////////////////////////////////////////////////////
             else if(!checkcomb()){
                 for(int i=0;i<1;i++){
                 lab[col][row]->movelab(temrow,temcol,1);
                 lab[temcol][temrow]->movelab(row,col,1);
                 sleep(10);
                 }
                 lab[col][row]->move(temrow,temcol);
                 lab[temcol][temrow]->move(row,col);
                 int temm=colar[col][row];
                 colar[col][row]=colar[temcol][temrow];
                 colar[temcol][temrow]=temm;
                 stone* tem=lab[col][row];
                 lab[col][row]=lab[temcol][temrow];
                lab[temcol][temrow]=tem;
                flk=0;
             }
             temcol=-2;
             temrow=-2;
             if(flk) stepchange();
         }
         else if((abs(temcol-col)+abs(temrow-row))==0){
             //do nothing
         }
         else{
             temcol=col;
             temrow=row;
         }



     }
         if(isgameover())gameover();
          chitest=0;
 }

 void gameing ::solve(int row,int col,int type){

       switch(type){
       case 1:{
       delete lab[col][row];
           lab[col][row]=NULL;
           colar[col][row]=0;
             score+10;
             scorechange();
           break;

       }
       case 2:{
           delete lab[col][row];
           lab[col][row]=NULL;
           colar[col][row]=0;
           for(int i=0;i<10;i++){
               if (lab[i][row]==NULL)continue;
               lab[i][row]->solve();

           }
             score+20;
             scorechange();
           break;
       }
       case 3:{
           delete lab[col][row];
           lab[col][row]=NULL;
           colar[col][row]=0;
           for(int i=0;i<10;i++){
               if (lab[col][i]==NULL)continue;
               lab[col][i]->solve();

           }
             score+20;
             scorechange();
break;
       }
       case 4:{
           delete lab[col][row];
           lab[col][row]=NULL;
           colar[col][row]=0;
           for(int i=0;i<3;i++){
               for(int j=0;j<3;j++){
                   if((col-1+i)<0||(col-1+i)>=10)continue;
                   if((row-1+j)<0||(row-1+j)>=10)continue;
                   if (lab[col-1+i][row-1+j]==NULL)continue;
                   lab[col-1+i][row-1+j]->solve();


               }
           }
             score+30;
             scorechange();
break;
       }
       case 5:{
           delete lab[col][row];
           lab[col][row]=NULL;
         srand((unsigned)time(NULL)+rand());
           colar[col][row]=0;
           int tt=rand()%4+1;
           for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(colar[i][j]==tt){
                       lab[col][row]->solve();
                   }
               }
           }

       }
            score+40;
            scorechange();
       break;
       }

 }
 bool gameing::isfill(){

     for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
             if(colar[i][j]==0)return 0;

         }
     }
    // cout<<"bbb"<<endl;
    return 1;
 }



 void gameing::falling(){
    int flag=0;
        for(int i=9;i>=0;i--){

            int dd=0;
            while(dd==0){

                cout<<i<<endl;
                dd=1;
                for(int j=0;j<10;j++){
                    if(colar[i][j]==0){
                        flag=1;

                        dd=0;
                        for(int times=0;times<1;times++){
                            for(int k=1;k<=i;k++){
                                if(lab[i-k][j]==NULL)continue;
                                lab[i-k][j]->movelab(j,i-k+1,1);

                             }

                              sleep(1);
                         }
                        for(int k=1;k<=i;k++){
                            if(lab[i-k][j]!=NULL){
                            lab[i-k][j]->move(j,i-k+1);
                            }
                            colar[i-k+1][j]=colar[i-k][j];
                            colar[i-k][j]=0;
                            lab[i-k+1][j]=lab[i-k][j];
                            lab[i-k][j]=NULL;
                           // cout<<i-k+1<<endl;

                        }




                       sleep(100);
                    newlab(j,0);
                   // cout<<"aaaaa"<<endl;
}


            }
        }
 }
        if(!isfill()){
           // cout<<"ccc"<<endl;
            falling();
        }
       if(flag==1)checkcomb();
 }




 bool gameing::checkcomb(){
     int flag=0;
    // return flag;///////////////////////////////////////
     for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
             int r1=0;
             int c1=0;
             int iii=0;
             if(colar[i][j]==0)continue;
             if(lab[i][j]==NULL)continue;
             while(colar[i][j]==colar[i+iii][j]){
                 c1++;
                 iii++;
                 if((i+iii)>9)break;
                 if(colar[i+iii][j]==0)break;
             }
       // cout<<c1<<endl;
               if(c1>=3){
                   int tempp=colar[i][j];
                 int fla=0;
                   for(int k=0;k<c1;k++){
                       r1=0;
                       iii=0;
                         while(colar[i+k][j]==colar[i+k][j+iii]){
                             if(colar[i+k][j]==0)break;
                            r1++;
                            iii++;
                            if((j+iii)>9)break;
                             if(colar[i+k][j+iii]==0)break;
                          }
                         iii=0;
                         int r2=0;
                           while(colar[i+k][j]==colar[i+k][j-iii]){
                              if(colar[i+k][j]==0)break;
                               r2++;
                              iii++;
                              if((j-iii)<0)break;
                               if(colar[i+k][j-iii]==0)break;
                            }
                         //  cout<<r1<<' '<<r2<<endl;
                         if(r1+r2>=4){
                            // cout<<'aaaaa'<<endl;

                             for(int l=0;l<r1;l++){
                                if( lab[i+k][j+l]==NULL)continue;
                                 lab[i+k][j+l]->solve();
                                   sleep(100);
                                 }
                             for(int ll=0;ll<r2;ll++){
                                 if( lab[i+k][j-ll]==NULL)continue;
                                lab[i+k][j-ll]->solve();
                             }



                             fla=1;
                             makelab(j,i+k,tempp,4);

                            }



                        else if( lab[i+k][j]!=NULL){
                         //cout<<"k="<<k<<endl;
                          lab[i+k][j]->solve();
                           // cout<<'a'<<endl;
                         }
                            flag=1;
                           // sleep(2000);


                  }
                   if(fla!=1){
                       if(c1==4){
                           makelab(j,i,tempp,3);
                       }
                       if(c1==5){
                           makelab(j,i,tempp,5);
                       }



                  }
               }
          else{
               r1=0;
                 iii=0;
///////////////////////////////////////////////////////////////////////

            while(colar[i][j]==colar[i][j+iii]){
               r1++;
                iii++;
                if((j+iii)>9)break;
                 if(colar[i][j+iii]==0)break;
            }
            if(r1>=3){
                int fla=0;
                int tempp=colar[i][j];
                for(int k=0;k<r1;k++){
                    c1=0;
                    iii=0;
                      while(colar[i][j+k]==colar[i+iii][j+k]){
                        if(colar[i][j+k]==0)break;
                          c1++;
                         iii++;
                         if((i+iii)>9)break;
                          if(colar[i+iii][j+k]==0)break;
                       }//////////////////////////////////////////////////
                      iii=0;
                      int c2=0;
                        while(colar[i][j+k]==colar[i-iii][j+k]){
                           if(colar[i][j+k]==0)break;
                            c2++;
                           iii++;
                           if((i-iii)<0)break;
                            if(colar[i-iii][j+k]==0)break;
                         }
                      //  cout<<c1<<' '<<c2<<endl;
                      if(c1+c2>=4){
                        //  cout<<'aaaaa'<<endl;
                          for(int l=0;l<c1;l++){
                             if( lab[i+l][j+k]==NULL)continue;
                              lab[i+l][j+k]->solve();
                                sleep(100);
                              }
                          for(int ll=0;ll<c2;ll++){
                              if( lab[i-ll][j+k]==NULL)continue;
                             lab[i-ll][j+k]->solve();
                          }
                          fla=1;
                          makelab(j+k,i,tempp,4);

                      }

                     else if( lab[i][j+k]!=NULL){
                     cout<<"k="<<k<<endl;
                       lab[i][j+k]->solve();
                     //    cout<<'a'<<endl;
                       }
                        flag=1;




                        // sleep(2000);
                }

                if(fla!=1){
                    if(c1==4){
                        makelab(j,i,tempp,2);
                    }
                    if(c1==5){
                        makelab(j,i,tempp,5);
                    }

               }
               }
     }
    }
     }
    falling();
return flag;
 }



 bool gameing::isgameover(){
     if(step<=0)  return 1;
     if(!isfill())return 0;
     for(int i=1;i<10;i++){
         for(int j=0;j<10;j++){
             int r1=0;
             int c1=0;
             int iii=0;
             if(colar[i][j]==0)continue;
             if(lab[i][j]==NULL)continue;
             while(colar[i][j]==colar[i+iii][j]){
                 c1++;
                 iii++;
                 if((i+iii)>9)break;
                 if(colar[i+iii][j]==0)break;
             }
             if(c1>=3)return 0;
             iii=0;
             while(colar[i][j]==colar[i][j+iii]){
                r1++;
                 iii++;
                 if((j+iii)>9)break;
                  if(colar[i][j+iii]==0)break;
             }
             if(r1>=3)return 0;

         }
     }


     for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
             tcolar[i][j]=colar[i][j];

         }
     }


     for(int w=0;w<10;w++){
         for(int d=0;d<10;d++){
             if(w+1<10){
             int tt=tcolar[w][d];
             tcolar[w][d]=tcolar[w+1][d];
             tcolar[w+1][d]=tt;

             for(int i=1;i<10;i++){
                 for(int j=0;j<10;j++){
                     int r1=0;
                     int c1=0;
                     int iii=0;
                     if(tcolar[i][j]==0)continue;

                     while(tcolar[i][j]==tcolar[i+iii][j]){
                         c1++;
                         iii++;
                         if((i+iii)>9)break;
                         if(colar[i+iii][j]==0)break;
                     }
                     if(c1>=3)return 0;
                     iii=0;
                     while(tcolar[i][j]==tcolar[i][j+iii]){
                        r1++;
                         iii++;
                         if((j+iii)>9)break;
                          if(tcolar[i][j+iii]==0)break;
                     }
                     if(r1>=3)return 0;

                 }
             }
            tt=tcolar[w][d];
             tcolar[w][d]=tcolar[w+1][d];
             tcolar[w+1][d]=tt;

             }

///////////////////////////////////
             if(d+1<10){
             int tt=tcolar[w][d];
             tcolar[w][d]=tcolar[w][d+1];
             tcolar[w][d+1]=tt;

             for(int i=1;i<10;i++){
                 for(int j=0;j<10;j++){
                     int r1=0;
                     int c1=0;
                     int iii=0;
                     if(tcolar[i][j]==0)continue;

                     while(tcolar[i][j]==tcolar[i+iii][j]){
                         c1++;
                         iii++;
                         if((i+iii)>9)break;
                         if(colar[i+iii][j]==0)break;
                     }
                     if(c1>=3)return 0;
                     iii=0;
                     while(tcolar[i][j]==tcolar[i][j+iii]){
                        r1++;
                         iii++;
                         if((j+iii)>9)break;
                          if(tcolar[i][j+iii]==0)break;
                     }
                     if(r1>=3)return 0;

                 }
             }
             tt=tcolar[w][d];
              tcolar[w][d]=tcolar[w][d+1];
                tcolar[w][d+1]=tt;

             }






         }
     }
     return 1;

 }


 void gameing:: gameover(){
     go=1;
     gameoverlab=new QLabel(this);
     gameoverlab->setGeometry(50,100,600,600);
     switch(score.getstar()){
     case 0: {
         QPixmap x(":/lose.png");
            gameoverlab->setPixmap(x);
         gameoverlab->show();
         break;
        }
     case 1:{
         QPixmap x(":/1star.png");
         gameoverlab->setPixmap(x);
      gameoverlab->show();
         break;
     }
     case 2:{
         QPixmap x(":/2star.png");
         gameoverlab->setPixmap(x);
      gameoverlab->show();
         break;
     }
    case 3:{
         QPixmap x(":/3star.png");
         gameoverlab->setPixmap(x);
      gameoverlab->show();
         break;
     }
     }
     gameoverlab->show();
     emit quit(score.getstar(),score.getscore());
 }

 void gameing::sleep(unsigned int msec)       // use to  delay the time
 {
     QTime dieTime = QTime::currentTime().addMSecs(msec);
     while( QTime::currentTime() < dieTime )
         QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
 }

 void gameing::scorechange(){
     ui->lcdNumber->display(score.getscore());
     ui->lcdNumber_3->display(score.getstar());


 }
  void gameing::stepchange(){
      step--;
     ui->lcdNumber_2->display(step);
  }
