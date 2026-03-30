#include "partsalesadd.h"
#include <QSqlError>
#include "ui_partsalesadd.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>

Partsalesadd::Partsalesadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Partsalesadd)
{
    ui->setupUi(this);
    this->setWindowTitle("СТО");
    Partsalesadd::setWindowModality(Qt::ApplicationModal);
    Partsalesadd::setFixedSize(minimumSize());
    QGridLayout *layoutadd = new QGridLayout(this);
    idz = new QLabel("id запчасти:");
    kolvo = new QLabel("Количество:");
    idz1 = new QComboBox;
    kolvo1 = new QLineEdit;
    add = new QPushButton("Добавить");
    add->setCursor(Qt::PointingHandCursor);
    layoutadd->addWidget(idz,1,0);
    layoutadd->addWidget(idz1,1,1);
    layoutadd->addWidget(kolvo,2,0);
    layoutadd->addWidget(kolvo1,2,1);
    layoutadd->addWidget(add,3,0,1,2);
    updateall();
    connect(add,&QPushButton::clicked,this,[=]{
       QString idz2 = idz1->currentData().toString();
       QString kolvo2 = kolvo1->text();
       if(kolvo2.isEmpty()) QMessageBox::warning(this,"СТО","Введите количество запчастей");
       QSqlQuery zapadd;
       zapadd.prepare("INSERT INTO `продажа_запчастей`(`запчасти_id`,`количество`) VALUES (?,?)");
       zapadd.addBindValue(idz2);
       zapadd.addBindValue(kolvo2);
       if(zapadd.exec()){
           QMessageBox::information(this,"СТО","Запись добавлена!");
           emit PartsalesAdded();           
           kolvo1->clear();
       }
    });
}
void Partsalesadd::updateall(){
    QSqlQuery q1("SELECT id,название FROM запчасти");
    while(q1.next()){ idz1->addItem(q1.value("название").toString(),q1.value("id")); }
}
Partsalesadd::~Partsalesadd()
{
    delete ui;
}
