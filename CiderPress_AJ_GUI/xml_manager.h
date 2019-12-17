#ifndef XML_MANAGER_H
#define XML_MANAGER_H

#include <QObject>

class XML_Manager : public QObject
{
    Q_OBJECT
public:
    explicit XML_Manager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // XML_MANAGER_H
