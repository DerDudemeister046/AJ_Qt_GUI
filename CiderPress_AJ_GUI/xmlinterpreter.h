#ifndef XMLINTERPRETER_H
#define XMLINTERPRETER_H

#include <QObject>
#include <QStringList>
#include <QtXml>
#include <QFile>
#include <QDebug>

class XMLInterpreter : public QObject
{
    Q_OBJECT
public:
    explicit XMLInterpreter(QObject *parent = nullptr);
    void readXML(QString xmlpath);
    void readConfig();
    void listElements(QString tagname, QString attribute); // Lists all elements in XML File
    QStringList getElementList(QString tagname, QString attribute);
    QString readElement(QString tagname, QString attribute);
    QDomDocument getDocument(); // Returns whole document.
private:
    QDomElement root;
    QDomDocument doc;
signals:

public slots:
};

#endif // XMLINTERPRETER_H
