#include "workshuduleadd.h"
#include "ui_workshuduleadd.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlQuery>
WorkShuduleadd::WorkShuduleadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkShuduleadd)
{
    ui->setupUi(this);
    this->setWindowTitle("СТО");
    WorkShuduleadd::setFixedSize(minimumSize());
    WorkShuduleadd::setWindowModality(Qt::ApplicationModal);
    WorkShuduleadd::setWindowTitle("Добавить график для сотрудника");
    QGridLayout *addlayout = new QGridLayout(this);
    add = new QPushButton("Добавить");
    add->setCursor(Qt::PointingHandCursor);
    sotid = new QLabel("ID сотрудника:");
    smena = new QLabel("Смена:");
    status = new QLabel("Статус:");
    sotid1 = new QComboBox;
    smena1 = new QComboBox;
    smena1->addItem("вечер");
    smena1->addItem("утро");
    smena1->addItem("полный");
    status1 = new QComboBox;
    status1->addItem("работает");
    status1->addItem("отпуск");
    status1->addItem("больничный");
    addlayout->addWidget(sotid,1,0);
    addlayout->addWidget(sotid1,1,1);
    addlayout->addWidget(smena,2,0);
    addlayout->addWidget(smena1,2,1);
    addlayout->addWidget(status,3,0);
    addlayout->addWidget(status1,3,1);
    addlayout->addWidget(add,4,0,1,2);
    updateall();
    connect(add,&QPushButton::clicked,this,[=]{
        QString sotid2 = sotid1->currentData().toString();
        QString smena2 = smena1->currentText();
        QString status2 = status1->currentText();
        QSqlQuery zaprosadd;
        zaprosadd.prepare("INSERT INTO `график_работы`(`сотрудник_id`,`смена`,`статус`) VALUES (?,?,?)");
        zaprosadd.addBindValue(sotid2);
        zaprosadd.addBindValue(smena2);
        zaprosadd.addBindValue(status2);
        if(zaprosadd.exec()){
            QMessageBox::information(this,"СТО","Запись создана");
            emit worksAdded();
        }
    });
}
void WorkShuduleadd::updateall(){
    QSqlQuery q1("SELECT id,фио FROM сотрудники");
    while(q1.next()) {
        QString text = q1.value("фио").toString() + " ID -" + q1.value("id").toString();
        sotid1->addItem(text, q1.value("id"));
    }
}
WorkShuduleadd::~WorkShuduleadd()
{
    delete ui;
}
