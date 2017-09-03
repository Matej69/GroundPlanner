/********************************************************************************
** Form generated from reading UI file 'editorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORWINDOW_H
#define UI_EDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorWindow
{
public:
    QWidget *widget;
    QPushButton *roomAdd;
    QPushButton *pointAdd;
    QPushButton *floorAdd;
    QPushButton *pointDelete;
    QPushButton *floorDelete;
    QPushButton *roomDelete;
    QPushButton *saveAll;
    QComboBox *dropBox_floors;
    QPushButton *switchWindow;

    void setupUi(QWidget *EditorWindow)
    {
        if (EditorWindow->objectName().isEmpty())
            EditorWindow->setObjectName(QStringLiteral("EditorWindow"));
        EditorWindow->resize(839, 691);
        EditorWindow->setStyleSheet(QStringLiteral(" color:black"));
        widget = new QWidget(EditorWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(0, 0, 141, 131));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 191, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 159, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 84, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush8(QColor(0, 255, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        widget->setPalette(palette);
        widget->setCursor(QCursor(Qt::ArrowCursor));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 0);"));
        roomAdd = new QPushButton(widget);
        roomAdd->setObjectName(QStringLiteral("roomAdd"));
        roomAdd->setGeometry(QRect(10, 10, 38, 38));
        roomAdd->setStyleSheet(QLatin1String("background:#3f3f3f; \n"
"color:white;font-weight:bold;font-size:10px;\n"
"QDialog {background: red;};\n"
"QInputDialog {background: red;};\n"
"border-image: url(\":/img/addRoom\");"));
        roomAdd->setIconSize(QSize(32, 32));
        roomAdd->setCheckable(false);
        roomAdd->setChecked(false);
        roomAdd->setAutoDefault(false);
        pointAdd = new QPushButton(widget);
        pointAdd->setObjectName(QStringLiteral("pointAdd"));
        pointAdd->setGeometry(QRect(50, 10, 38, 38));
        pointAdd->setStyleSheet(QLatin1String("background:#3f3f3f; \n"
"color:white;font-weight:bold;font-size:10px;\n"
"QDialog {background: red;};\n"
"QInputDialog {background: red;};\n"
"border-image: url(\":/img/addPoint\");"));
        pointAdd->setIconSize(QSize(32, 32));
        floorAdd = new QPushButton(widget);
        floorAdd->setObjectName(QStringLiteral("floorAdd"));
        floorAdd->setGeometry(QRect(90, 10, 38, 38));
        floorAdd->setStyleSheet(QLatin1String("background:#3f3f3f; \n"
"color:white;font-weight:bold;font-size:10px;\n"
"QDialog {background: red;};\n"
"QInputDialog {background: red;};\n"
"border-image: url(\":/img/addFloor\");"));
        floorAdd->setIconSize(QSize(32, 32));
        floorAdd->setCheckable(false);
        floorAdd->setAutoRepeat(false);
        floorAdd->setAutoExclusive(false);
        pointDelete = new QPushButton(widget);
        pointDelete->setObjectName(QStringLiteral("pointDelete"));
        pointDelete->setGeometry(QRect(50, 50, 38, 38));
        pointDelete->setStyleSheet(QLatin1String("background:#3f3f3f; \n"
"color:white;font-weight:bold;font-size:10px;\n"
"QDialog {background: red;};\n"
"QInputDialog {background: red;};\n"
"border-image: url(':/img/deletePointInactive');\n"
""));
        pointDelete->setIconSize(QSize(32, 32));
        floorDelete = new QPushButton(widget);
        floorDelete->setObjectName(QStringLiteral("floorDelete"));
        floorDelete->setGeometry(QRect(90, 50, 38, 38));
        floorDelete->setAutoFillBackground(false);
        floorDelete->setStyleSheet(QLatin1String("background:#3f3f3f; \n"
"color:white;font-weight:bold;font-size:10px;\n"
"QDialog {background: red;};\n"
"QInputDialog {background: red;};\n"
"border-image: url(\":/img/deleteFloor\");"));
        floorDelete->setIconSize(QSize(32, 32));
        roomDelete = new QPushButton(widget);
        roomDelete->setObjectName(QStringLiteral("roomDelete"));
        roomDelete->setGeometry(QRect(10, 50, 38, 38));
        roomDelete->setStyleSheet(QLatin1String("background:#3f3f3f; \n"
"color:white;font-weight:bold;font-size:10px;\n"
"border-image: url(\":/img/deleteRoom\");"));
        roomDelete->setIconSize(QSize(32, 32));
        roomDelete->setCheckable(false);
        roomDelete->setChecked(false);
        roomDelete->setAutoDefault(false);
        saveAll = new QPushButton(widget);
        saveAll->setObjectName(QStringLiteral("saveAll"));
        saveAll->setGeometry(QRect(10, 90, 121, 21));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        saveAll->setFont(font);
        saveAll->setAutoFillBackground(false);
        saveAll->setStyleSheet(QStringLiteral("background:white;color:black;font-weight:bold;"));
        saveAll->setIconSize(QSize(32, 32));
        dropBox_floors = new QComboBox(widget);
        dropBox_floors->setObjectName(QStringLiteral("dropBox_floors"));
        dropBox_floors->setGeometry(QRect(10, 110, 121, 21));
        dropBox_floors->setStyleSheet(QStringLiteral("background:white;color:black;font-weight:bold;"));
        switchWindow = new QPushButton(EditorWindow);
        switchWindow->setObjectName(QStringLiteral("switchWindow"));
        switchWindow->setGeometry(QRect(784, 0, 51, 51));
        switchWindow->setStyleSheet(QStringLiteral(""));

        retranslateUi(EditorWindow);

        QMetaObject::connectSlotsByName(EditorWindow);
    } // setupUi

    void retranslateUi(QWidget *EditorWindow)
    {
        EditorWindow->setWindowTitle(QApplication::translate("EditorWindow", "Form", Q_NULLPTR));
        roomAdd->setText(QString());
        pointAdd->setText(QString());
        floorAdd->setText(QString());
        pointDelete->setText(QString());
        floorDelete->setText(QString());
        roomDelete->setText(QString());
        saveAll->setText(QApplication::translate("EditorWindow", "SAVE", Q_NULLPTR));
        switchWindow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditorWindow: public Ui_EditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORWINDOW_H
