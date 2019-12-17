#ifndef XML_MANAGER_H
#define XML_MANAGER_H

#include <QObject>
#include <QtXml>
#include <QNetworkAccessManager> // Make requests to core
#include <QNetworkReply> // handle core replies
#include <QDebug>

#include "unixtimer.h"

class XML_Manager : public QObject
{
    Q_OBJECT
public:
    explicit XML_Manager(QObject *parent = nullptr);
    void get(QString url);              // Get XML table from AJCore
    QString urlCreator(QString table);  // Generates URL to AJCore
    void loadXML();                     // Reads whole XML-File

    QStringList getValueList(QString tag, QString value);

    // Checker functions
    bool fileExist();                   // Check if file exists, if so return true

    // SET- & GET-Methods
    void setReadFile(QString readfile);     // set filename of file to be read
    QString getReadFile();                  // get filename of file to be read

private:
    // Tables to get information from AJCore
    const QStringList tables = {"directory.xml","downloadpartlist.xml","getobject.xml","getsession.xml","information.xml","modified.xml","settings.xml","share.xml","userpartlist.xml"};
    const QStringList functions = {"canceldownload","cleandownloadlist","pausedownload","processlink","removeserver","resumedownload","search","serverlogin","setpassword","setpowerdownload","setpriority","setsettings"};
    // Values from settings.xml
    QString host;
    QString port;
    QString password;

    QDomElement root;       // Rootelement of XML Table
    QByteArray xmlreply;    // Reply of XML Query
    QDomDocument document;  // XML Document, this is where the root comes from

    QStringList valuelist;

    QFile file;         // XML File handle
    QString writefile;  // file to be written to
    QString readfile;   // file to be read in loadXML()
signals:

public slots:
private slots:
    void replyFinished(QNetworkReply*); // Called everytime a get() was performed
};

#endif // XML_MANAGER_H
