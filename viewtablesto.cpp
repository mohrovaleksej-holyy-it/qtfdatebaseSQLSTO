#include "viewtablesto.h"
#include "ui_viewtablesto.h"
#include <QGridLayout>
#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QTabWidget>
#include <QVBoxLayout>

viewtablesto::viewtablesto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewtablesto)
{
    ui->setupUi(this);  // ← переносим в начало

    struct cfg {
        QString tabwidgetname;
        QString tablename;
        QVector<int> columnWidths;
    };

    QVector<cfg> information {
        {"клиенты", "клиенты",{10,350,200,250,450,200,200,160}},
        {"сотрудники", "сотрудники", {10,550,460,400,400}},
        {"сотрудники_гарантии", "стафф_гарантии", {560,560,750}},
        {"услуги", "услуги",{10,350,1370,100}},
        {"заказы", "заказы",{10,10,10,10,450,600,70,100,100,200,200}},
        {"гарантийные_случаи", "гарантийные_случаи",{10,500,600,400,315}},
        {"ремонт_по_гарантии", "ремонт_по_гарантии",{10,10,605,570,600}},
        {"гарантия_по_ремонтам", "гарпорем",{280,920,200,100,100}},
        {"запчасти", "запчасти",{10,440,450,150,150,300,310}},
        {"продажа_запчастей", "отчетпродаж",{160,500,345,340,350}},
        {"отзывы", "отзывысто",{450,55,890,400}},
        {"график_работы", "графикиработы",{650,222,222}}
    };
    QTabWidget *tabWidget = new QTabWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
    for(const auto &infobase : information) {
        QWidget *page = new QWidget;
        QVBoxLayout *layout = new QVBoxLayout(page);

        QTableView *view = new QTableView(page);
        QSqlTableModel *model = new QSqlTableModel(this);
        model->setTable(infobase.tablename);
        model->select();
        view->setModel(model);
        view->verticalHeader()->setVisible(false);
        layout->addWidget(view);
        tabWidget->addTab(page, infobase.tabwidgetname);
    }

}

viewtablesto::~viewtablesto()
{
    delete ui;
}
