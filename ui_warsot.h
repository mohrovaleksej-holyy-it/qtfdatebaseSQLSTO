/********************************************************************************
** Form generated from reading UI file 'warsot.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARSOT_H
#define UI_WARSOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_warsot
{
public:

    void setupUi(QWidget *warsot)
    {
        if (warsot->objectName().isEmpty())
            warsot->setObjectName("warsot");
        warsot->resize(400, 300);

        retranslateUi(warsot);

        QMetaObject::connectSlotsByName(warsot);
    } // setupUi

    void retranslateUi(QWidget *warsot)
    {
        warsot->setWindowTitle(QCoreApplication::translate("warsot", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class warsot: public Ui_warsot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARSOT_H
