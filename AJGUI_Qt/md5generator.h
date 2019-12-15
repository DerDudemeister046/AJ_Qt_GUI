#ifndef MD5GENERATOR_H
#define MD5GENERATOR_H

#include <QObject>
#include <QDebug>
#include <QCryptographicHash>

class MD5Generator : public QObject
{
    Q_OBJECT
public:
    explicit MD5Generator(QObject *parent = nullptr);
    QString generateHash(QString password);
signals:

public slots:
};

#endif // MD5GENERATOR_H
