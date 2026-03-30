#ifndef CLIENTADD_H
#define CLIENTADD_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class clientadd;
}

class clientadd : public QWidget
{
    Q_OBJECT

public:
    explicit clientadd(QWidget *parent = nullptr);
    ~clientadd();

signals:
    void clientAdded();    

private:
    Ui::clientadd *ui;
    QPushButton *addclient;
    QLabel *fio;
    QLabel *number;
    QLabel *svaz;
    QLabel *zametki;
    QLabel *marka;
    QLabel *model;
    QLabel *year;
    QLineEdit *fio1;
    QLineEdit *number1;
    QLineEdit *svaz1;
    QLineEdit *zametki1;
    QLineEdit *marka1;
    QLineEdit *model1;
    QLineEdit *year1;
};

#endif // CLIENTADD_H
