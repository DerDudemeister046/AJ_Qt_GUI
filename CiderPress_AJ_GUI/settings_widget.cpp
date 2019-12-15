#include "settings_widget.h"
#include "ui_settings_widget.h"

Settings_Widget::Settings_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings_Widget)
{
    ui->setupUi(this);
    smgr = new Settings_Manager(this);
    md5gen = new MD5Generator(this);
}

Settings_Widget::~Settings_Widget()
{
    delete ui;
}


void Settings_Widget::on_ok_btn_clicked()
{
    smgr->ajcoreSettings(ui->host_le->text(), ui->port_le->text(), md5gen->generateHash(ui->password_le->text()));
    smgr->directorySettings("","");
    smgr->writeSettingsFile();
}

void Settings_Widget::on_apply_btn_clicked()
{

}

void Settings_Widget::on_cancel_btn_clicked()
{

}
