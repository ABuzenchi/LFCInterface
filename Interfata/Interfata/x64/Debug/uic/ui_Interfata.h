/********************************************************************************
** Form generated from reading UI file 'Interfata.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFATA_H
#define UI_INTERFATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfataClass
{
public:
    QWidget *centralWidget;
    QRadioButton *radioButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfataClass)
    {
        if (InterfataClass->objectName().isEmpty())
            InterfataClass->setObjectName("InterfataClass");
        InterfataClass->resize(600, 400);
        centralWidget = new QWidget(InterfataClass);
        centralWidget->setObjectName("centralWidget");
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(30, 30, 111, 20));
        InterfataClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfataClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        InterfataClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InterfataClass);
        mainToolBar->setObjectName("mainToolBar");
        InterfataClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InterfataClass);
        statusBar->setObjectName("statusBar");
        InterfataClass->setStatusBar(statusBar);

        retranslateUi(InterfataClass);

        QMetaObject::connectSlotsByName(InterfataClass);
    } // setupUi

    void retranslateUi(QMainWindow *InterfataClass)
    {
        InterfataClass->setWindowTitle(QCoreApplication::translate("InterfataClass", "Interfata", nullptr));
        radioButton->setText(QCoreApplication::translate("InterfataClass", "Show Symbols", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfataClass: public Ui_InterfataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFATA_H
