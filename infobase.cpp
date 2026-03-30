#include "infobase.h"
#include "ui_infobase.h"
#include <QSqlQuery>
#include <QGridLayout>
#include <QSqlRecord>
#include <QFile>
#include <QFileDialog>
#include <QDate>
#include <QTextStream>
#include <QMessageBox>
#include <QTimer>
infobase::infobase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infobase)
{
    ui->setupUi(this);
    this->setWindowTitle("СТО");
    QGridLayout *layout = new QGridLayout(this);
    QTimer *reconnectdb = new QTimer;
    connect(reconnectdb,&QTimer::timeout,this,[]{
       QSqlDatabase db = QSqlDatabase::database();
       if(db.isOpen()){
           QSqlQuery connect;
           connect.prepare("SELECT 1");
           connect.exec();
       }
    });
    reconnectdb->start(60000);
    getallinfo = new QLabel("====ОБЩАЯ СТАТИСТИКА СТО==== \n"
                            "Общая заработанная сумма: \n"
                            "Общее количество клиентов: \n"
                            "Общее количество заказов: \n"
                            "Общее количество запчастей: \n"
                            "Общее количество сотрудников: \n"
                            "Общее количество отзывов: \n"
                            "Общее количество продаж запчастей: \n"
                            "Общее количество гарантийных случаев: \n"
                            "Общее количество выданных гарантий: \n"
                            "Общее количество ремонтов по гарантии: \n"
                            "Общее количество сотрудников гарантии: \n"
                            "Машин в ремонте: \n"
                            "Машин ожидают запчасти: \n"
                            "Машин готово: \n"
                            "Машин отменено: \n"
                            "Машин в работе: \n"
                            "Машин выдано: ");
    categoryreviews = new QLabel("====ОБЩАЯ ХАРАКТЕРИСТИКА ОТЗЫВОВ==== \n"
                                 "Отрицательных отзывов: \n"
                                 "нейтральных отзывов: \n"
                                 "положительных отзывов: \n"
                                 "Средняя оценка СТО: ");
    sellonday = new QLabel("====ДАННЫЕ ЗА " + QDate::currentDate().toString("dd.MM.yyyy") + "==== \n"
                           "Количество принятых машин: \n"
                           "Количество проданных запчастей: \n"
                           "Количество полученных отзывов: \n"
                           "Заработано денег за услуги/запчасти: ");
    getinfostaff = new QLabel("====ДАННЫЕ О СОТРУДНИКАХ==== \n"
                              "Количество рабочих сотрудников: \n"
                              "Количество сотрудников в отпуске: \n"
                              "Количество сотрудников на больничном: \n"
                              "Количество сотрудников на полном графике: \n"
                              "Количество сотрудников на вечернем графике: \n"
                              "Количество сотрудников на утреннем графике: \n"
                              "Саммый эффективный сотрудник: \n"
                              "Средняя зарплата сотрудников: " );
    getfinansoviyanaliz = new QLabel("====ФИНАНСОВЫЕ ПОКАЗАТЕЛИ==== \n"
                                     "Средний чек заказа: \n"
                                     "Самый дорогой заказ: \n"
                                     "Доход за последние 7 дней: \n"
                                     "Доход за последние 30 дней: \n"
                                     "Доход за текущий месяц: \n"
                                     "Доход за прошлый месяц: ");
    getinformation = new QPushButton("Нажмите для загрузки/обновления данных");
    getinformation->setCursor(Qt::PointingHandCursor);
    saveinformation = new QPushButton("Выгрузка данных в файл");
    saveinformation->setCursor(Qt::PointingHandCursor);
    layout->addWidget(getinformation);
    layout->addWidget(getallinfo);
    layout->addWidget(getinfostaff);
    layout->addWidget(categoryreviews);
    layout->addWidget(sellonday);
    layout->addWidget(getfinansoviyanaliz);
    layout->addWidget(saveinformation);
    connect(getinformation,&QPushButton::clicked,this,[=]{
        QSqlQuery finasovianaliz;
        finasovianaliz.prepare( "SELECT "
                                "(SELECT AVG(стоимость) FROM заказы) ,"
                                "(SELECT MAX(стоимость) FROM заказы) ,"
                                "(SELECT SUM(стоимость) FROM заказы WHERE дата_создания >= DATE_SUB(CURDATE(), INTERVAL 7 DAY)) ,"
                                "(SELECT SUM(стоимость) FROM заказы WHERE дата_создания >= DATE_SUB(CURDATE(), INTERVAL 30 DAY)) ,"
                                "(SELECT SUM(стоимость) FROM заказы WHERE дата_создания >= DATE_FORMAT(CURDATE(), '%Y-%m-01')) ,"
                                "(SELECT SUM(стоимость) FROM заказы WHERE дата_создания >= DATE_SUB(DATE_FORMAT(CURDATE(), '%Y-%m-01'), INTERVAL 1 MONTH) AND дата_создания < DATE_FORMAT(CURDATE(), '%Y-%m-01')) ");
        if(finasovianaliz.exec() && finasovianaliz.next()){
            QString finasovianaliztext("====ФИНАНСОВЫЕ ПОКАЗАТЕЛИ==== \n"
                                        "Средний чек заказа: " + finasovianaliz.value(0).toString() + "\n"
                                        "Самый дорогой заказ: " + finasovianaliz.value(1).toString() + "\n"
                                        "Доход за последние 7 дней: " + finasovianaliz.value(2).toString() + "\n"
                                        "Доход за последние 30 дней: " + finasovianaliz.value(3).toString() + "\n"
                                        "Доход за текущий месяц: " + finasovianaliz.value(4).toString() + "\n"
                                        "Доход за прошлый месяц: " + finasovianaliz.value(5).toString());
            getfinansoviyanaliz->setText(finasovianaliztext);
        }
        QSqlQuery infostaff;
        infostaff.prepare("SELECT " "(SELECT COUNT(*) FROM график_работы WHERE статус = 'работает'), "
                          "(SELECT COUNT(*) FROM график_работы WHERE статус = 'отпуск'),"
                          "(SELECT COUNT(*) FROM график_работы WHERE статус = 'больничный'),"
                          "(SELECT COUNT(*) FROM `график_работы` WHERE смена = 'полный'),"
                          "(SELECT COUNT(*) FROM `график_работы` WHERE смена = 'вечер'),"
                          "(SELECT COUNT(*) FROM `график_работы` WHERE смена = 'утро'),"
                          "(SELECT AVG(оклад) FROM сотрудники),"
                          "(SELECT фио_сотрудника FROM заказы GROUP BY фио_сотрудника LIMIT 1)");
        if(infostaff.exec() && infostaff.next()){
            QString infostafftext = ("====ДАННЫЕ О СОТРУДНИКАХ==== \n"
                                     "Количество рабочих сотрудников: " + infostaff.value(0).toString() + "\n"
                                     "Количество сотрудников в отпуске: " + infostaff.value(1).toString() + "\n"
                                     "Количество сотрудников на больничном: " + infostaff.value(2).toString() + "\n"
                                     "Количество сотрудников на полном графике: " + infostaff.value(3).toString() + "\n"
                                     "Количество сотрудников на вечернем графике: " + infostaff.value(4).toString() + "\n"
                                     "Количество сотрудников на утреннем графике: " + infostaff.value(5).toString() + "\n"
                                     "Саммый эффективный сотрудник: \n" + infostaff.value(7).toString() + "\n"
                                     "Средняя зарплата сотрудников: " + infostaff.value(6).toString());

            getinfostaff->setText(infostafftext);
        }
        QSqlQuery sellingonday;
        sellingonday.prepare("SELECT " "(SELECT COUNT(*) FROM `заказы` WHERE DATE(дата_создания) = CURRENT_DATE), "
                             "(SELECT COUNT(*) FROM `продажа_запчастей` WHERE DATE(дата_продажи) = CURRENT_DATE),"
                             "(SELECT COUNT(*) FROM `отзывы` WHERE DATE(дата_отзыва) = CURRENT_DATE),"
                             "(SELECT SUM(стоимость) FROM заказы WHERE DATE(Дата_создания) = CURRENT_DATE) + "
                             "(SELECT SUM(цена) FROM продажа_запчастей WHERE DATE(дата_продажи) = CURRENT_DATE)");
        if(sellingonday.exec() && sellingonday.next()){
            QString sellingondaytext = "====ДАННЫЕ ЗА " + QDate::currentDate().toString("dd.MM.yyyy") + "==== \n"
                    "Количество принятых машин: " + sellingonday.value(0).toString() + "\n"
                    "Количество проданных запчастей: " + sellingonday.value(1).toString() + "\n"
                    "Количество полученных отзывов: " + sellingonday.value(2).toString() + "\n"
                    "Заработано денег за услуги/запчасти: " + sellingonday.value(3).toString();
            sellonday->setText(sellingondaytext);
        }
        QSqlQuery info;
        info.prepare("SELECT ((SELECT SUM(стоимость) FROM заказы) + (SELECT SUM(цена) FROM продажа_запчастей)), "
                     "(SELECT COUNT(*) FROM клиенты), (SELECT COUNT(*) FROM заказы), (SELECT COUNT(*) FROM запчасти), "
                     "(SELECT COUNT(*) FROM сотрудники), (SELECT COUNT(*) FROM отзывы),(SELECT COUNT(*) FROM продажа_запчастей), "
                     "(SELECT COUNT(*) FROM гарантийные_случаи), (SELECT COUNT(*) FROM гарантия_по_ремонтам),"
                     "(SELECT COUNT(*) FROM ремонт_по_гарантии), (SELECT COUNT(*) FROM сотрудники_гарантии),"
                     "(SELECT COUNT(*) FROM заказы WHERE статус = 'принят'),(SELECT COUNT(*) FROM заказы WHERE статус = 'ожидает запчасти'),"
                     "(SELECT COUNT(*) FROM заказы WHERE статус = 'готов'),(SELECT COUNT(*) FROM заказы WHERE статус = 'отменен'),"
                     "(SELECT COUNT(*) FROM заказы WHERE статус = 'в работе'),(SELECT COUNT(*) FROM заказы WHERE статус = 'выдан')");
        if(info.exec() && info.next()){
            double sum = info.value(0).toDouble();
            QString getallinfotext = "====ОБЩАЯ СТАТИСТИКА СТО==== \n"
                    "Общая заработанная сумма: " + QString::number(sum) + "\n" +
                    "Общее количество клиентов: " + info.value(1).toString() + "\n" +
                    "Общее количество заказов: " + info.value(2).toString() + "\n" +
                    "Общее количество запчастей: " + info.value(3).toString() + "\n"
                    "Общее количество сотрудников: " + info.value(4).toString() + "\n"
                    "Общее количество отзывов: " + info.value(5).toString() +  "\n"
                    "Общее количество продаж запчастей: " + info.value(6).toString() +  "\n"
                    "Общее количество гарантийных случаев: " + info.value(7).toString() +  "\n"
                    "Общее количество выданных гарантий: " + info.value(8).toString() +  "\n"
                    "Общее количество ремонтов по гарантии: " + info.value(9).toString() +  "\n"
                    "Общее количество сотрудников гарантии: "+ info.value(10).toString() +  "\n"
                    "Машин в ремонте: " + info.value(11).toString() +  "\n"
                    "Машин ожидают запчасти: " + info.value(12).toString() +  "\n"
                    "Машин готово: " + info.value(13).toString() +  "\n"
                    "Машин отменено: " + info.value(14).toString() + "\n"
                    "Машин в работе: " + info.value(15).toString() + "\n"
                    "Машин выдано: " + info.value(16).toString();

            getallinfo->setText(getallinfotext);
        }
        QSqlQuery category;
        category.prepare("SELECT (SELECT COUNT(*) FROM отзывы WHERE оценка <= 2),"
                         "(SELECT COUNT(*) FROM отзывы WHERE оценка = 3),"
                         "(SELECT COUNT(*) FROM отзывы WHERE оценка >= 4),"
                         "(SELECT AVG(оценка) FROM отзывы)");
        if(category.exec() && category.next()){
            QString categorytext = "====ОБЩАЯ ХАРАКТЕРИСТИКА ОТЗЫВОВ==== \n"
                    "Отрицательных отзывов: " + category.value(0).toString() + "\n"
                    "нейтральных отзывов: " + category.value(1).toString() + "\n"
                    "положительных отзывов: " + category.value(2).toString() + "\n"
                    "Средняя оценка СТО: " + category.value(3).toString();
            categoryreviews->setText(categorytext);
        }
    });
    connect(saveinformation,&QPushButton::clicked,this,[=]{
        QString filepath = "D:/qt/qt/STO2 ТАБЛИЦЫ/отчеты";
        QString setfilecfg = QFileDialog::getSaveFileName(this,"Сохранить файл", filepath + "/" + "Общий отчет базы от" + QDate::currentDate().toString(" dd.MM.yyyy") + ".txt", "(*.txt)");
        QFile savefile(setfilecfg);
        if(!savefile.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&savefile);
        out << sellonday->text() << getallinfo->text() << getfinansoviyanaliz->text() << getinfostaff->text() << categoryreviews->text();
        savefile.close();
        QMessageBox::information(this,"СТО","файл сохранен по пути: " + filepath);
    });
}

infobase::~infobase()
{
    delete ui;
}
