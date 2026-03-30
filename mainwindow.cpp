#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QFile>
#include <QFileDialog>
#include <QDate>
#include <QtCharts/QtCharts>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("СТО(рабочее окно)");
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QGridLayout *mainlayout = new QGridLayout(central);
    tabwidget = new QTabWidget;
    mainlayout->addWidget(tabwidget);

    clientadd *client = new clientadd; //инц таблиц
    Staffadd *staff = new Staffadd;
    warrantycasesadd *warcase = new warrantycasesadd;
    warrantyrepairsadd *warrep = new warrantyrepairsadd;
    Sparapartsadd *sparepart = new Sparapartsadd;
    Partsalesadd *partsales = new Partsalesadd;
    Servicesadd *servic = new Servicesadd;
    ordersadd *order = new ordersadd;
    reviews *review = new reviews;
    WorkShuduleadd *workshudule = new WorkShuduleadd;
    warsot *warsotWindow = new warsot;
    rempogar *remrag = new rempogar;
    infobase *infoform = new infobase;
    viewtablesto *checkform = new viewtablesto;

    struct tablecfg {
        QString tablename; // порядок для заполнения вертора 1.имя таблицы 2.нейм вкладки 3.для поиска 4.для удаления 5-7. нейм кнопиков 8. ширинка 9.формы таблиц для добавления и сигнала
        QString tabname;
        QString searchfield;
        QString deletefield;
        QString addbut;
        QString deletebut;
        QString searchbut;
        QVector<int> columnWidths;
        QWidget *openform;
    };

    QVector<QSqlTableModel*> allmodels; //виктор для сигналиков
    QVector<tablecfg> cfg { //виктор основной настройка приложения  и всего в целом
        {"клиенты",              "клиенты",               "фио",      "фио",      "Добавить клиента",    "Удалить клиента",    "Найти клиента",    {10,350,200,250,450,200,200,160},        client},
        {"сотрудники",           "сотрудники",           "фио",      "фио",      "Добавить сотрудника", "Удалить сотрудника", "Найти сотрудника", {10,550,460,400,400},                     staff},
        {"сотрудники_гарантии",  "сотрудники_гарантии",   "id",       "id",       "Добавить сотрудника", "Удалить сотрудника", "Найти сотрудника", {560,560,750},                     warsotWindow},
        {"услуги",               "услуги",                "название", "название", "Добавить запись",     "Удалить запись",     "Найти запись",     {10,350,1370,100},                       servic},
        {"заказы",               "заказы",                "id",       "id",       "Добавить запись",     "Удалить запись",     "Найти запись",     {10,10,10,10,450,600,70,100,100,200,200}, order},
        {"гарантийные_случаи",   "гарантийные_случаи",    "id",       "id",       "Добавить случай",     "Удалить случай",     "Найти случай",     {10,500,600,400,315},                   warcase},
        {"ремонт_по_гарантии",   "ремонт_по_гарантии",    "id",       "id",       "Добавить запись",     "Удалить запись",     "Найти запись",     {10,10,605,570,600},                     remrag},
        {"гарантия_по_ремонтам", "гарантия_по_ремонтам",  "id",       "id",       "Добавить запись",     "Удалить запись",     "Найти запись",     {10,10,10,10,280,920,200,100,100},       warrep},
        {"запчасти",             "запчасти",              "название", "название", "Добавить запись",     "Удалить запись",     "Найти запись",     {10,440,450,150,150,300,310},         sparepart},
        {"продажа_запчастей",    "продажа_запчастей",     "id",       "id",       "Добавить запись",     "Удалить запись",     "Найти запись",     {165,160,500,345,340,350},            partsales},
        {"отзывы",               "отзывы",                "id",       "id",       "Добавить запись",     "Удалить запись",     "Найти запись",     {10,10,450,55,890,400},                  review},
        {"график_работы",        "график_работы",         "id",       "id",       "Добавить запись",     "Удалить запись",     "Найти запись",     {380,380,650,222,222},              workshudule}
    };

    QPushButton *infobtn = new QPushButton("Общая информация о базе");
    infobtn->setCursor(Qt::PointingHandCursor);
    QPushButton *updbtn = new QPushButton("Обновить таблицы");
    updbtn->setCursor(Qt::PointingHandCursor);
    mainlayout->addWidget(infobtn);
    mainlayout->addWidget(updbtn);

    for(const auto &tablica : cfg) {                 //цикл кароче принимает виктора кфг и ставит ему нейм таблиса по ссылке
        QWidget *page = new QWidget;                 //просто окошко внутри окна
        QGridLayout *layout = new QGridLayout(page); //лай внутри виджета

        QSqlTableModel *model = new QSqlTableModel;
        allmodels.append(model);

        QTableView *table = new QTableView(page); //впиндюривание вкладок и таблиц
        model->setTable(tablica.tablename);
        model->select();
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        table->setModel(model);
        table->verticalHeader()->setVisible(false);
        for(int i = 0; i < tablica.columnWidths.size(); i++) table->setColumnWidth(i, tablica.columnWidths[i]); //принимаем колумевидтхс и ставим по индексу табличек

        QLineEdit *linedit = new QLineEdit; // красиво можно
        linedit->setCursor(Qt::IBeamCursor);
        linedit->setPlaceholderText("Введите " + tablica.searchfield + " для поиска || удаления");
        QPushButton *addbtn = new QPushButton(tablica.addbut, page);
        addbtn->setCursor(Qt::PointingHandCursor);
        QPushButton *delbtn = new QPushButton(tablica.deletebut, page);
        delbtn->setCursor(Qt::PointingHandCursor);
        QPushButton *searbtn = new QPushButton(tablica.searchbut, page);
        searbtn->setCursor(Qt::PointingHandCursor);
        QPushButton *savebtn = new QPushButton("Экспортировать данные в txt файл", page);
        savebtn->setCursor(Qt::PointingHandCursor);

        layout->addWidget(table,0,0,1,3); // можно а зачем
        layout->addWidget(linedit,1,0);
        layout->addWidget(delbtn,1,1);
        layout->addWidget(searbtn,1,2);
        layout->addWidget(addbtn,2,0,1,3);
        layout->addWidget(savebtn,3,0,1,0);
        tabwidget->addTab(page,tablica.tabname);

        connect(updbtn,&QPushButton::clicked,this,[=]{ model->select(); }); //upd всех таблиц хз зачем пусть будет
        connect(delbtn, &QPushButton::clicked, this, [=]{ //пашел нафик удален
            QString val = linedit->text();
            if(val.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите данные.");
            QSqlQuery zapros;
            zapros.prepare("DELETE FROM `" + tablica.tablename + "` WHERE `" + tablica.deletefield + "` = ?");
            zapros.addBindValue(val);
            if(zapros.exec()){
                if(zapros.numRowsAffected() > 0) { //если что то похожее больше чем нолик
                    QMessageBox::information(this,"СТО","Запись успешно удалена");
                    linedit->clear();
                    model->select();
                    emit deleteupdate(tablica.tablename);
                } else QMessageBox::warning(this,"СТО","Запись не найдена");
            }
        });
        connect(searbtn, &QPushButton::clicked, this, [=]{ // поиск на фильтре по сходству
            QString val = linedit->text();
            if (val.isEmpty()) model->setFilter("");
            QString inj = val;
            inj.replace("'", "''");
            model->setFilter(tablica.searchfield + " LIKE '%" + inj + "%'");
        });
        if(tablica.openform) connect(addbtn, &QPushButton::clicked, this, [=]{ tablica.openform->show(); }); //блин страшно
        connect(savebtn, &QPushButton::clicked, this, [=]{
            QString filepath = "D:/qt/qt/STO2 ТАБЛИЦЫ/" + tablica.tabname;     //указваем путь куда будем сохранять файл
            QString filen = QFileDialog::getSaveFileName(this, "Сохранить файл", filepath + "/" + tablica.tabname + QDate::currentDate().toString(" dd.MM.yyyy") + ".txt", "(*.txt)");  //формат путь текста настройка
            QFile file(filen);                                                 //настроили и передает настройку в куфайл(дичь для сохранения)
            if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;     //позволяем только записывать
            QTextStream out(&file);                                            //привязываеи фигню для записи к файлу по ссылке
            for(int r = 0; r < model->rowCount(); r++){                        //начинается ходка по строкам
                QString line;
                for(int c = 0; c < model->columnCount(); c++){                 //проходка по текущим столбам в строке
                    line += model->data(model->index(r,c)).toString();         //передача по индексам и преобразование в строук
                    if(c < model->columnCount()) line += " | ";                //проверка кароче на последний индекс в символе что бы перейти на новую если буква последняя ставит палку
                }
                out << line << "\n";                                           //переход на новую строку после окончание индексов в строке
            }
            file.close();                                                      // открыть файл
            QMessageBox::information(this,"СТО","файл сохранен по пути: " + filepath);
        });
    }
    connect(infobtn,&QPushButton::clicked,this,[=]{ infoform->show(); });

    QPushButton *viewtable = new QPushButton("Чистый просмотр таблиц");
    mainlayout->addWidget(viewtable);
    connect(viewtable,&QPushButton::clicked,this,[=]{checkform->show(); });

    if(allmodels.size() > 0) connect(client,      &clientadd::clientAdded,          this, [=] { allmodels[0]  -> select(); });
    if(allmodels.size() > 1) connect(staff,       &Staffadd::staffAdded,            this, [=] { allmodels[1]  -> select(); });
    if(allmodels.size() > 2) connect(warsotWindow,&warsot::warsotAddded,            this, [=] { allmodels[2]  -> select(); });
    if(allmodels.size() > 3) connect(servic,      &Servicesadd::servicesAdded,      this, [=] { allmodels[3]  -> select(); });
    if(allmodels.size() > 4) connect(order,       &ordersadd::ordersAdded,          this, [=] { allmodels[4]  -> select(); });
    if(allmodels.size() > 5) connect(warcase,     &warrantycasesadd::warcasesadded, this, [=] { allmodels[5]  -> select(); });
    if(allmodels.size() > 6) connect(remrag,      &rempogar::rempogarAddded,        this, [=] { allmodels[6]  -> select(); });
    if(allmodels.size() > 7) connect(warrep,      &warrantyrepairsadd::warrepAddded,this, [=] { allmodels[7]  -> select(); });
    if(allmodels.size() > 8) connect(sparepart,   &Sparapartsadd::spareAdded,       this, [=] { allmodels[8]  -> select(); });
    if(allmodels.size() > 9) connect(partsales,   &Partsalesadd::PartsalesAdded,    this, [=] { allmodels[9]  -> select(); });
    if(allmodels.size() > 10)connect(review,      &reviews::revAdded,               this, [=] { allmodels[10] -> select(); });
    if(allmodels.size() > 11)connect(workshudule, &WorkShuduleadd::worksAdded,      this, [=] { allmodels[11] -> select(); });

    connect(client,&clientadd::clientAdded,order,&ordersadd::updateall); // Обновление комбобоксов после добавления в связанных таблицах
    connect(staff,&Staffadd::staffAdded,order,&ordersadd::updateall);
    connect(servic,&Servicesadd::servicesAdded,order,&ordersadd::updateall);
    connect(order,&ordersadd::ordersAdded,warrep,&warrantyrepairsadd::updateall);
    connect(warsotWindow,&warsot::warsotAddded,warrep,&warrantyrepairsadd::updateall);
    connect(warcase,&warrantycasesadd::warcasesadded,warrep,&warrantyrepairsadd::updateall);
    connect(order,&ordersadd::ordersAdded,remrag,&rempogar::updateall);
    connect(sparepart,&Sparapartsadd::spareAdded,partsales,&Partsalesadd::updateall);
    connect(order,&ordersadd::ordersAdded,review,&reviews::updateall);
    connect(staff,&Staffadd::staffAdded,workshudule,&WorkShuduleadd::updateall);

//    QPushButton *graphreviews = new QPushButton("Отобразить график отзывов");
//    graphreviews->setCursor(Qt::PointingHandCursor);
//    mainlayout->addWidget(graphreviews);
//    connect(graphreviews,&QPushButton::clicked,this,[=]{
//        QLineSeries *graph = new QLineSeries;
//        QPen pen;
//        pen.setColor(Qt::red);
//        pen.setWidth(2);
//        pen.setStyle(Qt::SolidLine);
//        graph->setPen(pen);
//        QSqlQuery graphrevies;
//        graphrevies.prepare("SELECT оценка, id_заказа FROM отзывы ORDER BY оценка ASC");
//        graphrevies.exec();
//        while(graphrevies.next()){
//            int x = graphrevies.value(0).toInt();
//            int y = graphrevies.value(1).toInt();
//            graph->append(x,y);
//        }
//        QChart *chort = new QChart;
//        chort->addSeries(graph);
//        chort->setTitle("график отзывов");
//        QValueAxis *x = new QValueAxis;
//        x->setTitleText("Оценка");
//        x->setLabelFormat("%d");
//        x->setRange(0,6);
//        x->setTickCount(7);
//        chort->addAxis(x, Qt::AlignBottom);
//        graph->attachAxis(x);

//        QValueAxis *y = new QValueAxis;
//        y->setTitleText("id заказа");
//        y->setTickInterval(1);
//        y->setTickCount(15);
//        y->setLabelFormat("%d");
//        chort->addAxis(y, Qt::AlignLeft);
//        graph->attachAxis(y);

//        QChartView *view = new QChartView(chort);
//        view->setRenderHint(QPainter::Antialiasing);
//        view->resize(1200,700);
//        QString path = "D:/qt/qt/STO2 ТАБЛИЦЫ/отзывы";
//        QString filepath = QFileDialog::getSaveFileName(nullptr,"Сохранить файл", path + "/график отзывов от " + QDate::currentDate().toString(" dd.MM.yyyy"), "PNG Image (*.png)");
//        if(!filepath.isEmpty()) {
//            QPixmap image = view->grab();
//            image.save(filepath);
//        }
//        view->show();
//    });
//    QPushButton *partsalesgraph = new QPushButton("Отобразить график продаж запчастей");
//    partsalesgraph->setCursor(Qt::PointingHandCursor);
//    mainlayout->addWidget(partsalesgraph);
//    connect(partsalesgraph, &QPushButton::clicked, this, [=] {
//        QLineSeries *graph = new QLineSeries;
//        QPen pen;
//        pen.setColor(Qt::red);
//        pen.setWidth(2);
//        pen.setStyle(Qt::SolidLine);
//        graph->setPen(pen);
//        QSqlQuery partgraph;
//        partgraph.prepare("SELECT цена, запчасти_id FROM продажа_запчастей ORDER BY запчасти_id ASC");
//        partgraph.exec();
//        while (partgraph.next()) {
//            int x = partgraph.value(1).toInt();
//            int y = partgraph.value(0).toInt();
//            graph->append(x, y);
//        }
//        QChart *chart = new QChart;
//        chart->addSeries(graph);
//        chart->setTitle("график продаж");

//        QValueAxis *x = new QValueAxis;
//        x->setTitleText("id запчасти");
//        x->setLabelFormat("%d");
//        x->setRange(164,271);
//        x->setTickInterval(1);
//        x->setTickCount(25);
//        chart->addAxis(x, Qt::AlignBottom);
//        graph->attachAxis(x);

//        QValueAxis *y = new QValueAxis;
//        y->setTitleText("цена");
//        y->setRange(0,70000);
//        y->setTickInterval(2000);
//        y->setMin(0);
//        y->setLabelFormat("%d");
//        y->setTickCount(20);
//        chart->addAxis(y, Qt::AlignLeft);
//        graph->attachAxis(y);

//        QChartView *view = new QChartView(chart);
//        view->setRenderHint(QPainter::Antialiasing);
//        view->resize(1200, 700);
//        QString path = "D:/qt/qt/STO2 ТАБЛИЦЫ/продажа_запчастей";
//        QString filepath = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", path + "/график прожаж от " + QDate::currentDate().toString(" dd.MM.yyyy"), "PNG Image (*.png)");
//        if(!filepath.isEmpty()){
//            QPixmap image = view->grab();
//            image.save(filepath);
//        }
//        view->show();
//    });
//    QPushButton *ordersgraph = new QPushButton("Отобразить график выполненых заказов ");
//    ordersgraph->setCursor(Qt::PointingHandCursor);
//    mainlayout->addWidget(ordersgraph);
//    connect(ordersgraph,&QPushButton::clicked,this,[=]{
//        QLineSeries *graph = new QLineSeries;
//        QPen pen;
//        pen.setColor(Qt::red);
//        pen.setWidth(2);
//        pen.setStyle(Qt::SolidLine);
//        graph->setPen(pen);
//        QSqlQuery partgraph;
//        partgraph.prepare("SELECT сотрудник_id, стоимость FROM заказы ORDER BY сотрудник_id ASC");
//        partgraph.exec();
//        while (partgraph.next()) {
//            int x = partgraph.value(0).toInt();
//            int y = partgraph.value(1).toInt();
//            graph->append(x, y);
//        }
//        QChart *chart = new QChart;
//        chart->addSeries(graph);
//        chart->setTitle("график заказов");

//        QValueAxis *x = new QValueAxis;
//        x->setTitleText("id сотрудника");
//        x->setLabelFormat("%d");
//        x->setRange(159,205);
//        x->setTickInterval(1);
//        x->setTickCount(25);
//        chart->addAxis(x, Qt::AlignBottom);
//        graph->attachAxis(x);

//        QValueAxis *y = new QValueAxis;
//        y->setTitleText("стоимость");
//        y->setRange(0,16000);
//        y->setTickInterval(2000);
//        y->setMin(0);
//        y->setLabelFormat("%d");
//        y->setTickCount(20);
//        chart->addAxis(y, Qt::AlignLeft);
//        graph->attachAxis(y);

//        QChartView *view = new QChartView(chart);
//        view->setRenderHint(QPainter::Antialiasing);
//        view->resize(1200, 700);
//        QString path = "D:/qt/qt/STO2 ТАБЛИЦЫ/заказы";
//        QString filepath = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", path + "/график заказов от " + QDate::currentDate().toString(" dd.MM.yyyy"), "PNG Image (*.png)");
//        if(!filepath.isEmpty()){
//            QPixmap image = view->grab();
//            image.save(filepath);
//        }
//        view->show();
//    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
