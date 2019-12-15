#include "xmlinterpreter.h"

XMLInterpreter::XMLInterpreter(QObject *parent) : QObject(parent)
{

    readXML();

}

void XMLInterpreter::readXML()
{


    QFile file("./settings");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open XML-File";
    }
    else
    {
        qDebug() << "XML-File opened successfully!";
        if(!doc.setContent(&file))
        {
            qDebug() << "Failed to load Document";
        }
        qDebug() << "Document opened successfully!";
        file.close();
    }
    root = doc.firstChildElement();
    // get root element
    // List elements of XML-File
    //listElements(root, "server", "host");
    //listElements(root, "server", "name");
    //listElements(root, "server", "port");
    //listElements(root, "server", "lastseen");
    listElements("ajcore", "host");
    listElements("ajcore", "port");
    listElements("ajcore", "password");
    qDebug() << "Finished!";
}

void XMLInterpreter::listElements(QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    //qDebug() << "Total Items: " << items.count();

    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if(itemnode.isElement())
        {
            QDomElement itemx = itemnode.toElement();
            qDebug() << itemx.attribute(attribute);
        }
    }
}

QString XMLInterpreter::readElement(QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    //qDebug() << "Total Items: " << items.count();
    QString element = "";
    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if(itemnode.isElement())
        {
            QDomElement itemx = itemnode.toElement();
            qDebug() << itemx.attribute(attribute);
            element = itemx.attribute(attribute);
        }
    }
    return element;
}
