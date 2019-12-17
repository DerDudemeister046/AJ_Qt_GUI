#include "ciderpress.h"

#include <QApplication>

//#include "corecommunicator.h"
//#include "xmlinterpreter.h"
/* Test Includes */
//#include <QFile>
//#include <QtXml>
//#include "downloads_widget.h"
//#include "uploads_widget.h"
//#include "servers_widget.h"

#include "xml_manager.h"


#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //CiderPress w;
    //w.show();


    XML_Manager *xml = new XML_Manager;
    xml->setReadFile("settings.xml");
    xml->loadXML();

    //Downloads_Widget *dw = new Downloads_Widget;
    //dw->show();
    //Uploads_Widget *uw = new Uploads_Widget;
    //uw->show();
    //Servers_Widget *sw = new Servers_Widget;
    //sw->show();
    //CoreCommunicator* cc = new CoreCommunicator;
    //cc->start();
    //qDebug() << cc->urlCreator();

    return a.exec();
}
