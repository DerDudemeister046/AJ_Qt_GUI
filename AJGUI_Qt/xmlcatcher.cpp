/*
 *
 *  URLS:
 *       http://192.168.0.2:9851/xml/downloadpartlist.xml?password=25d55ad283aa400af464c76d713c07ad&id=392
 *       http://192.168.0.2:9851/xml/modified.xml?password=25d55ad283aa400af464c76d713c07ad&session=1945950535&timestamp=1576101126382&filter=down;uploads;user;server;search;informations;ids
 *       http://192.168.0.2:9851/xml/getobject.xml?password=25d55ad283aa400af464c76d713c07ad&Id=258
 *
 *
 */



#include "xmlcatcher.h"

XMLCatcher::XMLCatcher(QObject *parent) : QObject(parent)
{
    start();
}

void XMLCatcher::replyFinished(QNetworkReply *reply)
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

void XMLCatcher::start()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &XMLCatcher::replyFinished);
    // url should constantly be updated!
    const QUrl url = QUrl("http://192.168.0.2:9851/xml/modified.xml?password=25d55ad283aa400af464c76d713c07ad&session=1945950535&timestamp=1576089551879&filter=down;uploads;user;server;search;informations;ids");
    QNetworkRequest request(url);
    man->get(request);
}

void XMLCatcher::write()
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

QByteArray XMLCatcher::getXMLReply()
{
    return xmlreply;
}

void XMLCatcher::setXMLReply(QByteArray qa)
{
    this->xmlreply = qa;
}
