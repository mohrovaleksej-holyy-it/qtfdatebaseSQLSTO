#include "warrantycasesadd.h"
#include "ui_warrantycasesadd.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QMessageBox>
warrantycasesadd::warrantycasesadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warrantycasesadd)
{
    ui->setupUi(this);
    warrantycasesadd::setWindowModality(Qt::ApplicationModal);
    warrantycasesadd::setFixedSize(minimumSize());
    this->setWindowTitle("СТО");
    QGridLayout *layoutadd = new QGridLayout(this);
    cat = new QLabel("Категория:");
    ops = new QLabel("Описание:");
    gar = new QLabel("Гарантия:");
    day = new QLabel("Срок (дни):");
    cat1 = new QLineEdit();
    ops1 = new QLineEdit();
    gar1 = new QLineEdit();
    day1 = new QLineEdit();
    add = new QPushButton("Добавить");
    add->setCursor(Qt::PointingHandCursor);
    layoutadd->addWidget(cat,1,0);
    layoutadd->addWidget(cat1,1,1);
    layoutadd->addWidget(ops,2,0);
    layoutadd->addWidget(ops1,2,1);
    layoutadd->addWidget(gar,3,0);
    layoutadd->addWidget(gar1,3,1);
    layoutadd->addWidget(day,4,0);
    layoutadd->addWidget(day1,4,1);
    layoutadd->addWidget(add,5,0,1,2);
    cat1->setFixedWidth(200);
    connect(add,&QPushButton::clicked,this,[=]{
        QString cat2 = cat1->text();
        if(cat2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите категорию");
        QString ops2 = ops1->text();
        if(ops2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите описание");
        QString gar2 = gar1->text();
        if(gar2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите гарантию");
        QString day2 = day1->text();
        if(day2.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите срок гарантии(дни)");
        QSqlQuery addz;
        addz.prepare("INSERT INTO `гарантийные_случаи` (`категория`,`описание`,`Гарантийный_случай`,`срок_гарантии_дни`) VALUES (?,?,?,?)");
        addz.addBindValue(cat2);
        addz.addBindValue(ops2);
        addz.addBindValue(gar2);
        addz.addBindValue(day2);
        if(addz.exec()){
            QMessageBox::information(this,"СТО","Запись добавлена");
            emit warcasesadded();
            cat1->clear();
            ops1->clear();
            gar1->clear();
            day1->clear();
        }
    });

}
warrantycasesadd::~warrantycasesadd()
{
    delete ui;
}
