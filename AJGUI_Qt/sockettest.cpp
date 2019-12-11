#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::Connect()
{
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
    }
    else
    {
        qDebug() << "Not Connected";
    }
}
