#include "clientadd.h"
#include "ui_clientadd.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>

clientadd::clientadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientadd)
{
    ui->setupUi(this);
    clientadd::setWindowModality(Qt::ApplicationModal);
    clientadd::setWindowTitle("СТО");
    clientadd::setFixedSize(minimumSize());
    QGridLayout *layoutadd = new QGridLayout(this);
    addclient = new QPushButton("Добавить клиента:");
    addclient->setCursor(Qt::PointingHandCursor);
    fio = new QLabel("Введите ФИО:");
    number = new QLabel("Введите номер:");
    svaz = new QLabel("Способ связи:");
    zametki = new QLabel("Заметки о клиенте:");
    marka = new QLabel("Марка авто:");
    model = new QLabel("Модель авто:");
    year = new QLabel("Год авто:");
    fio1= new QLineEdit;
    number1= new QLineEdit;
    svaz1= new QLineEdit;
    zametki1= new QLineEdit;
    marka1= new QLineEdit;
    model1= new QLineEdit;
    year1= new QLineEdit;
    layoutadd->addWidget(fio,1,0);
    layoutadd->addWidget(fio1,1,1);
    layoutadd->addWidget(number,2,0);
    layoutadd->addWidget(number1,2,1);
    layoutadd->addWidget(svaz,3,0);
    layoutadd->addWidget(svaz1,3,1);
    layoutadd->addWidget(zametki,4,0);
    layoutadd->addWidget(zametki1,4,1);
    layoutadd->addWidget(marka,5,0);
    layoutadd->addWidget(marka1,5,1);
    layoutadd->addWidget(model,6,0);
    layoutadd->addWidget(model1,6,1);
    layoutadd->addWidget(year,7,0);
    layoutadd->addWidget(year1,7,1);
    layoutadd->addWidget(addclient,8,0,1,2);
    fio1->setFixedWidth(500);
    connect(addclient,&QPushButton::clicked,this,[=]{

        QString fiovvod = fio1->text();
        if(fiovvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите фио");
        QString numbervvod = number1->text();
        if(numbervvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите номер");
        QString svazvvod = svaz1->text();
        if(svazvvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите способ связи");
        QString zametkivvod = zametki1->text();
        QString markavvod = marka1->text();
        if(markavvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите марку авто");
        QString modelvvod = model1->text();
        if(modelvvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите модель авто");
        QString yearvvod = year1->text();
        if(yearvvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите год авто");
        QSqlQuery zaprosadd;
        zaprosadd.prepare ("INSERT INTO `клиенты`(`фио`,`телефон`,`Способ_связи`,`Заметки`,`марка_авто`,`модель_авто`,`год_выпуска`) VALUES (?,?,?,?,?,?,?)");
        zaprosadd.addBindValue(fiovvod);
        zaprosadd.addBindValue(numbervvod);
        zaprosadd.addBindValue(svazvvod);
        zaprosadd.addBindValue(zametkivvod);
        zaprosadd.addBindValue(markavvod);
        zaprosadd.addBindValue(modelvvod);
        zaprosadd.addBindValue(yearvvod);
        if(zaprosadd.exec()){
            QMessageBox::information(this,"СТО","Запись добавлена");
            emit clientAdded();
            fio1->clear();
            number1->clear();
            svaz1->clear();
            zametki1->clear();
            marka1->clear();
            model1->clear();
            year1->clear();
        }
    });
}

clientadd::~clientadd()
{
    delete ui;
}
