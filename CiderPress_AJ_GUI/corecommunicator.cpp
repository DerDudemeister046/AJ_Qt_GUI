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

QString CoreCommunicator::urlCreator(int table)
{
    xmlInterpreter = new XMLInterpreter(this);
    xmlInterpreter->readXML("settings.xml");

    QString ptc = "http://";
    //QString h = "HOST";
    QString h = xmlInterpreter->readElement("ajcore", "host");
    QString hps = ":";
    QString p = xmlInterpreter->readElement("ajcore", "port");
    QString tbl;
    if (table == 1)
    {
        tbl = "xml/directory.xml";
    }
    if (table == 2)
    {
        tbl = "xml/downloadpartlist.xml";
    }
    if (table == 3)
    {
        tbl = "xml/getobject.xml";
    }
    if (table == 4)
    {
        tbl = "xml/getsession.xml";
    }
    if (table == 5)
    {
        tbl = "xml/information.xml";
    }
    if (table == 6)
    {
        tbl = "xml/modified.xml";
    }
    if (table == 7)
    {
        tbl = "xml/settings.xml";
    }
    if (table == 8)
    {
        tbl = "xml/share.xml";
    }
    if (table == 9)
    {
        tbl = "xml/userpartlist.xml";
    }
    QString pwd = "?password=";
    QString pwdHash = xmlInterpreter->readElement("ajcore", "password");
    UnixTimer *unixtime = new UnixTimer;
    QString time = QVariant(unixtime->getUnixTime()).toString();
    QString url = "http://" + h + ":" + p + "/" + tbl + "?password=" + pwdHash + "&timestamp=" + time;
    return url;
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
