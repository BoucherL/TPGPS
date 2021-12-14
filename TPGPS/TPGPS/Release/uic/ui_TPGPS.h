/********************************************************************************
** Form generated from reading UI file 'TPGPS.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPGPS_H
#define UI_TPGPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TPGPSClass
{
public:
    QWidget *centralWidget;
    QLabel *portStatus;
    QLabel *Latitude;
    QLabel *Longitude;
    QLabel *TexteMemo1;
    QLabel *Memo1;
    QLabel *MemoTexte2;
    QLabel *Memo2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TPGPSClass)
    {
        if (TPGPSClass->objectName().isEmpty())
            TPGPSClass->setObjectName(QString::fromUtf8("TPGPSClass"));
        TPGPSClass->resize(600, 599);
        centralWidget = new QWidget(TPGPSClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        portStatus = new QLabel(centralWidget);
        portStatus->setObjectName(QString::fromUtf8("portStatus"));
        portStatus->setGeometry(QRect(40, 40, 111, 21));
        Latitude = new QLabel(centralWidget);
        Latitude->setObjectName(QString::fromUtf8("Latitude"));
        Latitude->setGeometry(QRect(40, 100, 81, 21));
        Longitude = new QLabel(centralWidget);
        Longitude->setObjectName(QString::fromUtf8("Longitude"));
        Longitude->setGeometry(QRect(40, 70, 81, 21));
        TexteMemo1 = new QLabel(centralWidget);
        TexteMemo1->setObjectName(QString::fromUtf8("TexteMemo1"));
        TexteMemo1->setGeometry(QRect(100, 220, 81, 21));
        Memo1 = new QLabel(centralWidget);
        Memo1->setObjectName(QString::fromUtf8("Memo1"));
        Memo1->setGeometry(QRect(220, 220, 81, 21));
        MemoTexte2 = new QLabel(centralWidget);
        MemoTexte2->setObjectName(QString::fromUtf8("MemoTexte2"));
        MemoTexte2->setGeometry(QRect(100, 270, 81, 21));
        Memo2 = new QLabel(centralWidget);
        Memo2->setObjectName(QString::fromUtf8("Memo2"));
        Memo2->setGeometry(QRect(220, 270, 81, 21));
        TPGPSClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TPGPSClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TPGPSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TPGPSClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TPGPSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TPGPSClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TPGPSClass->setStatusBar(statusBar);

        retranslateUi(TPGPSClass);

        QMetaObject::connectSlotsByName(TPGPSClass);
    } // setupUi

    void retranslateUi(QMainWindow *TPGPSClass)
    {
        TPGPSClass->setWindowTitle(QCoreApplication::translate("TPGPSClass", "TPGPS", nullptr));
        portStatus->setText(QCoreApplication::translate("TPGPSClass", "Port : ", nullptr));
        Latitude->setText(QCoreApplication::translate("TPGPSClass", "Latitude: ", nullptr));
        Longitude->setText(QCoreApplication::translate("TPGPSClass", "Longitude: ", nullptr));
        TexteMemo1->setText(QCoreApplication::translate("TPGPSClass", "M\303\251mo 1 :", nullptr));
        Memo1->setText(QCoreApplication::translate("TPGPSClass", "Trame1", nullptr));
        MemoTexte2->setText(QCoreApplication::translate("TPGPSClass", "Trame 2 :", nullptr));
        Memo2->setText(QCoreApplication::translate("TPGPSClass", "Trame2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TPGPSClass: public Ui_TPGPSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPGPS_H
