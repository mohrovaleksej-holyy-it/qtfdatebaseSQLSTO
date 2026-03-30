#ifndef REVIEWS_H
#define REVIEWS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
namespace Ui {
class reviews;
}

class reviews : public QWidget
{
    Q_OBJECT

public:
    explicit reviews(QWidget *parent = nullptr);
    ~reviews();
    void updateall();
signals:
    void revAdded();

private:
    Ui::reviews *ui;
    QPushButton *addreviews;

    QLineEdit *id_orders1;
    QComboBox *fio_client1;
    QLineEdit *ball1;
    QLineEdit *Reviews1;
    QLineEdit *DataReviews1;
    QLabel *id_orders;
    QLabel *fio_client;
    QLabel *ball;
    QLabel *Reviews;
    QLabel *DataReviews;

};

#endif // REVIEWS_H
