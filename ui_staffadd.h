/********************************************************************************
** Form generated from reading UI file 'staffadd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAFFADD_H
#define UI_STAFFADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Staffadd
{
public:

    void setupUi(QWidget *Staffadd)
    {
        if (Staffadd->objectName().isEmpty())
            Staffadd->setObjectName("Staffadd");
        Staffadd->resize(400, 300);

        retranslateUi(Staffadd);

        QMetaObject::connectSlotsByName(Staffadd);
    } // setupUi

    void retranslateUi(QWidget *Staffadd)
    {
        Staffadd->setWindowTitle(QCoreApplication::translate("Staffadd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Staffadd: public Ui_Staffadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAFFADD_H
