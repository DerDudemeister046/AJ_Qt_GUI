#ifndef XMLINTERPRETER_H
#define XMLINTERPRETER_H

#include <QObject>
#include <QtXml>
#include <QDebug>

class XMLInterpreter : public QObject
{
    Q_OBJECT
public:
    explicit XMLInterpreter(QObject *parent = nullptr);
    void readXML();
    void listElements(QDomElement root, QString tagname, QString attribute); // Lists all elements in XML File
private:


signals:

public slots:
};

#endif // XMLINTERPRETER_H