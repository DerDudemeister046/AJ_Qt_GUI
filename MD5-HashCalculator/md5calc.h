#ifndef MD5CALC_H
#define MD5CALC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MD5Calc; }
QT_END_NAMESPACE

class MD5Calc : public QWidget
{
    Q_OBJECT

public:
    MD5Calc(QWidget *parent = nullptr);
    ~MD5Calc();

private:
    Ui::MD5Calc *ui;
};
#endif // MD5CALC_H
