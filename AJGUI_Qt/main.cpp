#include <QCoreApplication>
#include "sockettest.h"
#include "xmlcatcher.h"
#include "xmlinterpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //SocketTest sTest;
    //sTest.Connect();

    XMLCatcher *xmlc = new XMLCatcher;

    XMLInterpreter *xmli = new XMLInterpreter;

    return a.exec();
}
