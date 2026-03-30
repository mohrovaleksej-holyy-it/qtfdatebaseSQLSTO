#include "rempogar.h"
#include "ui_rempogar.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>
rempogar::rempogar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rempogar)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setFixedSize(minimumSize());
    this->setWindowTitle("СТО");
    QGridLayout *layout = new QGridLayout(this);
    idLab = new QLabel("Выберете id выданной гарантии:");
    idcom = new QComboBox;
    problemaLab = new QLabel("Выберете описание проблемы");
    problema = new QLineEdit;
    add = new QPushButton("Добавить");
    add->setCursor(Qt::PointingHandCursor);
    idcom->setFixedWidth(250);
    layout->addWidget(idLab);
    layout->addWidget(idcom);
    layout->addWidget(problemaLab);
    layout->addWidget(problema);
    layout->addWidget(add);
    updateall();
    connect(add,&QPushButton::clicked,this,[=]{
        QString probl = problema->text();
        QString id = idcom->currentData().toString();
        QSqlQuery add;
        add.prepare("INSERT INTO `ремонт_по_гарантии`(`id_выданной_гарантии`,`описание_проблемы`) VALUES (?,?)");
        add.addBindValue(id);
        add.addBindValue(probl);
        if(add.exec()) {
            QMessageBox::information(this,"СТО","Запись добавлена");
            problema->clear();
            emit rempogarAddded();
        }
    });
}
void rempogar::updateall(){
    QSqlQuery q1("SELECT id,Заказ_описание FROM гарантия_по_ремонтам");
    while(q1.next()) idcom->addItem(q1.value("Заказ_описание").toString(),q1.value("id"));
}
rempogar::~rempogar()
{
    delete ui;
}
