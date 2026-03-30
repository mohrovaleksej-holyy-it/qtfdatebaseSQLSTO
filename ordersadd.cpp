#include "ordersadd.h"
#include "ui_ordersadd.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlQuery>


ordersadd::ordersadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ordersadd)
{
    ui->setupUi(this);
    ordersadd::setFixedSize(minimumSize());
    ordersadd::setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("СТО");
    QGridLayout *addorders = new QGridLayout(this);
    cbCl = new QComboBox;
    cbSt = new QComboBox;
    cbSer = new QComboBox;
    zaloba = new QLineEdit;
    clientLabel = new QLabel("Выберете клиента:");
    staffLabel = new QLabel("Выберете сотрудника:");
    serviceLabel = new QLabel("Выберете услугу:");
    zalobaLabel = new QLabel("Жалоба:");
    add = new QPushButton("Добавить заказ");    
    add->setCursor(Qt::PointingHandCursor);
    addorders->addWidget(clientLabel,0,0);
    addorders->addWidget(cbCl,0,1);
    addorders->addWidget(staffLabel,1,0);
    addorders->addWidget(cbSt,1,1);
    addorders->addWidget(serviceLabel,2,0);
    addorders->addWidget(cbSer,2,1);
    addorders->addWidget(zalobaLabel,3,0);
    addorders->addWidget(zaloba,3,1);
    addorders->addWidget(add,4,0,1,2);
    cbCl->setFixedWidth(500);
    cbSt->setFixedWidth(500);
    cbSer->setFixedWidth(500);
    updateall();
    connect(add,&QPushButton::clicked,this,[=]{
        QString cln = cbCl->currentData().toString();
        QString stf = cbSt->currentData().toString();
        QString spr = cbSer->currentData().toString();
        QString zal = zaloba->text();
        if(zal.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите жалобу");
        QSqlQuery zaprosadd;
        zaprosadd.prepare("INSERT INTO заказы (клиент_id, сотрудник_id, id_услуги, Жалоба_просьба_клиента) VALUES (?, ?, ?, ?)");
        zaprosadd.addBindValue(cln);
        zaprosadd.addBindValue(stf);
        zaprosadd.addBindValue(spr);
        zaprosadd.addBindValue(zal);
        if(zaprosadd.exec()){
            QMessageBox::information(this,"СТО","Заказ добавлен");
            emit ordersAdded();
            zaloba->clear();
            cbCl->setCurrentIndex(0);
            cbSt->setCurrentIndex(0);
            cbSer->setCurrentIndex(0);
        }
    });
}
void ordersadd::updateall()
{
    cbCl->clear();
    QSqlQuery q1("SELECT id, фио FROM клиенты ORDER BY фио");
    while(q1.next()) cbCl->addItem(q1.value("фио").toString(), q1.value("id"));
    cbSt->clear();
    QSqlQuery q2("SELECT id, фио, должность FROM сотрудники ORDER BY фио");
    while(q2.next()) {
        QString text = q2.value("фио").toString() + " (" + q2.value("должность").toString() + ")";
        cbSt->addItem(text, q2.value("id"));
    }
    cbSer->clear();
    QSqlQuery q3("SELECT id, описание FROM услуги ORDER BY описание");
    while(q3.next()) cbSer->addItem(q3.value("описание").toString(), q3.value("id"));
}

ordersadd::~ordersadd()
{
    delete ui;
}
