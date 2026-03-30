#ifndef SERVICESADD_H
#define SERVICESADD_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class Servicesadd;
}

class Servicesadd : public QWidget
{
    Q_OBJECT

public:
    explicit Servicesadd(QWidget *parent = nullptr);
    ~Servicesadd();
 signals:
    void servicesAdded();

private:
    Ui::Servicesadd *ui;
    QPushButton *addservices;
    QLabel *nazv;
    QLabel *opis;
    QLabel *price;
    QLineEdit *nazv1;
    QLineEdit *opis1;
    QLineEdit *pric1;
};

#endif // SERVICESADD_H
