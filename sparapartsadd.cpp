#include "sparapartsadd.h"
#include "ui_sparapartsadd.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlQuery>
Sparapartsadd::Sparapartsadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sparapartsadd)
{
    ui->setupUi(this);
    Sparapartsadd::setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("СТО");
    Sparapartsadd::setFixedSize(minimumSize());
    QGridLayout *addspara = new QGridLayout(this);
    nazvanie = new QLabel("Название:");
    category = new QLabel("Категория:");
    price = new QLabel("Цена закупки:");
    sellprice = new QLabel("Цена продажи:");
    kolvo = new QLabel("Количество:");
    post = new QLabel("Поставщик:");
    nazvanie1 = new QLineEdit;
    category1 = new QLineEdit;
    price1 = new QLineEdit;
    sellprice1 = new QLineEdit;
    kolvo1 = new QLineEdit;
    post1 = new QLineEdit;   
    addzap = new QPushButton("Добавить запчасть");
    eventenable = new QPushButton("Включить событие на добавление запчастей");
    eventdisable = new QPushButton("Отключить событие на добавление запчастей");
    addzap->setCursor(Qt::PointingHandCursor);
    addspara->addWidget(nazvanie,0,0);
    addspara->addWidget(nazvanie1,0,1);
    addspara->addWidget(category,1,0);
    addspara->addWidget(category1,1,1);
    addspara->addWidget(price,2,0);
    addspara->addWidget(price1,2,1);
    addspara->addWidget(sellprice,3,0);
    addspara->addWidget(sellprice1,3,1);
    addspara->addWidget(kolvo,4,0);
    addspara->addWidget(kolvo1,4,1);
    addspara->addWidget(post,5,0);
    addspara->addWidget(post1,5,1);
    addspara->addWidget(addzap,6,0,1,2);
    addspara->addWidget(eventenable,7,0);
    addspara->addWidget(eventdisable,7,1);
    connect(eventenable,&QPushButton::clicked,this,[=]{
       QSqlQuery eventenable;
       eventenable.prepare("ALTER EVENT zakupka ENABLE");
       if(eventenable.exec()) QMessageBox::information(this,"СТО","Событие включено");
    });
    connect(eventdisable,&QPushButton::clicked,this,[=]{
       QSqlQuery eventdisable;
       eventdisable.prepare("ALTER EVENT zakupka DISABLE");
       if(eventdisable.exec()) QMessageBox::information(this,"СТО","Событие выключено");

    });
    connect(addzap,&QPushButton::clicked,this,[=]{
       QString nazvanie2 = nazvanie1->text();
       if(nazvanie2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите название");
       QString category2 = category1->text();
       if(category2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите категорию");
       QString price2 = price1->text();
       if(price2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите цену закупки");
       QString sellprice2 = sellprice1->text();
       if(sellprice2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите цену продажи");
       QString kolvo2 = kolvo1->text();
       if(kolvo2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите колиичество");
       QString post2 = post1->text();
       if(post2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите поставщика");
       QSqlQuery zaprosadd;
       zaprosadd.prepare("INSERT INTO `запчасти`(`название`,`категория`,`цена_закупки`,`цена_продажи`,`количество_на_складе`,`поставщик`) VALUES (?,?,?,?,?,?)");
       zaprosadd.addBindValue(nazvanie2);
       zaprosadd.addBindValue(category2);
       zaprosadd.addBindValue(price2);
       zaprosadd.addBindValue(sellprice2);
       zaprosadd.addBindValue(kolvo2);
       zaprosadd.addBindValue(post2);
       if(zaprosadd.exec()){
           QMessageBox::information(this,"СТО","Запись добавлена");
           emit spareAdded();
           nazvanie1->clear();
           category1->clear();
           price1->clear();
           sellprice1->clear();
           kolvo1->clear();
           post1->clear();
       }
    });
}

Sparapartsadd::~Sparapartsadd()
{
    delete ui;
}
