#include "md5calc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MD5Calc w;
    w.show();
    return a.exec();
}
