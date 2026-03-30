/********************************************************************************
** Form generated from reading UI file 'ordersadd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSADD_H
#define UI_ORDERSADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ordersadd
{
public:

    void setupUi(QWidget *ordersadd)
    {
        if (ordersadd->objectName().isEmpty())
            ordersadd->setObjectName("ordersadd");
        ordersadd->resize(400, 300);

        retranslateUi(ordersadd);

        QMetaObject::connectSlotsByName(ordersadd);
    } // setupUi

    void retranslateUi(QWidget *ordersadd)
    {
        ordersadd->setWindowTitle(QCoreApplication::translate("ordersadd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ordersadd: public Ui_ordersadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSADD_H
