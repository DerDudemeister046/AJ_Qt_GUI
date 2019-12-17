#include "xml_manager.h"

XML_Manager::XML_Manager(QObject *parent) : QObject(parent)
{



    // Test -> Echo tables
    qDebug() << "TABLES: " << tables;
    qDebug() << "FUNCTIONS: " << functions;
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

QStringList XML_Manager::urlCreator()
{
    //xmlInterpreter = new XMLInterpreter(this);
    //xmlInterpreter->readXML("settings.xml");
    //QString h = xmlInterpreter->readElement("ajcore", "host");
    //QString p = xmlInterpreter->readElement("ajcore", "port");
    //QString pwdHash = xmlInterpreter->readElement("ajcore", "password");
    //UnixTimer *unixtime = new UnixTimer;
    //QString time = QVariant(unixtime->getUnixTime()).toString();
    //QString url = "http://" + h + ":" + p + "/xml/" + table + "?password=" + pwdHash + "&timestamp=" + time;

    QStringList urls;

    for (int i=0; i<tables.size(); i++)
    {
        QString url = "http://" + host + ":" + port + "/xml/" + tables.at(i) + "?password=" + password + "&timestamp=" + time;
        urls << url;
    }



    qDebug() << "TEST_URLS: " << urls;
    return urls;
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
    if (!document.isNull())
    {
        root = document.firstChildElement();
        qDebug() << "Rootelement set";
        qDebug() << "Reading XML-File finished!";
    }
    else
    {
        qDebug() << "Setup XML-File failed!";
    }
}

// Checker functions

bool XML_Manager::fileExist()
{
    bool check = false;

    if (getReadFile().isNull())
    {
        qDebug() << "Readfile value is empty";
    }
    else if (getReadFile().isEmpty())
    {
        qDebug() << "File is empty";
    }
    else if (document.isNull())
    {
        qDebug() << "Document is empty";
    }
    else
    {
        qDebug() << "File found. Begin processing...";
        check = true;
    }

    qDebug() << "FOUND: " << check;
    return check;
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
    if (document.setContent(reply->readAll()))
    {
        qDebug() << "Success";
    }
    else
    {
        qDebug() << "Failed!";
    }
}
