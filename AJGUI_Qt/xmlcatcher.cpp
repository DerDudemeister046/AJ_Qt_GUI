#include "xmlcatcher.h"

XMLCatcher::XMLCatcher(QObject *parent) : QObject(parent)
{

}

void XMLCatcher::replyFinished(QNetworkReply *reply)
{
    xmlreply = reply->readAll();
    qDebug() << "AAA: " << xmlreply;
}

void XMLCatcher::start()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &XMLCatcher::replyFinished);
    const QUrl url = QUrl("http://192.168.0.2:9851/xml/modified.xml?password=25d55ad283aa400af464c76d713c07ad&session=1945950535&timestamp=1576089551879&filter=down;uploads;user;server;search;informations;ids");
    QNetworkRequest request(url);
    man->get(request);
}
