#include "xml_manager.h"

XML_Manager::XML_Manager(QObject *parent) : QObject(parent)
{

}

// Functions

void XML_Manager::get(QString url)
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &XML_Manager::replyFinished);
    const QUrl u = QUrl(url);
    QNetworkRequest request(u);
    man->get(request);
}

QString XML_Manager::urlCreator(QString table)
{
    //xmlInterpreter = new XMLInterpreter(this);
    //xmlInterpreter->readXML("settings.xml");

    //QString h = xmlInterpreter->readElement("ajcore", "host");
    //QString p = xmlInterpreter->readElement("ajcore", "port");
    //QString pwdHash = xmlInterpreter->readElement("ajcore", "password");
    //UnixTimer *unixtime = new UnixTimer;
    //QString time = QVariant(unixtime->getUnixTime()).toString();
    //QString url = "http://" + h + ":" + p + "/xml/" + table + "?password=" + pwdHash + "&timestamp=" + time;
    QString url = table; // = h + p + pwdHash;
    qDebug() << "TEST: " << url;
    return url;
}

/*loadXML reads an XML File from HDD and sets it as content of document*/
void XML_Manager::loadXML()
{
    QFile file(getReadFile());
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open XML-File";
    }
    else
    {
        qDebug() << "XML-File opened successfully!";
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load Document";
        }
        qDebug() << "Document opened successfully!";
        file.close();
    }
    // get root element
    root = document.firstChildElement();
    qDebug() << "Rootelement set";
    qDebug() << "Reading XML-File finished!";
}

// SET- & GET-Methods

void XML_Manager::setReadFile(QString readfile)
{
    this->readfile = readfile;
}

QString XML_Manager::getReadFile()
{
    return readfile;
}

// Slots

void XML_Manager::replyFinished(QNetworkReply *reply)
{
    //setXMLReply(reply->readAll());
    //if (document.setContent(getXMLReply()))
    if (document.setContent(reply->readAll()))
    {
        qDebug() << "Success";
    }
    else
    {
        qDebug() << "Failed!";
    }
}
