#include <QCoreApplication>
#include "sockettest.h"
#include "xmlcatcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //SocketTest sTest;
    //sTest.Connect();

    XMLCatcher *xmlc = new XMLCatcher;
    xmlc->start();

    return a.exec();
}
