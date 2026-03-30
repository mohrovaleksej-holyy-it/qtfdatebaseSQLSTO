/********************************************************************************
** Form generated from reading UI file 'reviews.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEWS_H
#define UI_REVIEWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reviews
{
public:

    void setupUi(QWidget *reviews)
    {
        if (reviews->objectName().isEmpty())
            reviews->setObjectName("reviews");
        reviews->resize(400, 300);

        retranslateUi(reviews);

        QMetaObject::connectSlotsByName(reviews);
    } // setupUi

    void retranslateUi(QWidget *reviews)
    {
        reviews->setWindowTitle(QCoreApplication::translate("reviews", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reviews: public Ui_reviews {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEWS_H
