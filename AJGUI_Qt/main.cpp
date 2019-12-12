#include <QCoreApplication>
#include <QApplication>
#include <QDebug>

#include "xmlcatcher.h"
#include "xmlinterpreter.h"
#include "unixtimer.h"
#include "logininfo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    //QCoreApplication a(argc, argv);
    //XMLCatcher *xmlc = new XMLCatcher;
    //XMLInterpreter *xmli = new XMLInterpreter;
    /*
    UnixTimer *ut = new UnixTimer;

    for (int i = 0; i<10000; i++)
    {
        qDebug() << "TIMESTAMP ["<< i << "]: " << ut->getUnixTime();
    }
    */
    //LoginInfo *login = new LoginInfo();
    //login->show();

    LoginInfo login;
    login.show();

    //return a.exec();
    return app.exec();
}
