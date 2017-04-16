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
    QTableView *tableView_insert1;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_insert1;
    QTableView *tableView_insert1_type;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *tab_2;
    QWidget *tab;
    QWidget *card;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BookSystemClass)
    {
        if (BookSystemClass->objectName().isEmpty())
            BookSystemClass->setObjectName(QStringLiteral("BookSystemClass"));
        BookSystemClass->resize(819, 595);
        centralWidget = new QWidget(BookSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 791, 501));
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
        tableView_select->setGeometry(QRect(10, 110, 761, 351));
        pushButton_serach = new QPushButton(search);
        pushButton_serach->setObjectName(QStringLiteral("pushButton_serach"));
        pushButton_serach->setGeometry(QRect(680, 40, 75, 23));
        pushButton_serach_empty = new QPushButton(search);
        pushButton_serach_empty->setObjectName(QStringLiteral("pushButton_serach_empty"));
        pushButton_serach_empty->setGeometry(QRect(570, 40, 75, 23));
        checkBox = new QCheckBox(search);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(660, 15, 101, 16));
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
        gridLayoutWidget->setGeometry(QRect(370, 70, 391, 31));
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
        label_4->setGeometry(QRect(340, 80, 24, 12));
        plainTextEdit = new QPlainTextEdit(search);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 40, 271, 51));
        tabWidget->addTab(search, QString());
        insert = new QWidget();
        insert->setObjectName(QStringLiteral("insert"));
        tableView_insert1 = new QTableView(insert);
        tableView_insert1->setObjectName(QStringLiteral("tableView_insert1"));
        tableView_insert1->setGeometry(QRect(120, 110, 651, 351));
        gridLayoutWidget_2 = new QWidget(insert);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 681, 41));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_2->addWidget(lineEdit_5, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 4, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 0, 5, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 0, 6, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_2->addWidget(lineEdit_6, 1, 2, 1, 1);

        lineEdit_7 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_2->addWidget(lineEdit_7, 1, 3, 1, 1);

        lineEdit_8 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_2->addWidget(lineEdit_8, 1, 4, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_2->addWidget(lineEdit_9, 1, 5, 1, 1);

        lineEdit_10 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_2->addWidget(lineEdit_10, 1, 6, 1, 1);

        pushButton_insert1 = new QPushButton(insert);
        pushButton_insert1->setObjectName(QStringLiteral("pushButton_insert1"));
        pushButton_insert1->setGeometry(QRect(660, 70, 75, 23));
        tableView_insert1_type = new QTableView(insert);
        tableView_insert1_type->setObjectName(QStringLiteral("tableView_insert1_type"));
        tableView_insert1_type->setGeometry(QRect(10, 130, 91, 331));
        plainTextEdit_2 = new QPlainTextEdit(insert);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(10, 70, 531, 31));
        label_12 = new QLabel(insert);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 110, 92, 13));
        label_13 = new QLabel(insert);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(500, 0, 281, 20));
        tabWidget->addTab(insert, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        card = new QWidget();
        card->setObjectName(QStringLiteral("card"));
        tabWidget->addTab(card, QString());
        BookSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BookSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 23));
        BookSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BookSystemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BookSystemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BookSystemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BookSystemClass->setStatusBar(statusBar);

        retranslateUi(BookSystemClass);

        tabWidget->setCurrentIndex(1);


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
        label_5->setText(QApplication::translate("BookSystemClass", "\344\271\246\345\220\215", 0));
        label_7->setText(QApplication::translate("BookSystemClass", "\345\207\272\347\211\210\347\244\276", 0));
        label_6->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        label_8->setText(QApplication::translate("BookSystemClass", "\344\275\234\350\200\205", 0));
        label_9->setText(QApplication::translate("BookSystemClass", "\345\207\272\347\211\210\345\271\264\344\273\275", 0));
        label_10->setText(QApplication::translate("BookSystemClass", "\344\273\267\346\240\274", 0));
        label_11->setText(QApplication::translate("BookSystemClass", "\346\225\260\351\207\217", 0));
        pushButton_insert1->setText(QApplication::translate("BookSystemClass", "\346\217\222\345\205\245", 0));
        label_12->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        label_13->setText(QApplication::translate("BookSystemClass", "\345\246\202\346\236\234\344\277\241\346\201\257\345\256\214\345\205\250\347\233\270\345\220\214\345\210\231\350\207\252\345\212\250\345\220\210\345\271\266,ID\346\240\271\346\215\256\347\261\273\345\210\253\350\207\252\345\212\250\347\224\237\346\210\220", 0));
        tabWidget->setTabText(tabWidget->indexOf(insert), QApplication::translate("BookSystemClass", "\345\215\225\346\234\254\345\205\245\345\272\223", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BookSystemClass", "\346\211\271\351\207\217\345\205\245\345\272\223", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BookSystemClass", "\345\200\237\345\207\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(card), QApplication::translate("BookSystemClass", "\345\200\237\351\230\205\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class BookSystemClass: public Ui_BookSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSYSTEM_H
