#include "corecommunicator.h"

CoreCommunicator::CoreCommunicator(QObject *parent) : QObject(parent)
{

}

void CoreCommunicator::start()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &CoreCommunicator::replyFinished);
    // url should constantly be updated!
    const QUrl url = QUrl("http://192.168.0.2:9851/xml/modified.xml?password=25d55ad283aa400af464c76d713c07ad&session=1945950535&timestamp=1576089551879&filter=down;uploads;user;server;search;informations;ids");
    QNetworkRequest request(url);
    man->get(request);
}


QByteArray CoreCommunicator::getXMLReply()
{
    return xmlreply;
}

void CoreCommunicator::setXMLReply(QByteArray qa)
{
    this->xmlreply = qa;
}

void CoreCommunicator::write()
{
    QFile file("./test.xml"); // change to different dir/name
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished!";
    }
}

void CoreCommunicator::replyFinished(QNetworkReply *reply)
{
    setXMLReply(reply->readAll());
    if (document.setContent(getXMLReply()))
    {
        qDebug() << "Success";
        write();
    }
    else
    {
        qDebug() << "Failed!";
    }
}
