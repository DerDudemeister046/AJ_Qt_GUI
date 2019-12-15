#ifndef CORECOMMUNICATOR_H
#define CORECOMMUNICATOR_H

#include <QObject>
#include <QtXml>
#include <QNetworkAccessManager> // Make requests to core
#include <QNetworkReply> // handle core replies
#include <QDebug>
#include "xmlinterpreter.h"
#include "unixtimer.h"

class CoreCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit CoreCommunicator(QObject *parent = nullptr);
    void start();
    QByteArray getXMLReply();
    void setXMLReply(QByteArray qa);
    void write();
    QString urlCreator(int table);
private:
    XMLInterpreter *xmlInterpreter;
    QByteArray xmlreply;
    QDomDocument document;
    QDomDocument settings;
signals:

public slots:
private slots:
    void replyFinished(QNetworkReply*);
};

#endif // CORECOMMUNICATOR_H
