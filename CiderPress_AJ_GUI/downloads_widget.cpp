#include "downloads_widget.h"
#include "ui_downloads_widget.h"

Downloads_Widget::Downloads_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Downloads_Widget)
{
    ui->setupUi(this);
    corecom = new CoreCommunicator(this);
    qDebug() << corecom->urlCreator(6);
}

Downloads_Widget::~Downloads_Widget()
{
    delete ui;
}
