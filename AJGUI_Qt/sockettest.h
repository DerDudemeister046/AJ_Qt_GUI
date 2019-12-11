#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>   // create TCP Socket
#include <QDebug>

#include <QNetworkAccessManager> // make requests to ajcore
#include <QNetworkReply> // get an handle the replies from ajcore

class SocketTest : public QObject
{
    Q_OBJECT
public:
    explicit SocketTest(QObject *parent = nullptr);
    void Connect();
signals:
public slots:
private:
    QTcpSocket* socket;
private slots:
    void downloadFinished(QNetworkReply*);
};

#endif // SOCKETTEST_H
