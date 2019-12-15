#include <QApplication>

#include "mainwindow.h"
#include "logininfo.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    LoginInfo* login = new LoginInfo;
    login->show();

    qDebug() << "A";



    return app.exec();
}
