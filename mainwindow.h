#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "servicesadd.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QTabWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

#include <clientadd.h>
#include <staffadd.h>
#include <ordersadd.h>
#include <partsalesadd.h>
#include <ordersadd.h>
#include <sparapartsadd.h>
#include <warrantycasesadd.h>
#include <warrantyrepairsadd.h>
#include <workshuduleadd.h>
#include <reviews.h>
#include <warsot.h>
#include <rempogar.h>
#include <infobase.h>
#include <viewtablesto.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void deleteupdate(const QString &tablename);
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    QSqlTableModel *clientsTab;
    QSqlTableModel *part_salesTab;
    QSqlTableModel *Guaranteed_casesTab;
    QSqlTableModel *warranty_for_repairsTab;
    QSqlTableModel *work_scheduleTab;
    QSqlTableModel *ordersTab;
    QSqlTableModel *spare_partsTab;
    QSqlTableModel *reviewsTab;
    QSqlTableModel *repairment_guaranteesTab;
    QSqlTableModel *staffTab;
    QSqlTableModel *guarantee_staffersTab;
    QSqlTableModel *servicesTab;

    QTabWidget *tabwidget;
    QTableView *clients;
    QTableView *part_sales;
    QTableView *Guaranteed_cases;
    QTableView *warranty_for_repairs;
    QTableView *work_schedule;
    QTableView *orders;
    QTableView *spare_parts;
    QTableView *reviewsView;
    QTableView *repairment_guarantees;
    QTableView *staff;
    QTableView *guarantee_staffers;
    QTableView *services;

    QComboBox *Lineaddguarantee_staffers;
    QComboBox *Lineaddrepairment_guarantees;

};

#endif // MAINWINDOW_H
