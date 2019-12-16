#include "ciderpress.h"

#include <QApplication>
#include "corecommunicator.h"
#include "xmlinterpreter.h"

/* Test Includes */
#include <QFile>
#include <QtXml>
#include "downloads_widget.h"


#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CiderPress w;
    w.show();


    Downloads_Widget *dw = new Downloads_Widget;
    dw->show();
    //CoreCommunicator* cc = new CoreCommunicator;
    //cc->start();

    //qDebug() << cc->urlCreator();

    return a.exec();
}
