#ifndef XMLCATCHER_H
#define XMLCATCHER_H

#include <QtCore>
#include <QObject>
#include <QtXml>    // Implement XML Module
#include <QNetworkAccessManager> // Make requests to core
#include <QNetworkReply> // handle core replies
#include <QDebug>

class XMLCatcher : public QObject
{
    Q_OBJECT
public:
    explicit XMLCatcher(QObject *parent = nullptr);
    void start();

signals:

public slots:
private:
    QByteArray xmlreply;
private slots:
    void replyFinished(QNetworkReply*);
};

#endif // XMLCATCHER_H
