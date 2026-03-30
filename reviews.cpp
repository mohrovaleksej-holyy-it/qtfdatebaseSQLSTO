#include "reviews.h"
#include "ui_reviews.h"

#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QString>

reviews::reviews(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reviews)
{
    ui->setupUi(this);
    reviews::setWindowModality(Qt::ApplicationModal);
    reviews::setFixedSize(minimumSize());
    this->setWindowTitle("СТО");
    QGridLayout *layoutrewiws = new QGridLayout(this);
    addreviews = new QPushButton("Добавить новый отзыв");
    addreviews->setCursor(Qt::PointingHandCursor);
    fio_client1 = new QComboBox;
    ball1 = new QLineEdit;
    Reviews1 = new QLineEdit;
    fio_client = new QLabel("Введите ФИО:");
    ball = new QLabel("Оценка(1-5):");
    Reviews = new QLabel ("Введите отзыв:");
    Reviews1->setFixedWidth(200);
    layoutrewiws->addWidget(fio_client,3,0);
    layoutrewiws->addWidget(ball,4,0);
    layoutrewiws->addWidget(Reviews,5,0);
    layoutrewiws->addWidget(fio_client1,3,1);
    layoutrewiws->addWidget(ball1,4,1);
    layoutrewiws->addWidget(Reviews1,5,1);
    layoutrewiws->addWidget(addreviews,7,0,1,2);
    updateall();
    connect(addreviews, &QPushButton::clicked, this, [=]{
        QString fio_clientvvod = fio_client1->currentData().toString();
        QString ballvvod = ball1->text();
        if(ballvvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите оценку");
        QString Reviewsvvod = Reviews1->text();
        if(Reviewsvvod.isEmpty()) QMessageBox::warning(this,"СТО","Пожалуйста введите текст отзыва");
        QSqlQuery zapros;
        zapros.prepare("INSERT INTO `отзывы` (`id_заказа`, `оценка`, `отзыв`) VALUES(?,?,?)");
        zapros.addBindValue(fio_clientvvod);
        zapros.addBindValue(ballvvod);
        zapros.addBindValue(Reviewsvvod);
        if(zapros.exec()){
            QMessageBox::information(this,"СТО","Благодарим за отзыв!");
            emit revAdded();
            ball1->clear();
            Reviews1->clear();
        }
    });
}
void reviews::updateall(){
    QSqlQuery q1("SELECT id,фио_клиента FROM заказы");
    while(q1.next()){ fio_client1->addItem(q1.value("фио_клиента").toString(),q1.value("id")); }
}
reviews::~reviews()
{
    delete ui;
}
