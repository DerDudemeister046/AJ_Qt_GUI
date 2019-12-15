#ifndef LOGININFO_H
#define LOGININFO_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPalette>
#include <QImageReader>
#include <QPixmap>
#include <QDebug>


#include "md5generator.h"
#include "mainwindow.h"

class LoginInfo : public QWidget
{
    Q_OBJECT
public:
    explicit LoginInfo(QWidget *parent = nullptr);
    bool dataValid();
    QString getServer();
    QString getPort();
    QString getPasswordHash();
private:
    QLineEdit *server_le;
    QLineEdit *port_le;
    QLineEdit *password_le;

    QString server;
    QString port;
    QString passwordhash;
    bool data;
signals:

public slots:
    void loginToCore();
};

#endif // LOGININFO_H
