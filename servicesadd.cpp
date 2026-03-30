#include "servicesadd.h"
#include "ui_servicesadd.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>

Servicesadd::Servicesadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Servicesadd)
{
    ui->setupUi(this);
    Servicesadd::setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("СТО");
    Servicesadd::setFixedSize(minimumSize());
    QGridLayout *layoutServicesadd = new QGridLayout(this);
    addservices = new QPushButton("Добавить услугу");
    addservices->setCursor(Qt::PointingHandCursor);
    nazv = new QLabel("Название услуги:");
    opis = new QLabel("Описание:");
    price = new QLabel("Цена:");
    nazv1 = new QLineEdit;
    opis1 = new QLineEdit;
    pric1 = new QLineEdit;
    pric1->setFixedWidth(200);
    layoutServicesadd->addWidget(nazv,0,0);
    layoutServicesadd->addWidget(nazv1,0,1);
    layoutServicesadd->addWidget(opis,1,0);
    layoutServicesadd->addWidget(opis1,1,1);
    layoutServicesadd->addWidget(price,2,0);
    layoutServicesadd->addWidget(pric1,2,1);
    layoutServicesadd->addWidget(addservices,3,0,1,2);
    connect(addservices,&QPushButton::clicked,this,[=]{
       QString nazv2 = nazv1->text();
       if(nazv2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите название");
       QString opis2 = opis1->text();
       if(opis2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите описание");
       QString pric2 = pric1->text();
       if(pric2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите цену");
       QSqlQuery zaprosadd;
       zaprosadd.prepare("INSERT INTO `услуги`(`название`,`описание`,`стоимость`) VALUES (?,?,?)");
       zaprosadd.addBindValue(nazv2);
       zaprosadd.addBindValue(opis2);
       zaprosadd.addBindValue(pric2);
       if(zaprosadd.exec()){
           QMessageBox::information(this,"СТО","Запись добавлена");
           emit servicesAdded();
           nazv1->clear();
           opis1->clear();
           pric1->clear();
       }
    });
}

Servicesadd::~Servicesadd()
{
    delete ui;
}
