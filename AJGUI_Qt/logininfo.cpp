#include "logininfo.h"

LoginInfo::LoginInfo(QWidget *parent) : QWidget(parent)
{
    // Prepare Items for Login Widget
    // Prepare Label
    QLabel *banner_lbl = new QLabel;
    QPixmap pixmap(":/img/img/banner_test_small.png");
    banner_lbl->setPixmap(pixmap);
    QLabel *server_lbl = new QLabel;
    server_lbl->setText(tr("Server Address:"));
    QLabel *port_lbl = new QLabel;
    port_lbl->setText(tr("Server Port:"));
    QLabel *password_lbl = new QLabel;
    password_lbl->setText(tr("Password:"));

    // Prepare LineEdits
    server_le = new QLineEdit;
    server_le->setPlaceholderText("http://localhost");
    port_le = new QLineEdit;
    port_le->setPlaceholderText("9851");
    password_le = new QLineEdit;
    password_le->setEchoMode(QLineEdit::Password);
    password_le->clear();

    // Prepare Button
    QPushButton *login_btn = new QPushButton;
    login_btn->setText(tr("Login"));

    // Setup GridLayout
    QGridLayout *gridLayout = new QGridLayout(this);

    gridLayout->addWidget(banner_lbl,0,0,1,0);
    gridLayout->addWidget(server_lbl,1,0);
    gridLayout->addWidget(server_le,1,1);
    gridLayout->addWidget(port_lbl,2,0);
    gridLayout->addWidget(port_le,2,1);
    gridLayout->addWidget(password_lbl,3,0);
    gridLayout->addWidget(password_le,3,1);
    gridLayout->addWidget(login_btn,4,1);

    // apply GridLayout to Widget
    setLayout(gridLayout);
    setWindowTitle(tr("Login to AJCore"));
    setFixedSize(QSize(280,256));

    // Connect Slots and Signals
    connect(login_btn, SIGNAL(clicked()), this, SLOT(loginToCore()));
}

void LoginInfo::loginToCore()
{
    // ADD Dialogboxes for Error Handling in future!!!

    if(server_le->text() != "" && port_le->text() != "")
    {
        server = server_le->text();
        qDebug() << "Server: " << server;
        port = port_le->text();
        qDebug() << "Port: " << port;
        if(password_le->text() == "")
        {
            qDebug() << "WARNING: Connection is unsecure due to empty password";
            passwordhash = "";
        }
        else
        {
            MD5Generator *gen = new MD5Generator;
            passwordhash = gen->generateHash(password_le->text());
            qDebug() << "Password: " << passwordhash;
        }
    }
    else
    {
        qDebug() << "Please specify Server and Port!";
    }

}
