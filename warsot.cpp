#include "warsot.h"
#include "ui_warsot.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>
warsot::warsot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warsot)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setFixedSize(minimumSize());
    this->setWindowTitle("СТО");
    QGridLayout *layout = new QGridLayout(this);
    idLab = new QLabel("Выберете id сотрудника:");
    idcom = new QComboBox;
    add = new QPushButton("Добавить сотрудника");
    add->setCursor(Qt::PointingHandCursor);
    idcom->setFixedWidth(250);
    layout->addWidget(idLab);
    layout->addWidget(idcom);
    layout->addWidget(add);
    QSqlQuery q1("SELECT id,фио FROM сотрудники");
    while(q1.next()) idcom->addItem(q1.value("фио").toString(),q1.value("id"));
    connect(add,&QPushButton::clicked,this,[=]{
        QString id = idcom->currentData().toString();
        QSqlQuery add;
        add.prepare("INSERT INTO `сотрудники_гарантии`(`id_менеджера`) VALUES (?)");
        add.addBindValue(id);
        if(add.exec()) {
            QMessageBox::information(this,"СТО","Запись добавлена");
            emit warsotAddded();
        }
    });

}
warsot::~warsot()
{
    delete ui;
}
