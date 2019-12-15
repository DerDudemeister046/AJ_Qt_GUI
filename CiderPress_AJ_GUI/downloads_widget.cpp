#include "downloads_widget.h"
#include "ui_downloads_widget.h"

Downloads_Widget::Downloads_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Downloads_Widget)
{
    ui->setupUi(this);
}

Downloads_Widget::~Downloads_Widget()
{
    delete ui;
}
