#include "warrantyrepairsadd.h"
#include "ui_warrantyrepairsadd.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>
warrantyrepairsadd::warrantyrepairsadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warrantyrepairsadd)
{
    ui->setupUi(this);
    warrantyrepairsadd::setWindowModality(Qt::ApplicationModal);
    warrantyrepairsadd::setFixedSize(minimumSize());
    warrantyrepairsadd::setWindowTitle("Гарантия");
    QGridLayout *layoutadd = new QGridLayout(this);
    idz = new QLabel("Выберете заказ:");
    idm = new QLabel("Выберете фио менеджера:");
    ids = new QLabel("Выберете возможный случай:");
    idz1 = new QComboBox;
    idm1 = new QComboBox;
    ids1 = new QComboBox;
    add = new QPushButton("Добавить");
    add->setCursor(Qt::PointingHandCursor);
    layoutadd->addWidget(idz,1,0);
    layoutadd->addWidget(idz1,1,1);
    layoutadd->addWidget(idm,2,0);
    layoutadd->addWidget(idm1,2,1);
    layoutadd->addWidget(ids,3,0);
    layoutadd->addWidget(ids1,3,1);
    layoutadd->addWidget(add,4,0,1,2);
    updateall();
    connect(add,&QPushButton::clicked,this,[=]{
       QString idz2 = idz1->currentData().toString();
       QString idm2 = idm1->currentData().toString();
       QString ids2 = ids1->currentData().toString();
       QSqlQuery zapadd;
       zapadd.prepare("INSERT INTO `гарантия_по_ремонтам`(`id_заказа`,`мастер_по_гарантии_id`,`id_возможного_случая`) VALUES(?,?,?)");
       zapadd.addBindValue(idz2);
       zapadd.addBindValue(idm2);
       zapadd.addBindValue(ids2);
       if(zapadd.exec()){
           QMessageBox::information(this,"СТО","Запись добавлена");
           emit warrepAddded();
       }
    });
}
void warrantyrepairsadd::updateall(){
    QSqlQuery q1("SELECT id, Услуга_в_заказе FROM заказы");
    while(q1.next()){ idz1->addItem(q1.value("Услуга_в_заказе").toString(),q1.value("id")); }
    QSqlQuery q2("SELECT id, фио_менеджера_по_гарантии FROM сотрудники_гарантии");
    while(q2.next()){ idm1->addItem(q2.value("фио_менеджера_по_гарантии").toString(),q2.value("id")); }
    QSqlQuery q3("SELECT id, описание,Гарантийный_случай FROM Гарантийные_случаи");
    while(q3.next()){
        QString text = q3.value("описание").toString() + "(" + q3.value("Гарантийный_случай").toString() + ")";
        ids1->addItem(text,q3.value("id"));
    }
}
warrantyrepairsadd::~warrantyrepairsadd()
{
    delete ui;
}
