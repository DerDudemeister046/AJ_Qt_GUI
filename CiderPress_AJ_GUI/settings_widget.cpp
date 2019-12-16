#include "settings_widget.h"
#include "ui_settings_widget.h"

Settings_Widget::Settings_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings_Widget)
{
    ui->setupUi(this);
    smgr = new Settings_Manager(this);
    md5gen = new MD5Generator(this);
    if (smgr->checkSettingsFile())
    {
        qDebug() << "Populate fields";
        ui->host_le->setText(smgr->readSettingsFile("ajcore", "host"));
        ui->port_le->setText(smgr->readSettingsFile("ajcore", "port"));
        ui->password_le->setText(smgr->readSettingsFile("ajcore", "password"));
        ui->completeDir_le->setText(smgr->readSettingsFile("directories", "complete"));
        ui->incompleteDir_le->setText(smgr->readSettingsFile("directories", "incomplete"));
    }
}

Settings_Widget::~Settings_Widget()
{
    delete ui;
}


void Settings_Widget::on_ok_btn_clicked()
{
    smgr->ajcoreSettings(ui->host_le->text(), ui->port_le->text(), md5gen->generateHash(ui->password_le->text()));
    smgr->directorySettings(ui->completeDir_le->text(),ui->incompleteDir_le->text());
    smgr->writeSettingsFile();
    this->close();
}

void Settings_Widget::on_apply_btn_clicked()
{
    smgr->ajcoreSettings(ui->host_le->text(), ui->port_le->text(), md5gen->generateHash(ui->password_le->text()));
    smgr->directorySettings(ui->completeDir_le->text(),ui->incompleteDir_le->text());
    smgr->writeSettingsFile();
}

void Settings_Widget::on_cancel_btn_clicked()
{
    this->close();
}
