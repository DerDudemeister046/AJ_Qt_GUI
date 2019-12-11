#include "md5calc.h"
#include "ui_md5calc.h"

MD5Calc::MD5Calc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MD5Calc)
{
    ui->setupUi(this);
}

MD5Calc::~MD5Calc()
{
    delete ui;
}


void MD5Calc::on_calc_btn_clicked()
{
    QCryptographicHash calcMd5(QCryptographicHash::Md5);
    QByteArray input;

    QString x = ui->password_le->text();

    input.append(x);

    qDebug() << "INPUT: " << input;
    qDebug() << "Calculate Hash...";

    calcMd5.addData(input);
    // output Hash
    ui->md5hash_le->setEnabled(true);
    ui->md5hash_lbl->setEnabled(true);
    ui->clear_btn->setEnabled(true);
    ui->calc_btn->setEnabled(false);
    ui->password_lbl->setEnabled(false);
    ui->md5hash_le->setText(calcMd5.result().toHex());

    qDebug() << "HASH: " << calcMd5.result();
    qDebug() << "HASH-HEX: " << calcMd5.result().toHex();

    //input.append(ui)
}

void MD5Calc::on_clear_btn_clicked()
{
    ui->password_le->clear();
    ui->password_le->setEnabled(true);
    ui->md5hash_le->clear();
    ui->md5hash_le->setEnabled(false);
    ui->clear_btn->setEnabled(false);
    ui->calc_btn->setEnabled(true);
    ui->md5hash_lbl->setEnabled(false);
    ui->password_lbl->setEnabled(true);
    qDebug() << "all fields cleared";
}
