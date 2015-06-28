#ifndef SCORE_H
#define SCORE_H


class Score
{
public:
    Score();
    int getscore();
    int getstar();
    void operator+(int);
    void zero();
    void setscore(int a);
private:
    int scor;
    int star;
};

#endif // SCORE_H
