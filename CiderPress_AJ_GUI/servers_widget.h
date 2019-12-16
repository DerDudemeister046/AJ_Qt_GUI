#ifndef SERVERS_WIDGET_H
#define SERVERS_WIDGET_H

#include <QWidget>
#include "corecommunicator.h"
#include "xmlinterpreter.h"

namespace Ui {
class Servers_Widget;
}

class Servers_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Servers_Widget(QWidget *parent = nullptr);
    ~Servers_Widget();

    void updateServers();
private:
    Ui::Servers_Widget *ui;
    CoreCommunicator *corecom;
    XMLInterpreter *xmlInterpreter;
};

#endif // SERVERS_WIDGET_H
