#include "ciderpress.h"

#include <QApplication>
#include <QDebug>

#include "settings_widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //CiderPress w;
    //w.show();

    Settings_Widget *sw = new Settings_Widget;
    sw->show();

    return a.exec();
}
