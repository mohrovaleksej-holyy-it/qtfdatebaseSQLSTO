#ifndef WARRANTYREPAIRSADD_H
#define WARRANTYREPAIRSADD_H

#include <QComboBox>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class warrantyrepairsadd;
}

class warrantyrepairsadd : public QWidget
{
    Q_OBJECT

public:
    explicit warrantyrepairsadd(QWidget *parent = nullptr);
    ~warrantyrepairsadd();
    void updateall();
signals:
    void warrepAddded();

private:
    Ui::warrantyrepairsadd *ui;
    QLabel *idz;
    QLabel *idm;
    QLabel *ids;
    QComboBox *idz1;
    QComboBox *idm1;
    QComboBox *ids1;
    QPushButton *add;
};

#endif // WARRANTYREPAIRSADD_H
