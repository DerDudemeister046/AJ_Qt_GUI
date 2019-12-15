#include "ciderpress.h"
#include "ui_ciderpress.h"

CiderPress::CiderPress(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CiderPress)
{
    ui->setupUi(this);
}

CiderPress::~CiderPress()
{
    delete ui;
}

