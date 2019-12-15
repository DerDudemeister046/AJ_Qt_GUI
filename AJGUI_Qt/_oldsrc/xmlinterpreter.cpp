#include "xmlinterpreter.h"

XMLInterpreter::XMLInterpreter(QObject *parent) : QObject(parent)
{
    readXML();
}

void XMLInterpreter::readXML()
{
    QDomDocument doc;

    QFile file("./test.xml");
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

    // get root element
    QDomElement root = doc.firstChildElement();

    // List elements of XML-File
    listElements(root, "server", "host");
    listElements(root, "server", "name");
    listElements(root, "server", "port");
    listElements(root, "server", "lastseen");
    qDebug() << "Finished!";
}

void XMLInterpreter::listElements(QDomElement root, QString tagname, QString attribute)
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
