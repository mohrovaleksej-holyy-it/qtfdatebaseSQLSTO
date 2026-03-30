/********************************************************************************
** Form generated from reading UI file 'servicesadd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICESADD_H
#define UI_SERVICESADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Servicesadd
{
public:

    void setupUi(QWidget *Servicesadd)
    {
        if (Servicesadd->objectName().isEmpty())
            Servicesadd->setObjectName("Servicesadd");
        Servicesadd->resize(400, 300);

        retranslateUi(Servicesadd);

        QMetaObject::connectSlotsByName(Servicesadd);
    } // setupUi

    void retranslateUi(QWidget *Servicesadd)
    {
        Servicesadd->setWindowTitle(QCoreApplication::translate("Servicesadd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Servicesadd: public Ui_Servicesadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICESADD_H
