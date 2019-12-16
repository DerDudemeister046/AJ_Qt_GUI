#ifndef SERVERS_WIDGET_H
#define SERVERS_WIDGET_H

#include <QWidget>

namespace Ui {
class Servers_Widget;
}

class Servers_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Servers_Widget(QWidget *parent = nullptr);
    ~Servers_Widget();

private:
    Ui::Servers_Widget *ui;
};

#endif // SERVERS_WIDGET_H
