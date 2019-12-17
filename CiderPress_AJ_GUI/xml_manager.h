#ifndef XML_MANAGER_H
#define XML_MANAGER_H

#include <QObject>
#include <QtXml>
#include <QNetworkAccessManager> // Make requests to core
#include <QNetworkReply> // handle core replies
#include <QDebug>

class XML_Manager : public QObject
{
    Q_OBJECT
public:
    explicit XML_Manager(QObject *parent = nullptr);
    void get(QString url);              // Get XML table from AJCore
    QString urlCreator(QString table);  // Generates URL to AJCore
    void loadXML();      // Reads whole XML-File

    // Checker functions
    bool fileExist();

    // SET- & GET-Methods
    void setReadFile(QString readfile);
    QString getReadFile();



private:
    QDomElement root;
    QByteArray xmlreply;
    QDomDocument document;
    QDomDocument settings;

    QStringList *valuelist;

    QFile file;         // XML File handle
    QString writefile;  // file to be written to
    QString readfile;   // file to be read in loadXML()
signals:

public slots:
private slots:
    void replyFinished(QNetworkReply*);
};

#endif // XML_MANAGER_H
