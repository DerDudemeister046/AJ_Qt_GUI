#include "ciderpress.h"
#include "ui_ciderpress.h"


#include "settings_widget.h"
#include "downloads_widget.h"

#include <QLayout>


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


void CiderPress::on_pushButton_clicked()
{
    qDeleteAll(ui->widget->children());
    Settings_Widget *sw = new Settings_Widget(ui->widget);
    sw->show();

}

void CiderPress::on_pushButton_2_clicked()
{
    qDeleteAll(ui->widget->children());
    Downloads_Widget *dw = new Downloads_Widget(ui->widget);
    dw->show();
}
