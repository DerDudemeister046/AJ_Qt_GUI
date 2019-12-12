#ifndef LOGININFO_H
#define LOGININFO_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPalette>
#include <QImageReader>
#include <QPixmap>

class LoginInfo : public QWidget
{
    Q_OBJECT
public:
    explicit LoginInfo(QWidget *parent = nullptr);
private:
    QLineEdit *echoLineEdit;
    QLineEdit *validatorLineEdit;
    QLineEdit *alignmentLineEdit;
    QLineEdit *inputMaskLineEdit;
    QLineEdit *accessLineEdit;

signals:

public slots:
};

#endif // LOGININFO_H
