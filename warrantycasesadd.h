#ifndef WARRANTYCASESADD_H
#define WARRANTYCASESADD_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class warrantycasesadd;
}

class warrantycasesadd : public QWidget
{
    Q_OBJECT

public:
    explicit warrantycasesadd(QWidget *parent = nullptr);
    ~warrantycasesadd();
signals:
    void warcasesadded();

private:
    Ui::warrantycasesadd *ui;
    QLabel *cat;
    QLabel *ops;
    QLabel *gar;
    QLabel *day;
    QLineEdit *cat1;
    QLineEdit *ops1;
    QLineEdit *gar1;
    QLineEdit *day1;
    QPushButton *add;
};

#endif // WARRANTYCASESADD_H
