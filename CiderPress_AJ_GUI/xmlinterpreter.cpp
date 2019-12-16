#include "xmlinterpreter.h"

XMLInterpreter::XMLInterpreter(QObject *parent) : QObject(parent)
{
}

void XMLInterpreter::readXML(QString xmlpath)
{
    QFile file(xmlpath);
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
    root = doc.firstChildElement();
    qDebug() << "Reading XML-File finished!";
}

void XMLInterpreter::listElements(QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

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

QStringList XMLInterpreter::getElementList(QString tagname, QString attribute)
{
    QStringList list;
    QDomNodeList items = root.elementsByTagName(tagname);

    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if(itemnode.isElement())
        {
            QDomElement itemx = itemnode.toElement();
            qDebug() << itemx.attribute(attribute);
            list << itemx.attribute(attribute);
        }
    }
    return list;
}

QString XMLInterpreter::readElement(QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QString element = "";
    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if(itemnode.isElement())
        {
            QDomElement itemx = itemnode.toElement();
            //qDebug() << itemx.attribute(attribute);
            element = itemx.attribute(attribute);
        }
    }
    return element;
}

QDomDocument XMLInterpreter::getDocument()
{
    return doc;
}
