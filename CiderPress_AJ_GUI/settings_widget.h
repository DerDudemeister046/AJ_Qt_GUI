#ifndef SETTINGS_WIDGET_H
#define SETTINGS_WIDGET_H

#include <QWidget>
#include <QDebug>
#include "settings_manager.h" // check if file exists, create and modifiy settings file
#include "md5generator.h"   // generate password hash from entered password

namespace Ui {
class Settings_Widget;
}

class Settings_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Settings_Widget(QWidget *parent = nullptr);
    ~Settings_Widget();

private slots:
    void on_ok_btn_clicked();

    void on_apply_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::Settings_Widget *ui;
    Settings_Manager *smgr;
    MD5Generator *md5gen;
};

#endif // SETTINGS_WIDGET_H
