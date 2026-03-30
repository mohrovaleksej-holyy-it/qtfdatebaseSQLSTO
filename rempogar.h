#ifndef REMPOGAR_H
#define REMPOGAR_H

#include <QComboBox>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class rempogar;
}

class rempogar : public QWidget
{
    Q_OBJECT

public:
    explicit rempogar(QWidget *parent = nullptr);
    ~rempogar();
    void updateall();
signals:
    void rempogarAddded();
private:
    Ui::rempogar *ui;
    QLabel *idLab;
    QLabel *problemaLab;
    QLineEdit *problema;
    QComboBox *idcom;
    QPushButton *add;
};

#endif // REMPOGAR_H
