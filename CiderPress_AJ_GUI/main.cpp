#include "ciderpress.h"

#include <QApplication>
#include "corecommunicator.h"
#include "xmlinterpreter.h"

/* Test Includes */
#include <QFile>
#include <QtXml>


#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CiderPress w;
    w.show();

    //CoreCommunicator* cc = new CoreCommunicator;
    //cc->start();

    //qDebug() << cc->urlCreator();

    return a.exec();
}
