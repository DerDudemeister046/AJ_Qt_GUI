#ifndef UNIXTIMER_H
#define UNIXTIMER_H

#include <QObject>

class UnixTimer : public QObject
{
    Q_OBJECT
public:
    explicit UnixTimer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // UNIXTIMER_H
