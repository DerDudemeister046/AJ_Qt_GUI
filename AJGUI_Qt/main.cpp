#include <QCoreApplication>
#include <QDebug>

#include "sockettest.h"
#include "xmlcatcher.h"
#include "xmlinterpreter.h"
#include "unixtimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //SocketTest sTest;
    //sTest.Connect();

    //XMLCatcher *xmlc = new XMLCatcher;
    //XMLInterpreter *xmli = new XMLInterpreter;

    UnixTimer *ut = new UnixTimer;

    for (int i = 0; i<10000; i++)
    {
        qDebug() << "TIMESTAMP ["<< i << "]: " << ut->getUnixTime();
    }

    return a.exec();
}
