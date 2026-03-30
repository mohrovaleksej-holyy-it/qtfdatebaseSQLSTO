/********************************************************************************
** Form generated from reading UI file 'infobase.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOBASE_H
#define UI_INFOBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infobase
{
public:

    void setupUi(QWidget *infobase)
    {
        if (infobase->objectName().isEmpty())
            infobase->setObjectName("infobase");
        infobase->resize(400, 300);

        retranslateUi(infobase);

        QMetaObject::connectSlotsByName(infobase);
    } // setupUi

    void retranslateUi(QWidget *infobase)
    {
        infobase->setWindowTitle(QCoreApplication::translate("infobase", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infobase: public Ui_infobase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOBASE_H
