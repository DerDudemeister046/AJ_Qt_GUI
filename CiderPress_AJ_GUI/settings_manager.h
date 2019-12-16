#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QObject>
#include <QFile>        // for filehandling
#include <QFileInfo>    // get information from files
#include <QtXml>        // save and load settings in XML format
#include <QtDebug>

#include "xmlinterpreter.h"

class Settings_Manager : public QObject
{
    Q_OBJECT
public:
    explicit Settings_Manager(QObject *parent = nullptr);
    bool checkSettingsFile();   // checks if a settingsfile has been created.
    bool createSettingsFile();  // creates an empty settingsfile
    bool writeSettingsFile();   // writes settings to disk
    void readSettingsFile();
    void ajcoreSettings(QString host, QString port, QString password);
    void directorySettings(QString complete, QString incomplete);
private:
    QDomDocument document;
    QDomElement root;
    QString filename = "settings.xml";
signals:

public slots:
};

#endif // SETTINGS_MANAGER_H
