#ifndef CIDERPRESS_H
#define CIDERPRESS_H

#include <QMainWindow>
#include <QMdiSubWindow>

#include "xml_manager.h"

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
private:
    Ui::CiderPress *ui;
    XML_Manager *xmlManager;
};
#endif // CIDERPRESS_H
