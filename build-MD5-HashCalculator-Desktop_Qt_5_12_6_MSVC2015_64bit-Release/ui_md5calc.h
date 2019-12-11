/********************************************************************************
** Form generated from reading UI file 'md5calc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MD5CALC_H
#define UI_MD5CALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MD5Calc
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *password_le;
    QLabel *password_lbl;
    QLineEdit *md5hash_le;
    QLabel *md5hash_lbl;
    QHBoxLayout *horizontalLayout;
    QPushButton *clear_btn;
    QPushButton *calc_btn;

    void setupUi(QWidget *MD5Calc)
    {
        if (MD5Calc->objectName().isEmpty())
            MD5Calc->setObjectName(QString::fromUtf8("MD5Calc"));
        MD5Calc->resize(480, 110);
        verticalLayoutWidget = new QWidget(MD5Calc);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 461, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        password_le = new QLineEdit(verticalLayoutWidget);
        password_le->setObjectName(QString::fromUtf8("password_le"));

        gridLayout->addWidget(password_le, 0, 1, 1, 1);

        password_lbl = new QLabel(verticalLayoutWidget);
        password_lbl->setObjectName(QString::fromUtf8("password_lbl"));

        gridLayout->addWidget(password_lbl, 0, 0, 1, 1);

        md5hash_le = new QLineEdit(verticalLayoutWidget);
        md5hash_le->setObjectName(QString::fromUtf8("md5hash_le"));
        md5hash_le->setEnabled(false);
        md5hash_le->setReadOnly(true);

        gridLayout->addWidget(md5hash_le, 1, 1, 1, 1);

        md5hash_lbl = new QLabel(verticalLayoutWidget);
        md5hash_lbl->setObjectName(QString::fromUtf8("md5hash_lbl"));
        md5hash_lbl->setEnabled(false);

        gridLayout->addWidget(md5hash_lbl, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        clear_btn = new QPushButton(verticalLayoutWidget);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));
        clear_btn->setEnabled(false);

        horizontalLayout->addWidget(clear_btn);

        calc_btn = new QPushButton(verticalLayoutWidget);
        calc_btn->setObjectName(QString::fromUtf8("calc_btn"));

        horizontalLayout->addWidget(calc_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MD5Calc);

        QMetaObject::connectSlotsByName(MD5Calc);
    } // setupUi

    void retranslateUi(QWidget *MD5Calc)
    {
        MD5Calc->setWindowTitle(QApplication::translate("MD5Calc", "MD5Calc", nullptr));
        password_lbl->setText(QApplication::translate("MD5Calc", "Password", nullptr));
        md5hash_lbl->setText(QApplication::translate("MD5Calc", "MD5 Hash", nullptr));
        clear_btn->setText(QApplication::translate("MD5Calc", "Clear", nullptr));
        calc_btn->setText(QApplication::translate("MD5Calc", "Calculate Hash", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MD5Calc: public Ui_MD5Calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MD5CALC_H
