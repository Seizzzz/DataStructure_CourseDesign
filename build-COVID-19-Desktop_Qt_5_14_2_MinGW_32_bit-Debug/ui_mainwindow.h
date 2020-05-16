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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *labelMap;
    QWidget *widgetAddTourist;
    QGridLayout *gridLayout;
    QLabel *labelAddTourist;
    QLabel *label;
    QComboBox *comboBoxTouristStart;
    QLabel *label_2;
    QComboBox *comboBoxTouristDes;
    QLabel *label_3;
    QLineEdit *lineEditTouristLimit;
    QPushButton *pushButtonAddTourist;
    QWidget *widgetAddTourist_2;
    QGridLayout *gridLayout_2;
    QLabel *labelAddTourist_2;
    QLabel *label_4;
    QLineEdit *lineEditCityName;
    QLabel *label_6;
    QLineEdit *lineEditCityRisk;
    QPushButton *pushButtonAddCity;
    QWidget *widgetAddTourist_3;
    QGridLayout *gridLayout_3;
    QLabel *labelAddTourist_3;
    QLabel *label_10;
    QComboBox *comboBoxTransportStart;
    QLabel *label_5;
    QComboBox *comboBoxTransportDes;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEditTransportStartTime;
    QLabel *label_8;
    QLineEdit *lineEditTransportTimecost;
    QPushButton *pushButtonAddTransport;
    QLineEdit *lineEditTransportRisk;
    QTableWidget *tableWidgetTourist;
    QTreeWidget *treeWidgetCity;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelMap = new QLabel(centralwidget);
        labelMap->setObjectName(QString::fromUtf8("labelMap"));
        labelMap->setGeometry(QRect(0, 0, 746, 600));
        labelMap->setFrameShape(QFrame::Box);
        labelMap->setScaledContents(false);
        widgetAddTourist = new QWidget(centralwidget);
        widgetAddTourist->setObjectName(QString::fromUtf8("widgetAddTourist"));
        widgetAddTourist->setGeometry(QRect(940, 20, 232, 137));
        gridLayout = new QGridLayout(widgetAddTourist);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelAddTourist = new QLabel(widgetAddTourist);
        labelAddTourist->setObjectName(QString::fromUtf8("labelAddTourist"));

        gridLayout->addWidget(labelAddTourist, 0, 0, 1, 1);

        label = new QLabel(widgetAddTourist);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        comboBoxTouristStart = new QComboBox(widgetAddTourist);
        comboBoxTouristStart->setObjectName(QString::fromUtf8("comboBoxTouristStart"));

        gridLayout->addWidget(comboBoxTouristStart, 1, 1, 1, 1);

        label_2 = new QLabel(widgetAddTourist);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        comboBoxTouristDes = new QComboBox(widgetAddTourist);
        comboBoxTouristDes->setObjectName(QString::fromUtf8("comboBoxTouristDes"));

        gridLayout->addWidget(comboBoxTouristDes, 2, 1, 1, 1);

        label_3 = new QLabel(widgetAddTourist);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEditTouristLimit = new QLineEdit(widgetAddTourist);
        lineEditTouristLimit->setObjectName(QString::fromUtf8("lineEditTouristLimit"));

        gridLayout->addWidget(lineEditTouristLimit, 3, 1, 1, 1);

        pushButtonAddTourist = new QPushButton(widgetAddTourist);
        pushButtonAddTourist->setObjectName(QString::fromUtf8("pushButtonAddTourist"));

        gridLayout->addWidget(pushButtonAddTourist, 4, 0, 1, 1);

        widgetAddTourist_2 = new QWidget(centralwidget);
        widgetAddTourist_2->setObjectName(QString::fromUtf8("widgetAddTourist_2"));
        widgetAddTourist_2->setGeometry(QRect(940, 240, 232, 111));
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

        gridLayout_2->addWidget(pushButtonAddCity, 3, 0, 1, 1);

        widgetAddTourist_3 = new QWidget(centralwidget);
        widgetAddTourist_3->setObjectName(QString::fromUtf8("widgetAddTourist_3"));
        widgetAddTourist_3->setGeometry(QRect(950, 380, 235, 189));
        gridLayout_3 = new QGridLayout(widgetAddTourist_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelAddTourist_3 = new QLabel(widgetAddTourist_3);
        labelAddTourist_3->setObjectName(QString::fromUtf8("labelAddTourist_3"));

        gridLayout_3->addWidget(labelAddTourist_3, 0, 0, 1, 1);

        label_10 = new QLabel(widgetAddTourist_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        comboBoxTransportStart = new QComboBox(widgetAddTourist_3);
        comboBoxTransportStart->setObjectName(QString::fromUtf8("comboBoxTransportStart"));

        gridLayout_3->addWidget(comboBoxTransportStart, 1, 1, 1, 2);

        label_5 = new QLabel(widgetAddTourist_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        comboBoxTransportDes = new QComboBox(widgetAddTourist_3);
        comboBoxTransportDes->setObjectName(QString::fromUtf8("comboBoxTransportDes"));

        gridLayout_3->addWidget(comboBoxTransportDes, 2, 1, 1, 2);

        label_7 = new QLabel(widgetAddTourist_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        label_9 = new QLabel(widgetAddTourist_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 4, 0, 1, 1);

        lineEditTransportStartTime = new QLineEdit(widgetAddTourist_3);
        lineEditTransportStartTime->setObjectName(QString::fromUtf8("lineEditTransportStartTime"));

        gridLayout_3->addWidget(lineEditTransportStartTime, 4, 2, 1, 1);

        label_8 = new QLabel(widgetAddTourist_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 5, 0, 1, 1);

        lineEditTransportTimecost = new QLineEdit(widgetAddTourist_3);
        lineEditTransportTimecost->setObjectName(QString::fromUtf8("lineEditTransportTimecost"));

        gridLayout_3->addWidget(lineEditTransportTimecost, 5, 2, 1, 1);

        pushButtonAddTransport = new QPushButton(widgetAddTourist_3);
        pushButtonAddTransport->setObjectName(QString::fromUtf8("pushButtonAddTransport"));

        gridLayout_3->addWidget(pushButtonAddTransport, 6, 0, 1, 2);

        lineEditTransportRisk = new QLineEdit(widgetAddTourist_3);
        lineEditTransportRisk->setObjectName(QString::fromUtf8("lineEditTransportRisk"));

        gridLayout_3->addWidget(lineEditTransportRisk, 3, 2, 1, 1);

        tableWidgetTourist = new QTableWidget(centralwidget);
        tableWidgetTourist->setObjectName(QString::fromUtf8("tableWidgetTourist"));
        tableWidgetTourist->setGeometry(QRect(760, 20, 171, 192));
        treeWidgetCity = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetCity->setHeaderItem(__qtreewidgetitem);
        treeWidgetCity->setObjectName(QString::fromUtf8("treeWidgetCity"));
        treeWidgetCity->setGeometry(QRect(760, 270, 171, 192));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        labelMap->setText(QCoreApplication::translate("MainWindow", "labelMap", nullptr));
        labelAddTourist->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\205\345\256\242\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\217\221\347\202\271\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\231\220(\345\260\217\346\227\266):", nullptr));
        pushButtonAddTourist->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\205\345\256\242", nullptr));
        labelAddTourist_2->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\237\216\345\270\202\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\237\216\345\270\202\345\220\215\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\243\216\351\231\251\345\200\274\357\274\232", nullptr));
        pushButtonAddCity->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\237\216\345\270\202", nullptr));
        labelAddTourist_3->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\266\345\210\273\350\241\250\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\247\213\345\217\221\347\253\231\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\247\213\345\217\221\347\253\231\357\274\232", nullptr));
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
