#ifndef CIDERPRESS_H
#define CIDERPRESS_H

#include <QMainWindow>
#include <QMdiSubWindow>

#include "xml_manager.h"
#include "settings_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CiderPress; }
QT_END_NAMESPACE

class CiderPress : public QMainWindow
{
    Q_OBJECT

public:
    CiderPress(QWidget *parent = nullptr);
    ~CiderPress();

private slots:
    void on_settings_btn_clicked();

private:
    Ui::CiderPress *ui;
    XML_Manager *xmlManager;
};
#endif // CIDERPRESS_H
