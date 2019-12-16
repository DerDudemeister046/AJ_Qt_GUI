#include "corecommunicator.h"

CoreCommunicator::CoreCommunicator(QObject *parent) : QObject(parent)
{

}

void CoreCommunicator::start()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &CoreCommunicator::replyFinished);
    // url should constantly be updated!
    const QUrl url = QUrl("http://192.168.0.2:9851/xml/downloadpartlist.xml?password=25d55ad283aa400af464c76d713c07ad&simple&id=11692");
    QNetworkRequest request(url);
    man->get(request);
}

void CoreCommunicator::get(QString url)
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &CoreCommunicator::replyFinished);
    // url should constantly be updated!
    const QUrl u = QUrl(url);
    QNetworkRequest request(u);
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
    file.setFileName(filename); // change to different dir/name
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

QString CoreCommunicator::urlCreator(QString table)
{
    xmlInterpreter = new XMLInterpreter(this);
    xmlInterpreter->readXML("settings.xml");

    QString h = xmlInterpreter->readElement("ajcore", "host");
    QString p = xmlInterpreter->readElement("ajcore", "port");
    QString pwdHash = xmlInterpreter->readElement("ajcore", "password");
    UnixTimer *unixtime = new UnixTimer;
    QString time = QVariant(unixtime->getUnixTime()).toString();
    QString url = "http://" + h + ":" + p + "/xml/" + table + "?password=" + pwdHash + "&timestamp=" + time;
    return url;
}

void CoreCommunicator::setFilename(QString filename)
{
    this->filename = filename;
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
