#ifndef WORKSHUDULEADD_H
#define WORKSHUDULEADD_H

#include "qcombobox.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class WorkShuduleadd;
}

class WorkShuduleadd : public QWidget
{
    Q_OBJECT

public:
    explicit WorkShuduleadd(QWidget *parent = nullptr);
    ~WorkShuduleadd();
    void updateall();
signals:
    void worksAdded();
private:
    Ui::WorkShuduleadd *ui;
    QPushButton *add;
    QLabel *sotid;
    QLabel *smena;
    QLabel *status;
    QComboBox *sotid1;
    QComboBox *smena1;
    QComboBox *status1;
};

#endif // WORKSHUDULEADD_H
