#ifndef STAFFADD_H
#define STAFFADD_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Staffadd;
}

class Staffadd : public QWidget
{
    Q_OBJECT

public:
    explicit Staffadd(QWidget *parent = nullptr);
    ~Staffadd();
signals:
    void staffAdded();
private:
    Ui::Staffadd *ui;

    QPushButton *addStaff;
    QLabel *fio;
    QLabel *post;
    QLabel *number;
    QLabel *salary;
    QLineEdit *fio1;
    QLineEdit *post1;
    QLineEdit *number1;
    QLineEdit *salary1;
};

#endif // STAFFADD_H
