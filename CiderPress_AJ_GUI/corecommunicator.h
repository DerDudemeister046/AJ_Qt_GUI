#ifndef CORECOMMUNICATOR_H
#define CORECOMMUNICATOR_H

#include <QObject>

class CoreCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit CoreCommunicator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CORECOMMUNICATOR_H
