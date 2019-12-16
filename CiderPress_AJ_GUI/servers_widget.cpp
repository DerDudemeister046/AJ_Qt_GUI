#include "servers_widget.h"
#include "ui_servers_widget.h"

Servers_Widget::Servers_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Servers_Widget)
{
    ui->setupUi(this);
}

Servers_Widget::~Servers_Widget()
{
    delete ui;
}
