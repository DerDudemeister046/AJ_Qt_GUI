#ifndef DOWNLOADS_WIDGET_H
#define DOWNLOADS_WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QAbstractItemModel> // For creating Table View item
#include <QDebug>
#include "corecommunicator.h"
#include "xmlinterpreter.h"


namespace Ui {
class Downloads_Widget;
}

class Downloads_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Downloads_Widget(QWidget *parent = nullptr);
    ~Downloads_Widget();

    void addRoot(QString name, QString description, QString status);
    void addChild(QTreeWidgetItem *parent, QString name, QString description, QString status);
private slots:
    void on_getList_btn_clicked();

private:
    Ui::Downloads_Widget *ui;
    CoreCommunicator *corecom;
};

#endif // DOWNLOADS_WIDGET_H
