#ifndef UPLOADS_WIDGET_H
#define UPLOADS_WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QAbstractItemModel> // For creating Table View item
#include <QDebug>
#include "corecommunicator.h"
#include "xmlinterpreter.h"

namespace Ui {
class Uploads_Widget;
}

class Uploads_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Uploads_Widget(QWidget *parent = nullptr);
    ~Uploads_Widget();

    void addRoot(QString name, QString description, QString status);
    void addChild(QTreeWidgetItem *parent, QString name, QString description, QString status);
private slots:
    void on_getList_btn_clicked();

private:
    Ui::Uploads_Widget *ui;
    CoreCommunicator *corecom;
};

#endif // UPLOADS_WIDGET_H
