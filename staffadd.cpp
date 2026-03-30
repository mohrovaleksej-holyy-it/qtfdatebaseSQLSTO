#include "staffadd.h"
#include "ui_staffadd.h"
#include "ui_staffadd.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

Staffadd::Staffadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Staffadd)
{
    ui->setupUi(this);
    Staffadd::setFixedSize(minimumSize());
    this->setWindowTitle("СТО");
    Staffadd::setWindowModality(Qt::ApplicationModal);
    QGridLayout *layoutrewiwsadd = new QGridLayout(this);
    addStaff = new QPushButton("Добавить сотрудника");
    addStaff->setCursor(Qt::PointingHandCursor);
    fio = new QLabel("Введите ФИО:");
    post = new QLabel("Введите должность:");
    number = new QLabel("Введите номер телефона:");
    salary = new QLabel("Оклад:");
    fio1 = new QLineEdit;
    post1 = new QLineEdit;
    number1 = new QLineEdit;
    salary1 = new QLineEdit;
    layoutrewiwsadd->addWidget(fio,1,0);
    layoutrewiwsadd->addWidget(fio1,1,1);
    layoutrewiwsadd->addWidget(post,2,0);
    layoutrewiwsadd->addWidget(post1,2,1);
    layoutrewiwsadd->addWidget(number,3,0);
    layoutrewiwsadd->addWidget(number1,3,1);
    layoutrewiwsadd->addWidget(salary,4,0);
    layoutrewiwsadd->addWidget(salary1,4,1);
    layoutrewiwsadd->addWidget(addStaff,5,0,1,2);
    fio1->setFixedWidth(200);
    connect(addStaff,&QPushButton::clicked,this,[=]{
        QString fiovvod = fio1->text();
        if(fiovvod.isEmpty())QMessageBox::warning(this,"СТО","Пожалуйста введите фио");
        QString postvvod = post1->text();
        if(postvvod.isEmpty())QMessageBox::warning(this,"СТО","Пожалуйста введите должность");
        QString numbervvod = number1->text();
        if(numbervvod.isEmpty())QMessageBox::warning(this,"СТО","Пожалуйста введите номер телефона");
        QString salaryvvod = salary1->text();
        if(salaryvvod.isEmpty())QMessageBox::warning(this,"СТО","Пожалуйста введите оклад");

        QSqlQuery zapros;
        zapros.prepare("INSERT INTO `сотрудники`(`фио`,`должность`,`телефон`,`оклад`) VALUES(?,?,?,?)");
        zapros.addBindValue(fiovvod);
        zapros.addBindValue(postvvod);
        zapros.addBindValue(numbervvod);
        zapros.addBindValue(salaryvvod);
        if(zapros.exec()){
        QMessageBox::information(this,"СТО","Запись добавлена");
        emit staffAdded();
        fio1->clear();
        post1->clear();
        number1->clear();
        salary1->clear();
    }
    });
}

Staffadd::~Staffadd()
{
    delete ui;
}
