#include "xml_manager.h"

XML_Manager::XML_Manager(QObject *parent) : QObject(parent)
{
    /*
    if (!initialize())
    {
        qDebug() << "Initialization failed";
    }
    else
    {
        qDebug() << "Initialization succeded";
    }
    */
}

// Initialization
bool XML_Manager::initialize()
{
    bool success = false;
    qDebug() << "Starting initialization";
    setReadFile("settings.xml");
    qDebug() << "Set READFILE: " << getReadFile();
    qDebug() << "Check if FILE: " << getReadFile() << " exists";
    if (!fileExist())
    {
        qDebug() << "FILE" << getReadFile() << " not found";
        qDebug() << "Initialization failed";
    }
    else
    {
        qDebug() << "Config loaded...";
        // Get values from config file
        loadXML();

        host = getElement("ajcore", "host");
        qDebug() << "Set Host: " << host;
        port = getElement("ajcore", "port");
        qDebug() << "Set Port: " << port;
        password = getElement("ajcore", "password");
        qDebug() << "Set Passwort: " << password;
        // Get a session id from AJCore
        //writefile = "session.xml";
        setWriteFile("session.xml");
        qDebug() << "Writefile set: " << getWriteFile();
        QString test = QString("http://") + host + QString(":") + port + "/xml/" + tables.at(3) + QString("?password=") + password;
        qDebug() << "GENERATED URL: " << test;
        get(QString("http://") + host + QString(":") + port + "/xml/" + tables.at(3) + QString("?password=") + password);
        //readfile = "session.xml";
        setReadFile("session.xml");
        qDebug() << "Set READFILE: " << getReadFile();
        loadXML();
        qDebug() << "GET: " << getElement("session", "id");
        sessionID = getElement("session", "id");
        qDebug() << "SESSION ID: " << sessionID;
        success = true;
        qDebug() << "Initialization succeded";
    }
    return success;
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
    QStringList urls;

    UnixTimer *ut = new UnixTimer;
    time = QVariant(ut->getUnixTime()).toString();

    for (int i=0; i<tables.size(); i++)
    {
        QString url = "http://" + host + ":" + port + "/xml/" + tables.at(i) + "?password=" + password + "&timestamp=" + time;
        qDebug() << url;
        urls << url;
    }
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
        if(!document->setContent(&file))
        {
            qDebug() << "Failed to load Document";
        }
        qDebug() << "Document opened successfully!";
        file.close();
    }
    // get root element
    if (!document->isNull())
    {
        root = document->firstChildElement();
        qDebug() << "Rootelement set";
        qDebug() << "Reading XML-File finished!";
    }
    else
    {
        qDebug() << "Setup XML-File failed! Empty Document";
    }
}

void XML_Manager::writeXML()
{
    /*
    if (writefile.isEmpty() || writefile.isNull())
    {
        qDebug() << "No File to write specified. Aborting...";
    }
    else
    {
        qDebug() << "Write...";
        file.setFileName(writefile); // change to different dir/name
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
    */

    qDebug() << "Write...";
    file.setFileName(getWriteFile()); // change to different dir/name
    qDebug() << "FILENAME: " << file.fileName();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        QTextStream stream(&file);
        stream << document->toString();
        qDebug() << "STREAM: " << document->toString();
        file.close();
        qDebug() << "Finished!";
    }
}

// Returns list of values
QStringList XML_Manager::getValueList(QString tag, QString value)
{
    QStringList list;
    QDomNodeList items = root.elementsByTagName(tag);

    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if(itemnode.isElement())
        {
            QDomElement item = itemnode.toElement();
            list << item.attribute(value);
        }
    }
    return list;
}

// Returns specific element
QString XML_Manager::getElement(QString tag, QString value)
{
    QDomNodeList items = root.elementsByTagName(tag);
    QString element = "";
    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if(itemnode.isElement())
        {
            QDomElement item = itemnode.toElement();
            element = item.attribute(value);
        }
    }
    return element;
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
    /*
    else if (document.isNull())
    {
        qDebug() << "Document is empty";
    }
    */
    else
    {
        qDebug() << "File found. Begin processing...";
        check = true;
    }

    qDebug() << "FOUND: " << check;
    return check;
}

// SET- & GET-Methods

void XML_Manager::setRootElement(QDomElement root)
{
    this->root = root;
}

QDomElement XML_Manager::getRootElement()
{
    return root;
}

void XML_Manager::setDocument(QDomDocument document)
{
    this->document = &document;
}

QDomDocument XML_Manager::getDocument()
{
    return *document;
}

void XML_Manager::setReadFile(QString readfile)
{
    this->readfile = readfile;
}

QString XML_Manager::getReadFile()
{
    return readfile;
}

void XML_Manager::setWriteFile(QString writefile)
{
    this->writefile = writefile;
}

QString XML_Manager::getWriteFile()
{
    return writefile;
}

// Slots

void XML_Manager::replyFinished(QNetworkReply *reply)
{
    if (document->setContent(reply->readAll()))
    {
        qDebug() << "Success";
        writeXML();
    }
    else
    {
        qDebug() << "Failed!";
    }
}
