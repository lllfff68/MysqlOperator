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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *localhost;
    QLineEdit *username;
    QLabel *label_5;
    QLineEdit *IP;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *passwd;
    QLabel *label_3;
    QPushButton *connectButton;
    QLineEdit *DBname;
    QTableView *table;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *refreash;
    QPushButton *addbutton;
    QPushButton *deletebutton;
    QPushButton *changebutton;
    QPushButton *querybutton;
    QComboBox *selectbox;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 20, 711, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        localhost = new QLineEdit(gridLayoutWidget);
        localhost->setObjectName(QString::fromUtf8("localhost"));

        gridLayout_2->addWidget(localhost, 0, 4, 1, 1);

        username = new QLineEdit(gridLayoutWidget);
        username->setObjectName(QString::fromUtf8("username"));

        gridLayout_2->addWidget(username, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 6, 1, 1);

        IP = new QLineEdit(gridLayoutWidget);
        IP->setObjectName(QString::fromUtf8("IP"));

        gridLayout_2->addWidget(IP, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 5, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        passwd = new QLineEdit(gridLayoutWidget);
        passwd->setObjectName(QString::fromUtf8("passwd"));

        gridLayout_2->addWidget(passwd, 1, 4, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        connectButton = new QPushButton(gridLayoutWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout_2->addWidget(connectButton, 0, 6, 1, 2);

        DBname = new QLineEdit(gridLayoutWidget);
        DBname->setObjectName(QString::fromUtf8("DBname"));

        gridLayout_2->addWidget(DBname, 1, 7, 1, 1);

        DBname->raise();
        localhost->raise();
        username->raise();
        label_5->raise();
        IP->raise();
        label->raise();
        label_2->raise();
        label_4->raise();
        passwd->raise();
        label_3->raise();
        connectButton->raise();
        table = new QTableView(centralwidget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(50, 150, 511, 371));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(600, 230, 160, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        refreash = new QPushButton(verticalLayoutWidget);
        refreash->setObjectName(QString::fromUtf8("refreash"));

        verticalLayout->addWidget(refreash);

        addbutton = new QPushButton(verticalLayoutWidget);
        addbutton->setObjectName(QString::fromUtf8("addbutton"));
        addbutton->setAutoDefault(false);

        verticalLayout->addWidget(addbutton);

        deletebutton = new QPushButton(verticalLayoutWidget);
        deletebutton->setObjectName(QString::fromUtf8("deletebutton"));

        verticalLayout->addWidget(deletebutton);

        changebutton = new QPushButton(verticalLayoutWidget);
        changebutton->setObjectName(QString::fromUtf8("changebutton"));

        verticalLayout->addWidget(changebutton);

        querybutton = new QPushButton(verticalLayoutWidget);
        querybutton->setObjectName(QString::fromUtf8("querybutton"));

        verticalLayout->addWidget(querybutton);

        selectbox = new QComboBox(centralwidget);
        selectbox->setObjectName(QString::fromUtf8("selectbox"));
        selectbox->setGeometry(QRect(600, 150, 161, 22));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        refreash->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\350\241\250\346\240\274", nullptr));
        addbutton->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240\346\225\260\346\215\256", nullptr));
        deletebutton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        changebutton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\225\260\346\215\256", nullptr));
        querybutton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
