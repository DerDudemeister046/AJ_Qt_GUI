#include "logininfo.h"

LoginInfo::LoginInfo(QWidget *parent) : QWidget(parent)
{
    /*
    QLabel *imgLbl = new QLabel;
    QLabel *lbl_1 = new QLabel(tr("Test1"));
    QPushButton *btn_test1 = new QPushButton(this);
    btn_test1->setText("Login");
    QLineEdit *le_test1 = new QLineEdit;
    QGridLayout *gridLayout = new QGridLayout(this);
    le_test1->setText("Hallo!");

    // Setup Banner
    QPixmap pixmap("./ressources/banner_test.png");
    imgLbl->setPixmap(pixmap);
    //imgLbl->setMask(pixmap.mask());
    imgLbl->show();


    // Setup GUI
    gridLayout->addWidget(imgLbl,1,0,1,0);
    gridLayout->addWidget(btn_test1,2,3);
    gridLayout->addWidget(le_test1, 2, 5);
    gridLayout->addWidget(lbl_1, 3, 0);

    setLayout(gridLayout);
    setWindowTitle(tr("Login Info"));
    */

    // Prepare Items for Login Widget
    // Prepare Label
    QLabel *banner_lbl = new QLabel;
    QLabel *server_lbl = new QLabel;
    QLabel *password_lbl = new QLabel;
    QLabel *port_lbl = new QLabel;
    // Prepare Button
    QPushButton *login_btn = new QPushButton;


}
