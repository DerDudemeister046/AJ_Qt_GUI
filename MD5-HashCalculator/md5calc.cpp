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

