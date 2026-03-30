/********************************************************************************
** Form generated from reading UI file 'partsalesadd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTSALESADD_H
#define UI_PARTSALESADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Partsalesadd
{
public:

    void setupUi(QWidget *Partsalesadd)
    {
        if (Partsalesadd->objectName().isEmpty())
            Partsalesadd->setObjectName("Partsalesadd");
        Partsalesadd->resize(400, 300);

        retranslateUi(Partsalesadd);

        QMetaObject::connectSlotsByName(Partsalesadd);
    } // setupUi

    void retranslateUi(QWidget *Partsalesadd)
    {
        Partsalesadd->setWindowTitle(QCoreApplication::translate("Partsalesadd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Partsalesadd: public Ui_Partsalesadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTSALESADD_H
