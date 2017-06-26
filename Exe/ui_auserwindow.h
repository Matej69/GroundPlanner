/********************************************************************************
** Form generated from reading UI file 'auserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUSERWINDOW_H
#define UI_AUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AUserWindow
{
public:

    void setupUi(QWidget *AUserWindow)
    {
        if (AUserWindow->objectName().isEmpty())
            AUserWindow->setObjectName(QStringLiteral("AUserWindow"));
        AUserWindow->resize(812, 500);

        retranslateUi(AUserWindow);

        QMetaObject::connectSlotsByName(AUserWindow);
    } // setupUi

    void retranslateUi(QWidget *AUserWindow)
    {
        AUserWindow->setWindowTitle(QApplication::translate("AUserWindow", "ABSTRACT WINDOW", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AUserWindow: public Ui_AUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUSERWINDOW_H
