#ifndef VIEWTABLESTO_H
#define VIEWTABLESTO_H

#include <QWidget>
#include <QTabWidget>
namespace Ui {
class viewtablesto;
}

class viewtablesto : public QWidget
{
    Q_OBJECT

public:
    explicit viewtablesto(QWidget *parent = nullptr);
    ~viewtablesto();

private:
    Ui::viewtablesto *ui;
    QTabWidget *tabwidget;
};

#endif // VIEWTABLESTO_H
