#ifndef PARTSALESADD_H
#define PARTSALESADD_H

#include "qcombobox.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class Partsalesadd;
}

class Partsalesadd : public QWidget
{
    Q_OBJECT

public:
    explicit Partsalesadd(QWidget *parent = nullptr);
    ~Partsalesadd();
    void updateall();
signals:
    void PartsalesAdded();
private:
    Ui::Partsalesadd *ui;
    QLabel *idz;
    QLabel *kolvo;
    QComboBox *idz1;
    QLineEdit *kolvo1;
    QPushButton *add;
};

#endif // PARTSALESADD_H
