#include "uploads_widget.h"
#include "ui_uploads_widget.h"

uploads_widget::uploads_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uploads_widget)
{
    ui->setupUi(this);
}

uploads_widget::~uploads_widget()
{
    delete ui;
}
