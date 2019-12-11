#include <QCoreApplication>
#include "sockettest.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketTest sTest;
    sTest.Connect();

    return a.exec();
}
