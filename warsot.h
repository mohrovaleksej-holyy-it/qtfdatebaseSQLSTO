#ifndef WARSOT_H
#define WARSOT_H

#include <QComboBox>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class warsot;
}

class warsot : public QWidget
{
    Q_OBJECT

public:
    explicit warsot(QWidget *parent = nullptr);
    ~warsot();
signals:
    void warsotAddded();
private:
    Ui::warsot *ui;
    QLabel *idLab;
    QComboBox *idcom;
    QPushButton *add;
};

#endif // WARSOT_H
