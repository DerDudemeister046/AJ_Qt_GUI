#ifndef UNIXTIMER_H
#define UNIXTIMER_H

#include <QObject>
#include <QTime>
#include <QDate>
#include <QDebug>

class UnixTimer : public QObject
{
    Q_OBJECT
public:
    explicit UnixTimer(QObject *parent = nullptr);
    // GET-Methods
    uint getUnixTime();         // Return UNIX-Timestamp in Seconds since 01-01-1970
    QDateTime getRealTime();    // Return real Time from UNIX-Timestamp
    // SET-Methods
    void setUnixTime(uint unixTime);
    void setRealTime(QDateTime realTime);
private:
    uint unixTime;
    QDateTime realTime;
signals:

public slots:
};

#endif // UNIXTIMER_H
