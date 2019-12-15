#include "md5generator.h"

MD5Generator::MD5Generator(QObject *parent) : QObject(parent)
{

}

QString MD5Generator::generateHash(QString password)
{
    QCryptographicHash md5cal(QCryptographicHash::Md5);
    QByteArray input;
    input.append(password);
    md5cal.addData(input);
    return md5cal.result().toHex();
}
