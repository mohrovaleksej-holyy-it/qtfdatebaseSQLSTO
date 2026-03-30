#ifndef SPARAPARTSADD_H
#define SPARAPARTSADD_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class Sparapartsadd;
}

class Sparapartsadd : public QWidget
{
    Q_OBJECT

public:
    explicit Sparapartsadd(QWidget *parent = nullptr);
    ~Sparapartsadd();
signals:
    void spareAdded();
private:
    Ui::Sparapartsadd *ui;
    QLabel *nazvanie;
    QLabel *category;
    QLabel *price;
    QLabel *sellprice;
    QLabel *kolvo;
    QLabel *post;
    QLineEdit *nazvanie1;
    QLineEdit *category1;
    QLineEdit *price1;
    QLineEdit *sellprice1;
    QLineEdit *kolvo1;
    QLineEdit *post1;
    QPushButton *addzap;
    QPushButton *eventenable;
    QPushButton *eventdisable;
};

#endif // SPARAPARTSADD_H
