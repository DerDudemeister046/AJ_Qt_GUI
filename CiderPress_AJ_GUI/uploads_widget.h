#ifndef UPLOADS_WIDGET_H
#define UPLOADS_WIDGET_H

#include <QWidget>

namespace Ui {
class uploads_widget;
}

class uploads_widget : public QWidget
{
    Q_OBJECT

public:
    explicit uploads_widget(QWidget *parent = nullptr);
    ~uploads_widget();

private:
    Ui::uploads_widget *ui;
};

#endif // UPLOADS_WIDGET_H
