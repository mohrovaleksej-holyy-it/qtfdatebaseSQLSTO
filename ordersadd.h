#ifndef ORDERSADD_H
#define ORDERSADD_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>

namespace Ui {
class ordersadd;
}

class ordersadd : public QWidget
{
    Q_OBJECT

public:
    explicit ordersadd(QWidget *parent = nullptr);
    ~ordersadd();
    void updateall();
signals:
    void ordersAdded();

private:
    Ui::ordersadd *ui;

    QComboBox *cbCl;
    QComboBox *cbSt;
    QComboBox *cbSer;
    QLineEdit *zaloba;
    QLineEdit *status;
    QLabel *clientLabel;
    QLabel *staffLabel;
    QLabel *serviceLabel;
    QLabel *zalobaLabel;
    QLabel *statusLabel;
    QPushButton *add;    
};

#endif // ORDERSADD_H
