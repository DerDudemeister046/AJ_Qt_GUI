#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QObject>

class Settings_Manager : public QObject
{
    Q_OBJECT
public:
    explicit Settings_Manager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SETTINGS_MANAGER_H
