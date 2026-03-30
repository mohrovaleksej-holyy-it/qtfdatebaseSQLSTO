/********************************************************************************
** Form generated from reading UI file 'rempogar.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMPOGAR_H
#define UI_REMPOGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rempogar
{
public:

    void setupUi(QWidget *rempogar)
    {
        if (rempogar->objectName().isEmpty())
            rempogar->setObjectName("rempogar");
        rempogar->resize(400, 300);

        retranslateUi(rempogar);

        QMetaObject::connectSlotsByName(rempogar);
    } // setupUi

    void retranslateUi(QWidget *rempogar)
    {
        rempogar->setWindowTitle(QCoreApplication::translate("rempogar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rempogar: public Ui_rempogar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMPOGAR_H
