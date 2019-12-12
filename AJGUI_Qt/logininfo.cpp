#include "logininfo.h"

LoginInfo::LoginInfo(QWidget *parent) : QWidget(parent)
{
    QLabel *lbl_1 = new QLabel(tr("Test1"));
    QPushButton *btn_test1 = new QPushButton(this);
    QLineEdit *le_test1 = new QLineEdit;
    QGridLayout *gridLayout = new QGridLayout(this);
    le_test1->setText("Hallo!");

    gridLayout->addWidget(btn_test1);
    gridLayout->addWidget(le_test1);
    gridLayout->addWidget(lbl_1);

    setLayout(gridLayout);
    setWindowTitle(tr("Login Info"));
}
