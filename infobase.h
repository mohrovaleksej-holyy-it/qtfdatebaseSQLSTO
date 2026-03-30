#ifndef INFOBASE_H
#define INFOBASE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
namespace Ui {
class infobase;
}

class infobase : public QWidget
{
    Q_OBJECT

public:
    explicit infobase(QWidget *parent = nullptr);
    ~infobase();

private:
    Ui::infobase *ui;

    QLabel *getallinfo;
    QLabel *categoryreviews;
    QLabel *sellonday;
    QLabel *getinfostaff;
    QLabel *getfinansoviyanaliz;
    QPushButton *getinformation;
    QPushButton *saveinformation;
};

#endif // INFOBASE_H
