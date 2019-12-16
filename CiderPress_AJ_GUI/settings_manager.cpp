#include "settings_manager.h"

Settings_Manager::Settings_Manager(QObject *parent) : QObject(parent)
{
    // Create Document Root
    root = document.createElement("settings");
    // Add Root to Document
    document.appendChild(root);

    // Check if settingsfile exists. If not create one.

    if (!checkSettingsFile())
    {
        qDebug() << "No settingsfile found.";
        qDebug() << "Creating...";

        if (!createSettingsFile())
        {
            qDebug() << "Configfile cant be created";
        }
        else
        {
            qDebug() << "Configfile successfully created";
        }
    }
    else
    {
        qDebug() << "Configfile found";
    }
}

bool Settings_Manager::checkSettingsFile()
{
    bool fileavailable = false;
    QString fileName(filename);

    if(QFileInfo::exists(fileName))
    {
        fileavailable = true;
    }
    else
    {
        fileavailable = false;
    }
    return fileavailable;
}

// Creates an empty config file with only a root
bool Settings_Manager::createSettingsFile()
{
    bool success = false;
    // Write file to disk
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File cant be opened!";
        success = false;
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        success = true;
    }
    return success;
}


bool Settings_Manager::writeSettingsFile()
{
    bool success = false;

    // Write file to disk
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File cant be opened!";
        success = false;
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        success = true;
    }

    //XMLInterpreter *xi = new XMLInterpreter;
    //xi->readXML("settings.xml");
    //qDebug() << "PASSWD: " << xi->readElement("ajcore", "password");

    return success;
}

void Settings_Manager::readSettingsFile()
{
    XMLInterpreter *xmlinterpreter = new XMLInterpreter;

}


// Creates and writes Section acjore in settingsfile
void Settings_Manager::ajcoreSettings(QString host, QString port, QString password)
{
    QDomElement settings = document.createElement("ajcore");
    settings.setAttribute("host", host);
    settings.setAttribute("port", port);
    settings.setAttribute("password", password);
    root.appendChild(settings);
}

void Settings_Manager::directorySettings(QString complete, QString incomplete)
{
    QDomElement settings = document.createElement("directories");
    settings.setAttribute("complete", complete);
    settings.setAttribute("incomplete", incomplete);
    root.appendChild(settings);
}

