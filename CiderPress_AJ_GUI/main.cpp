#include "ciderpress.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CiderPress w;
    w.show();
    return a.exec();
}
