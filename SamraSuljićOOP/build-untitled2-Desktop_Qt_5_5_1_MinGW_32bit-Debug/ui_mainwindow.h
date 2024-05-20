/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *redniBroj;
    QTableView *tableView;
    QLabel *label;
    QTableView *tableView_2;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_2;
    QPushButton *pushButton_add;
    QLabel *label_ukupnaPotrosnja;
    QLabel *label_8;
    QLabel *label_11;
    QLineEdit *inventurniBroj;
    QPushButton *pushButton_sljedeciMjesec;
    QPushButton *pushButton_update;
    QSpinBox *spinBox_godina;
    QLineEdit *trenutnoStanje;
    QLineEdit *lokacija;
    QLabel *label_4;
    QSpinBox *spinBox_mjesec;
    QLineEdit *prethodnoStanje;
    QLabel *label_10;
    QLabel *label_3;
    QLineEdit *serijskiBroj;
    QLineEdit *modelPrintera;
    QLabel *label_5;
    QLineEdit *osoba;
    QPushButton *pushButton_delete;
    QLabel *label_serijski;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(853, 387);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        redniBroj = new QLineEdit(centralWidget);
        redniBroj->setObjectName(QStringLiteral("redniBroj"));

        gridLayout->addWidget(redniBroj, 2, 1, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 2, 12, 8);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        tableView_2 = new QTableView(centralWidget);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));

        gridLayout->addWidget(tableView_2, 1, 10, 12, 3);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 4, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 12, 0, 1, 2);

        label_ukupnaPotrosnja = new QLabel(centralWidget);
        label_ukupnaPotrosnja->setObjectName(QStringLiteral("label_ukupnaPotrosnja"));

        gridLayout->addWidget(label_ukupnaPotrosnja, 13, 12, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 14, 4, 1, 1);

        inventurniBroj = new QLineEdit(centralWidget);
        inventurniBroj->setObjectName(QStringLiteral("inventurniBroj"));

        gridLayout->addWidget(inventurniBroj, 4, 1, 1, 1);

        pushButton_sljedeciMjesec = new QPushButton(centralWidget);
        pushButton_sljedeciMjesec->setObjectName(QStringLiteral("pushButton_sljedeciMjesec"));

        gridLayout->addWidget(pushButton_sljedeciMjesec, 14, 6, 1, 1);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));

        gridLayout->addWidget(pushButton_update, 13, 0, 1, 2);

        spinBox_godina = new QSpinBox(centralWidget);
        spinBox_godina->setObjectName(QStringLiteral("spinBox_godina"));
        spinBox_godina->setReadOnly(true);
        spinBox_godina->setMinimum(2023);
        spinBox_godina->setMaximum(2029);

        gridLayout->addWidget(spinBox_godina, 14, 5, 1, 1);

        trenutnoStanje = new QLineEdit(centralWidget);
        trenutnoStanje->setObjectName(QStringLiteral("trenutnoStanje"));

        gridLayout->addWidget(trenutnoStanje, 9, 1, 1, 1);

        lokacija = new QLineEdit(centralWidget);
        lokacija->setObjectName(QStringLiteral("lokacija"));

        gridLayout->addWidget(lokacija, 6, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        spinBox_mjesec = new QSpinBox(centralWidget);
        spinBox_mjesec->setObjectName(QStringLiteral("spinBox_mjesec"));
        spinBox_mjesec->setReadOnly(true);
        spinBox_mjesec->setMinimum(1);
        spinBox_mjesec->setMaximum(12);

        gridLayout->addWidget(spinBox_mjesec, 14, 3, 1, 1);

        prethodnoStanje = new QLineEdit(centralWidget);
        prethodnoStanje->setObjectName(QStringLiteral("prethodnoStanje"));

        gridLayout->addWidget(prethodnoStanje, 8, 1, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 14, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        serijskiBroj = new QLineEdit(centralWidget);
        serijskiBroj->setObjectName(QStringLiteral("serijskiBroj"));

        gridLayout->addWidget(serijskiBroj, 3, 1, 1, 1);

        modelPrintera = new QLineEdit(centralWidget);
        modelPrintera->setObjectName(QStringLiteral("modelPrintera"));

        gridLayout->addWidget(modelPrintera, 5, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        osoba = new QLineEdit(centralWidget);
        osoba->setObjectName(QStringLiteral("osoba"));

        gridLayout->addWidget(osoba, 7, 1, 1, 1);

        pushButton_delete = new QPushButton(centralWidget);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        gridLayout->addWidget(pushButton_delete, 14, 0, 1, 2);

        label_serijski = new QLabel(centralWidget);
        label_serijski->setObjectName(QStringLiteral("label_serijski"));

        gridLayout->addWidget(label_serijski, 0, 11, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 0, 10, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 853, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Redni broj", 0));
        label_9->setText(QApplication::translate("MainWindow", "Lista printera", 0));
        label_6->setText(QApplication::translate("MainWindow", "Prethodno stanje broja\304\215a", 0));
        label_7->setText(QApplication::translate("MainWindow", "Trenutno stanje broja\304\215a", 0));
        label_2->setText(QApplication::translate("MainWindow", "Serijski broj", 0));
        pushButton_add->setText(QApplication::translate("MainWindow", "Dodaj", 0));
        label_ukupnaPotrosnja->setText(QApplication::translate("MainWindow", "Ukupna potro\305\241nja", 0));
        label_8->setText(QApplication::translate("MainWindow", "Lokacija", 0));
        label_11->setText(QApplication::translate("MainWindow", "Godina", 0));
        pushButton_sljedeciMjesec->setText(QApplication::translate("MainWindow", "Sljede\304\207i mjesec", 0));
        pushButton_update->setText(QApplication::translate("MainWindow", "Update", 0));
        label_4->setText(QApplication::translate("MainWindow", "Model Printera", 0));
        label_10->setText(QApplication::translate("MainWindow", "Mjesec", 0));
        label_3->setText(QApplication::translate("MainWindow", "Inventurni broj", 0));
        label_5->setText(QApplication::translate("MainWindow", "Zadu\305\276ena Osoba", 0));
        pushButton_delete->setText(QApplication::translate("MainWindow", "Obri\305\241i", 0));
        label_serijski->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Serijski bro\305\241tampa\304\215a:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
