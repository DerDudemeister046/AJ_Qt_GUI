#ifndef SETTINGS_WIDGET_H
#define SETTINGS_WIDGET_H

#include <QWidget>

namespace Ui {
class Settings_Widget;
}

class Settings_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Settings_Widget(QWidget *parent = nullptr);
    ~Settings_Widget();

private:
    Ui::Settings_Widget *ui;
};

#endif // SETTINGS_WIDGET_H
