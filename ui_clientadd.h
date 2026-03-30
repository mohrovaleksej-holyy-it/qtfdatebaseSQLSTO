/********************************************************************************
** Form generated from reading UI file 'clientadd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTADD_H
#define UI_CLIENTADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientadd
{
public:

    void setupUi(QWidget *clientadd)
    {
        if (clientadd->objectName().isEmpty())
            clientadd->setObjectName("clientadd");
        clientadd->resize(400, 300);

        retranslateUi(clientadd);

        QMetaObject::connectSlotsByName(clientadd);
    } // setupUi

    void retranslateUi(QWidget *clientadd)
    {
        clientadd->setWindowTitle(QCoreApplication::translate("clientadd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientadd: public Ui_clientadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTADD_H
