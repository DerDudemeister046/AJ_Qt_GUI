#include <QApplication>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow *mainwindow = new MainWindow(nullptr);
    //mainwindow->show();
    mainwindow->start();
    return app.exec();
}
