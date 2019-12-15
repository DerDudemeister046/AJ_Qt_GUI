#ifndef XMLPATHGENERATOR_H
#define XMLPATHGENERATOR_H

#include <QObject>
#include <QDebug>
#include "unixtimer.h"

class XMLPathGenerator : public QObject
{
    Q_OBJECT
public:
    explicit XMLPathGenerator(QObject *parent = nullptr);
    QString outputPath(); // Returns completed path
private:
    QString path;         // Variable to generate Path to XML
    QString pwdHash;      // contains Hashed Password
    QString port;         // XML Port to communicate to/from
signals:

public slots:
};

#endif // XMLPATHGENERATOR_H
