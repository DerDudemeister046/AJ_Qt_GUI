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
    //ui->mdiArea->setTabsMovable(true);
    //ui->mdiArea->setTabsClosable(true);

    Downloads_Widget *dw_mdi = new Downloads_Widget(ui->mdiArea);
    Settings_Widget *sw_mdi = new Settings_Widget(ui->mdiArea);

    QMdiSubWindow *sw_subwindow = new QMdiSubWindow;

    sw_subwindow->setWidget(sw_mdi);
    sw_subwindow->setAttribute(Qt::WA_DeleteOnClose);
    ui->mdiArea->addSubWindow(sw_subwindow);


    QMdiSubWindow *sw_subwindow2 = new QMdiSubWindow;

    sw_subwindow2->setWidget(dw_mdi);
    ui->mdiArea->addSubWindow(sw_subwindow2);

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
