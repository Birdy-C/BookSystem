/********************************************************************************
** Form generated from reading UI file 'BookSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSYSTEM_H
#define UI_BOOKSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookSystemClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *search;
    QLineEdit *lineEdit;
    QLabel *label;
    QTableView *tableView_select;
    QPushButton *pushButton_serach;
    QPushButton *pushButton_serach_empty;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QCheckBox *checkBox_2;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit;
    QWidget *insert;
    QWidget *tab;
    QWidget *card;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BookSystemClass)
    {
        if (BookSystemClass->objectName().isEmpty())
            BookSystemClass->setObjectName(QStringLiteral("BookSystemClass"));
        BookSystemClass->resize(683, 595);
        centralWidget = new QWidget(BookSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 641, 501));
        search = new QWidget();
        search->setObjectName(QStringLiteral("search"));
        lineEdit = new QLineEdit(search);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 10, 113, 20));
        label = new QLabel(search);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 24, 12));
        tableView_select = new QTableView(search);
        tableView_select->setObjectName(QStringLiteral("tableView_select"));
        tableView_select->setGeometry(QRect(10, 110, 611, 351));
        pushButton_serach = new QPushButton(search);
        pushButton_serach->setObjectName(QStringLiteral("pushButton_serach"));
        pushButton_serach->setGeometry(QRect(540, 40, 75, 23));
        pushButton_serach_empty = new QPushButton(search);
        pushButton_serach_empty->setObjectName(QStringLiteral("pushButton_serach_empty"));
        pushButton_serach_empty->setGeometry(QRect(440, 40, 75, 23));
        checkBox = new QCheckBox(search);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(530, 20, 101, 16));
        label_2 = new QLabel(search);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 15, 24, 12));
        lineEdit_2 = new QLineEdit(search);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 10, 113, 20));
        lineEdit_3 = new QLineEdit(search);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(380, 10, 113, 20));
        label_3 = new QLabel(search);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 15, 24, 12));
        gridLayoutWidget = new QWidget(search);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(230, 70, 391, 31));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(gridLayoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setChecked(true);

        gridLayout->addWidget(radioButton_4, 3, 0, 1, 1);

        radioButton_2 = new QRadioButton(gridLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 3, 2, 1, 1);

        radioButton_3 = new QRadioButton(gridLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 3, 3, 1, 1);

        radioButton = new QRadioButton(gridLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 3, 1, 1, 1);

        checkBox_2 = new QCheckBox(gridLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 3, 4, 1, 1);

        label_4 = new QLabel(search);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 80, 24, 12));
        plainTextEdit = new QPlainTextEdit(search);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 30, 221, 51));
        tabWidget->addTab(search, QString());
        lineEdit->raise();
        label->raise();
        tableView_select->raise();
        pushButton_serach->raise();
        pushButton_serach_empty->raise();
        checkBox->raise();
        label_2->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        label_3->raise();
        gridLayoutWidget->raise();
        label_4->raise();
        checkBox_2->raise();
        plainTextEdit->raise();
        insert = new QWidget();
        insert->setObjectName(QStringLiteral("insert"));
        tabWidget->addTab(insert, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        card = new QWidget();
        card->setObjectName(QStringLiteral("card"));
        tabWidget->addTab(card, QString());
        BookSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BookSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 23));
        BookSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BookSystemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BookSystemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BookSystemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BookSystemClass->setStatusBar(statusBar);

        retranslateUi(BookSystemClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BookSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *BookSystemClass)
    {
        BookSystemClass->setWindowTitle(QApplication::translate("BookSystemClass", "BookSystem", 0));
        label->setText(QApplication::translate("BookSystemClass", "\344\271\246\345\220\215", 0));
        pushButton_serach->setText(QApplication::translate("BookSystemClass", " \346\237\245\350\257\242", 0));
        pushButton_serach_empty->setText(QApplication::translate("BookSystemClass", "\346\270\205\347\251\272", 0));
        checkBox->setText(QApplication::translate("BookSystemClass", "\344\273\205\346\230\276\347\244\272\346\234\211\344\275\231\351\207\217", 0));
        label_2->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        label_3->setText(QApplication::translate("BookSystemClass", "\344\275\234\350\200\205", 0));
        radioButton_4->setText(QApplication::translate("BookSystemClass", "\351\273\230\350\256\244", 0));
        radioButton_2->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        radioButton_3->setText(QApplication::translate("BookSystemClass", "\344\275\234\350\200\205", 0));
        radioButton->setText(QApplication::translate("BookSystemClass", "\344\271\246\345\220\215", 0));
        checkBox_2->setText(QApplication::translate("BookSystemClass", "\345\217\215\345\220\221", 0));
        label_4->setText(QApplication::translate("BookSystemClass", "\346\216\222\345\272\217", 0));
        tabWidget->setTabText(tabWidget->indexOf(search), QApplication::translate("BookSystemClass", "\346\243\200\347\264\242", 0));
        tabWidget->setTabText(tabWidget->indexOf(insert), QApplication::translate("BookSystemClass", "\345\205\245\345\272\223", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BookSystemClass", "\345\200\237\345\207\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(card), QApplication::translate("BookSystemClass", "\345\200\237\351\230\205\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class BookSystemClass: public Ui_BookSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSYSTEM_H
