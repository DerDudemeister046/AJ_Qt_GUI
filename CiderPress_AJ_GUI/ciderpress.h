#ifndef CIDERPRESS_H
#define CIDERPRESS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CiderPress; }
QT_END_NAMESPACE

class CiderPress : public QMainWindow
{
    Q_OBJECT

public:
    CiderPress(QWidget *parent = nullptr);
    ~CiderPress();

private:
    Ui::CiderPress *ui;
};
#endif // CIDERPRESS_H
