#include "unixtimer.h"

UnixTimer::UnixTimer(QObject *parent) : QObject(parent)
{

}

uint UnixTimer::getUnixTime()
{
    QDateTime current = QDateTime::currentDateTime(); // Get current timestamp
    unixTime = current.toTime_t();
    return unixTime;
}
