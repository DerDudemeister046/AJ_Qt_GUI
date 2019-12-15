#ifndef CORECOMMUNICATOR_H
#define CORECOMMUNICATOR_H

#include <QObject>
#include <QtXml>
#include <QNetworkAccessManager> // Make requests to core
#include <QNetworkReply> // handle core replies
#include <QDebug>

class CoreCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit CoreCommunicator(QObject *parent = nullptr);
    void start();
    QByteArray getXMLReply();
    void setXMLReply(QByteArray qa);
    void write();
private:
    QByteArray xmlreply;
    QDomDocument document;
signals:

public slots:
private slots:
    void replyFinished(QNetworkReply*);
};

#endif // CORECOMMUNICATOR_H
