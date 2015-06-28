#include "gameing.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameing w;
    w.show();

    return a.exec();
}
