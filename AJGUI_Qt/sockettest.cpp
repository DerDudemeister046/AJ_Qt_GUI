#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}


void SocketTest::downloadFinished(QNetworkReply *reply)
{
    //qDebug() << "Ergebnis: " << reply->readAll();
    QByteArray x = reply->readAll();
    qDebug() << "Ergebnis " << x;
}


void SocketTest::Connect()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &SocketTest::downloadFinished);

    const QUrl url = QUrl("http://192.168.0.2:9851/xml/modified.xml?password=25d55ad283aa400af464c76d713c07ad&session=1945950535&timestamp=1576089551879&filter=down;uploads;user;server;search;informations;ids");
    QNetworkRequest request(url);
    man->get(request);

    /*
    QString hashedpass = "25d55ad283aa400af464c76d713c07ad";
    socket = new QTcpSocket(this);
    socket->connectToHost("192.168.0.2",9851);

    if (socket->waitForConnected(5000))
    {

        qDebug() << "Connected";
        // send Data to Server
        socket->write("Hallo server\r\n\r\n\r\n\r\n\r\n");
        // Get Data from Server
        socket->waitForBytesWritten(5000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();
        socket->close();

        qDebug() << "Socket was closed";

        // QNetworkAccessManager Test


    }
    else
    {
        qDebug() << "Not Connected";
    }
    */
}
