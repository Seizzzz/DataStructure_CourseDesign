/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mymap.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QWidget *widgetAddTourist;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QCheckBox *checkBoxTouristTimeLimit;
    QComboBox *comboBoxTouristStart;
    QLabel *label_2;
    QLineEdit *lineEditTouristLimit;
    QComboBox *comboBoxTouristDes;
    QPushButton *pushButtonAddTourist;
    QLabel *labelAddTourist;
    QCheckBox *checkBoxTouristNextDay;
    QWidget *widgetAddTourist_2;
    QGridLayout *gridLayout_2;
    QLabel *labelAddTourist_2;
    QLabel *label_4;
    QLineEdit *lineEditCityName;
    QLabel *label_6;
    QLineEdit *lineEditCityRisk;
    QPushButton *pushButtonAddCity;
    QTableWidget *tableWidgetTourist;
    QTreeWidget *treeWidgetCity;
    QCheckBox *checkBoxTime;
    QLabel *label_11;
    QLabel *labelTime;
    QLabel *label_12;
    QLabel *label_13;
    myMap *widgetMap;
    QWidget *widgetAddTourist_3;
    QGridLayout *gridLayout_3;
    QLabel *labelAddTourist_3;
    QLabel *label_14;
    QComboBox *comboBoxTransportKind;
    QLabel *label_10;
    QComboBox *comboBoxTransportStart;
    QLabel *label_5;
    QComboBox *comboBoxTransportDes;
    QLabel *label_7;
    QLineEdit *lineEditTransportRisk;
    QLabel *label_9;
    QLineEdit *lineEditTransportStartTime;
    QLabel *label_8;
    QLineEdit *lineEditTransportTimecost;
    QPushButton *pushButtonAddTransport;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widgetAddTourist = new QWidget(centralwidget);
        widgetAddTourist->setObjectName(QString::fromUtf8("widgetAddTourist"));
        widgetAddTourist->setGeometry(QRect(1100, 230, 181, 137));
        gridLayout = new QGridLayout(widgetAddTourist);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widgetAddTourist);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(widgetAddTourist);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        checkBoxTouristTimeLimit = new QCheckBox(widgetAddTourist);
        checkBoxTouristTimeLimit->setObjectName(QString::fromUtf8("checkBoxTouristTimeLimit"));
        checkBoxTouristTimeLimit->setChecked(true);

        gridLayout->addWidget(checkBoxTouristTimeLimit, 4, 1, 1, 1);

        comboBoxTouristStart = new QComboBox(widgetAddTourist);
        comboBoxTouristStart->setObjectName(QString::fromUtf8("comboBoxTouristStart"));

        gridLayout->addWidget(comboBoxTouristStart, 1, 1, 1, 1);

        label_2 = new QLabel(widgetAddTourist);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditTouristLimit = new QLineEdit(widgetAddTourist);
        lineEditTouristLimit->setObjectName(QString::fromUtf8("lineEditTouristLimit"));

        gridLayout->addWidget(lineEditTouristLimit, 3, 1, 1, 1);

        comboBoxTouristDes = new QComboBox(widgetAddTourist);
        comboBoxTouristDes->setObjectName(QString::fromUtf8("comboBoxTouristDes"));

        gridLayout->addWidget(comboBoxTouristDes, 2, 1, 1, 1);

        pushButtonAddTourist = new QPushButton(widgetAddTourist);
        pushButtonAddTourist->setObjectName(QString::fromUtf8("pushButtonAddTourist"));
        pushButtonAddTourist->setEnabled(true);

        gridLayout->addWidget(pushButtonAddTourist, 4, 0, 1, 1);

        labelAddTourist = new QLabel(widgetAddTourist);
        labelAddTourist->setObjectName(QString::fromUtf8("labelAddTourist"));

        gridLayout->addWidget(labelAddTourist, 0, 0, 1, 1);

        checkBoxTouristNextDay = new QCheckBox(widgetAddTourist);
        checkBoxTouristNextDay->setObjectName(QString::fromUtf8("checkBoxTouristNextDay"));
        checkBoxTouristNextDay->setChecked(true);

        gridLayout->addWidget(checkBoxTouristNextDay, 0, 1, 1, 1);

        widgetAddTourist_2 = new QWidget(centralwidget);
        widgetAddTourist_2->setObjectName(QString::fromUtf8("widgetAddTourist_2"));
        widgetAddTourist_2->setGeometry(QRect(1100, 110, 181, 111));
        gridLayout_2 = new QGridLayout(widgetAddTourist_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelAddTourist_2 = new QLabel(widgetAddTourist_2);
        labelAddTourist_2->setObjectName(QString::fromUtf8("labelAddTourist_2"));

        gridLayout_2->addWidget(labelAddTourist_2, 0, 0, 1, 1);

        label_4 = new QLabel(widgetAddTourist_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEditCityName = new QLineEdit(widgetAddTourist_2);
        lineEditCityName->setObjectName(QString::fromUtf8("lineEditCityName"));

        gridLayout_2->addWidget(lineEditCityName, 1, 1, 1, 1);

        label_6 = new QLabel(widgetAddTourist_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        lineEditCityRisk = new QLineEdit(widgetAddTourist_2);
        lineEditCityRisk->setObjectName(QString::fromUtf8("lineEditCityRisk"));

        gridLayout_2->addWidget(lineEditCityRisk, 2, 1, 1, 1);

        pushButtonAddCity = new QPushButton(widgetAddTourist_2);
        pushButtonAddCity->setObjectName(QString::fromUtf8("pushButtonAddCity"));
        pushButtonAddCity->setEnabled(true);

        gridLayout_2->addWidget(pushButtonAddCity, 3, 0, 1, 1);

        tableWidgetTourist = new QTableWidget(centralwidget);
        if (tableWidgetTourist->columnCount() < 9)
            tableWidgetTourist->setColumnCount(9);
        tableWidgetTourist->setObjectName(QString::fromUtf8("tableWidgetTourist"));
        tableWidgetTourist->setGeometry(QRect(760, 40, 331, 251));
        tableWidgetTourist->setColumnCount(9);
        tableWidgetTourist->horizontalHeader()->setDefaultSectionSize(65);
        treeWidgetCity = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetCity->setHeaderItem(__qtreewidgetitem);
        treeWidgetCity->setObjectName(QString::fromUtf8("treeWidgetCity"));
        treeWidgetCity->setGeometry(QRect(760, 320, 331, 261));
        treeWidgetCity->setColumnCount(4);
        treeWidgetCity->header()->setVisible(false);
        treeWidgetCity->header()->setDefaultSectionSize(76);
        checkBoxTime = new QCheckBox(centralwidget);
        checkBoxTime->setObjectName(QString::fromUtf8("checkBoxTime"));
        checkBoxTime->setGeometry(QRect(1120, 70, 71, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1120, 20, 54, 12));
        labelTime = new QLabel(centralwidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(1130, 40, 54, 12));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(770, 20, 81, 16));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(770, 300, 111, 16));
        widgetMap = new myMap(centralwidget);
        widgetMap->setObjectName(QString::fromUtf8("widgetMap"));
        widgetMap->setGeometry(QRect(0, 0, 746, 600));
        widgetAddTourist_3 = new QWidget(centralwidget);
        widgetAddTourist_3->setObjectName(QString::fromUtf8("widgetAddTourist_3"));
        widgetAddTourist_3->setGeometry(QRect(1100, 370, 181, 215));
        gridLayout_3 = new QGridLayout(widgetAddTourist_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelAddTourist_3 = new QLabel(widgetAddTourist_3);
        labelAddTourist_3->setObjectName(QString::fromUtf8("labelAddTourist_3"));

        gridLayout_3->addWidget(labelAddTourist_3, 0, 0, 1, 1);

        label_14 = new QLabel(widgetAddTourist_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 1, 0, 1, 1);

        comboBoxTransportKind = new QComboBox(widgetAddTourist_3);
        comboBoxTransportKind->setObjectName(QString::fromUtf8("comboBoxTransportKind"));

        gridLayout_3->addWidget(comboBoxTransportKind, 1, 1, 1, 1);

        label_10 = new QLabel(widgetAddTourist_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        comboBoxTransportStart = new QComboBox(widgetAddTourist_3);
        comboBoxTransportStart->setObjectName(QString::fromUtf8("comboBoxTransportStart"));

        gridLayout_3->addWidget(comboBoxTransportStart, 2, 1, 1, 1);

        label_5 = new QLabel(widgetAddTourist_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        comboBoxTransportDes = new QComboBox(widgetAddTourist_3);
        comboBoxTransportDes->setObjectName(QString::fromUtf8("comboBoxTransportDes"));

        gridLayout_3->addWidget(comboBoxTransportDes, 3, 1, 1, 1);

        label_7 = new QLabel(widgetAddTourist_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 4, 0, 1, 1);

        lineEditTransportRisk = new QLineEdit(widgetAddTourist_3);
        lineEditTransportRisk->setObjectName(QString::fromUtf8("lineEditTransportRisk"));

        gridLayout_3->addWidget(lineEditTransportRisk, 4, 1, 1, 1);

        label_9 = new QLabel(widgetAddTourist_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        lineEditTransportStartTime = new QLineEdit(widgetAddTourist_3);
        lineEditTransportStartTime->setObjectName(QString::fromUtf8("lineEditTransportStartTime"));

        gridLayout_3->addWidget(lineEditTransportStartTime, 5, 1, 1, 1);

        label_8 = new QLabel(widgetAddTourist_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 6, 0, 1, 1);

        lineEditTransportTimecost = new QLineEdit(widgetAddTourist_3);
        lineEditTransportTimecost->setObjectName(QString::fromUtf8("lineEditTransportTimecost"));

        gridLayout_3->addWidget(lineEditTransportTimecost, 6, 1, 1, 1);

        pushButtonAddTransport = new QPushButton(widgetAddTourist_3);
        pushButtonAddTransport->setObjectName(QString::fromUtf8("pushButtonAddTransport"));
        pushButtonAddTransport->setEnabled(true);

        gridLayout_3->addWidget(pushButtonAddTransport, 7, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\217\221\347\202\271\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\231\220(\345\260\217\346\227\266):", nullptr));
        checkBoxTouristTimeLimit->setText(QCoreApplication::translate("MainWindow", "\351\231\220\346\227\266", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260\357\274\232", nullptr));
        pushButtonAddTourist->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\205\345\256\242", nullptr));
        labelAddTourist->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\205\345\256\242\357\274\232", nullptr));
        checkBoxTouristNextDay->setText(QCoreApplication::translate("MainWindow", "\346\254\241\346\227\245\345\207\272\345\217\221", nullptr));
        labelAddTourist_2->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\237\216\345\270\202\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\237\216\345\270\202\345\220\215\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\243\216\351\231\251\345\200\274\357\274\232", nullptr));
        pushButtonAddCity->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\237\216\345\270\202", nullptr));
        checkBoxTime->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        labelTime->setText(QCoreApplication::translate("MainWindow", "0\345\244\2510\345\260\217\346\227\266", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\227\205\345\256\242\344\277\241\346\201\257\350\241\250\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\345\237\216\345\270\202/\350\275\246\346\254\241\344\277\241\346\201\257\350\241\250\357\274\232", nullptr));
        labelAddTourist_3->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\266\345\210\273\350\241\250\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\247\213\345\217\221\347\253\231\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\202\271\347\253\231\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\351\243\216\351\231\251\345\200\274\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\217\221\346\227\266\351\227\264:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\225\277(\345\260\217\346\227\266):", nullptr));
        pushButtonAddTransport->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\266\345\210\273\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
