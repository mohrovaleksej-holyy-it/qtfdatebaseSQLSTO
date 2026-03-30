#include "viewtablesto.h"
#include "ui_viewtablesto.h"
#include <QGridLayout>
#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QtCharts/QtCharts>
#include <QSqlQuery>
viewtablesto::viewtablesto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewtablesto)

{
    ui->setupUi(this);
    this->setFixedSize(1400, 800);
    this->setWindowTitle("СТО(окно просмотра)");
    struct cfg {
        QString tabwidgetname;
        QString tablename;
        QVector<int> columnWidths;
    };

    QVector<cfg> information {
        {"клиенты", "кклиенты",{350,200,250,450,200,200,160}},
        {"сотрудники", "стафф", {550,460,400,400}},
        {"сотрудники_гарантии", "стафф_гарантии", {560,560,750}},
        {"услуги", "сервись",{350,1370,100}},
        {"заказы", "заказзы",{450,600,70,100,100,200,200}},
        {"гарантийные_случаи", "случаи",{500,600,400,315}},
        {"ремонт_по_гарантии", "ремпогар",{605,570,600}},
        {"гарантия_по_ремонтам", "гарпорем",{280,920,200,100,100}},
        {"запчасти", "запики",{440,450,150,150,300,310}},
        {"продажа_запчастей", "отчетпродаж",{160,500,345,340,350}},
        {"отзывы", "отзывысто",{450,55,890,400}},
        {"график_работы", "графикиработы",{650,350,350}}
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
        for(int i = 0; i < infobase.columnWidths.size(); ++i) { view->setColumnWidth(i, infobase.columnWidths[i]);}
        layout->addWidget(view);
        tabWidget->addTab(page, infobase.tabwidgetname);
    }
    QPushButton *graphreviews = new QPushButton("Отобразить график отзывов");
        graphreviews->setCursor(Qt::PointingHandCursor);
            mainLayout->addWidget(graphreviews);
        connect(graphreviews,&QPushButton::clicked,this,[=]{
            QLineSeries *graph = new QLineSeries;
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(2);
            pen.setStyle(Qt::SolidLine);
            graph->setPen(pen);
            QSqlQuery graphrevies;
            graphrevies.prepare("SELECT оценка, id_заказа FROM отзывы ORDER BY оценка ASC");
            graphrevies.exec();
            while(graphrevies.next()){
                int x = graphrevies.value(0).toInt();
                int y = graphrevies.value(1).toInt();
                graph->append(x,y);
            }
            QChart *chort = new QChart;
            chort->addSeries(graph);
            chort->setTitle("график отзывов");
            QValueAxis *x = new QValueAxis;
            x->setTitleText("Оценка");
            x->setLabelFormat("%d");
            x->setRange(0,6);
            x->setTickCount(7);
            chort->addAxis(x, Qt::AlignBottom);
            graph->attachAxis(x);

            QValueAxis *y = new QValueAxis;
            y->setTitleText("id заказа");
            y->setTickInterval(1);
            y->setTickCount(15);
            y->setLabelFormat("%d");
            chort->addAxis(y, Qt::AlignLeft);
            graph->attachAxis(y);

            QChartView *view = new QChartView(chort);
            view->setRenderHint(QPainter::Antialiasing);
            view->resize(1200,700);
            QString path = "D:/qt/qt/STO2 ТАБЛИЦЫ/отзывы";
            QString filepath = QFileDialog::getSaveFileName(nullptr,"Сохранить файл", path + "/график отзывов от " + QDate::currentDate().toString(" dd.MM.yyyy"), "PNG Image (*.png)");
            if(!filepath.isEmpty()) {
                QPixmap image = view->grab();
                image.save(filepath);
            }
            view->show();
        });
        QPushButton *partsalesgraph = new QPushButton("Отобразить график продаж запчастей");
        partsalesgraph->setCursor(Qt::PointingHandCursor);
        mainLayout->addWidget(partsalesgraph);
        connect(partsalesgraph, &QPushButton::clicked, this, [=] {
            QLineSeries *graph = new QLineSeries;
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(2);
            pen.setStyle(Qt::SolidLine);
            graph->setPen(pen);
            QSqlQuery partgraph;
            partgraph.prepare("SELECT цена, запчасти_id FROM продажа_запчастей ORDER BY запчасти_id ASC");
            partgraph.exec();
            while (partgraph.next()) {
                int x = partgraph.value(1).toInt();
                int y = partgraph.value(0).toInt();
                graph->append(x, y);
            }
            QChart *chart = new QChart;
            chart->addSeries(graph);
            chart->setTitle("график продаж");

            QValueAxis *x = new QValueAxis;
            x->setTitleText("id запчасти");
            x->setLabelFormat("%d");
            x->setRange(164,271);
            x->setTickInterval(1);
            x->setTickCount(25);
            chart->addAxis(x, Qt::AlignBottom);
            graph->attachAxis(x);

            QValueAxis *y = new QValueAxis;
            y->setTitleText("цена");
            y->setRange(0,70000);
            y->setTickInterval(2000);
            y->setMin(0);
            y->setLabelFormat("%d");
            y->setTickCount(20);
            chart->addAxis(y, Qt::AlignLeft);
            graph->attachAxis(y);

            QChartView *view = new QChartView(chart);
            view->setRenderHint(QPainter::Antialiasing);
            view->resize(1200, 700);
            QString path = "D:/qt/qt/STO2 ТАБЛИЦЫ/продажа_запчастей";
            QString filepath = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", path + "/график прожаж от " + QDate::currentDate().toString(" dd.MM.yyyy"), "PNG Image (*.png)");
            if(!filepath.isEmpty()){
                QPixmap image = view->grab();
                image.save(filepath);
            }
            view->show();
        });
        QPushButton *ordersgraph = new QPushButton("Отобразить график выполненых заказов ");
        ordersgraph->setCursor(Qt::PointingHandCursor);
        mainLayout->addWidget(ordersgraph);
        connect(ordersgraph,&QPushButton::clicked,this,[=]{
            QLineSeries *graph = new QLineSeries;
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(2);
            pen.setStyle(Qt::SolidLine);
            graph->setPen(pen);
            QSqlQuery partgraph;
            partgraph.prepare("SELECT сотрудник_id, стоимость FROM заказы ORDER BY сотрудник_id ASC");
            partgraph.exec();
            while (partgraph.next()) {
                int x = partgraph.value(0).toInt();
                int y = partgraph.value(1).toInt();
                graph->append(x, y);
            }
            QChart *chart = new QChart;
            chart->addSeries(graph);
            chart->setTitle("график заказов");

            QValueAxis *x = new QValueAxis;
            x->setTitleText("id сотрудника");
            x->setLabelFormat("%d");
            x->setRange(159,205);
            x->setTickInterval(1);
            x->setTickCount(25);
            chart->addAxis(x, Qt::AlignBottom);
            graph->attachAxis(x);

            QValueAxis *y = new QValueAxis;
            y->setTitleText("стоимость");
            y->setRange(0,16000);
            y->setTickInterval(2000);
            y->setMin(0);
            y->setLabelFormat("%d");
            y->setTickCount(20);
            chart->addAxis(y, Qt::AlignLeft);
            graph->attachAxis(y);

            QChartView *view = new QChartView(chart);
            view->setRenderHint(QPainter::Antialiasing);
            view->resize(1200, 700);
            QString path = "D:/qt/qt/STO2 ТАБЛИЦЫ/заказы";
            QString filepath = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", path + "/график заказов от " + QDate::currentDate().toString(" dd.MM.yyyy"), "PNG Image (*.png)");
            if(!filepath.isEmpty()){
                QPixmap image = view->grab();
                image.save(filepath);
            }
            view->show();
        });
}

viewtablesto::~viewtablesto()
{
    delete ui;
}
