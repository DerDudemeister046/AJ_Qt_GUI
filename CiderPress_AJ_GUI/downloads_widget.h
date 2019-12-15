#ifndef DOWNLOADS_WIDGET_H
#define DOWNLOADS_WIDGET_H

#include <QWidget>

namespace Ui {
class Downloads_Widget;
}

class Downloads_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Downloads_Widget(QWidget *parent = nullptr);
    ~Downloads_Widget();

private:
    Ui::Downloads_Widget *ui;
};

#endif // DOWNLOADS_WIDGET_H
