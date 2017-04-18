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
    QWidget *tab_1;
    QLineEdit *lineEdit;
    QLabel *label;
    QTableView *tableView_select;
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
    QWidget *tab_2;
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
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_delete;
    QLabel *label_14;
    QLineEdit *lineEdit_11;
    QWidget *tab_3;
    QTableView *tableView_insert2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *tab_4;
    QTableView *tableView_borrow;
    QLabel *label_15;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_10;
    QLabel *label_17;
    QLineEdit *lineEdit_14;
    QTableView *tableView_borrow_book;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QTableView *tableView_borrow_info;
    QPushButton *pushButton_11;
    QWidget *tab_5;
    QLabel *label_16;
    QLineEdit *lineEdit_13;
    QTableView *tableView_user;
    QPushButton *pushButton_8;
    QWidget *tab_6;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_23;
    QLabel *label_22;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QLabel *label_21;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton_9;
    QWidget *tab_7;
    QTableView *tableView_info;
    QWidget *tab_8;
    QTableView *tableView_info_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPlainTextEdit *plainTextEdit_3;
    QPushButton *pushButton_12;
    QLabel *label_24;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLabel *label_25;
    QLabel *label_26;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BookSystemClass)
    {
        if (BookSystemClass->objectName().isEmpty())
            BookSystemClass->setObjectName(QStringLiteral("BookSystemClass"));
        BookSystemClass->resize(820, 620);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BookSystemClass->sizePolicy().hasHeightForWidth());
        BookSystemClass->setSizePolicy(sizePolicy);
        BookSystemClass->setMinimumSize(QSize(820, 620));
        BookSystemClass->setMaximumSize(QSize(820, 620));
        centralWidget = new QWidget(BookSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 40, 791, 511));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        lineEdit = new QLineEdit(tab_1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 10, 113, 20));
        label = new QLabel(tab_1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 24, 12));
        tableView_select = new QTableView(tab_1);
        tableView_select->setObjectName(QStringLiteral("tableView_select"));
        tableView_select->setGeometry(QRect(10, 110, 761, 361));
        pushButton_serach_empty = new QPushButton(tab_1);
        pushButton_serach_empty->setObjectName(QStringLiteral("pushButton_serach_empty"));
        pushButton_serach_empty->setGeometry(QRect(540, 10, 75, 23));
        checkBox = new QCheckBox(tab_1);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(660, 15, 101, 16));
        label_2 = new QLabel(tab_1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 15, 24, 12));
        lineEdit_2 = new QLineEdit(tab_1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 10, 113, 20));
        lineEdit_3 = new QLineEdit(tab_1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(380, 10, 113, 20));
        label_3 = new QLabel(tab_1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 15, 24, 12));
        gridLayoutWidget = new QWidget(tab_1);
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

        label_4 = new QLabel(tab_1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 80, 24, 12));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView_insert1 = new QTableView(tab_2);
        tableView_insert1->setObjectName(QStringLiteral("tableView_insert1"));
        tableView_insert1->setGeometry(QRect(120, 110, 651, 361));
        gridLayoutWidget_2 = new QWidget(tab_2);
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

        pushButton_insert1 = new QPushButton(tab_2);
        pushButton_insert1->setObjectName(QStringLiteral("pushButton_insert1"));
        pushButton_insert1->setGeometry(QRect(700, 30, 75, 23));
        tableView_insert1_type = new QTableView(tab_2);
        tableView_insert1_type->setObjectName(QStringLiteral("tableView_insert1_type"));
        tableView_insert1_type->setGeometry(QRect(10, 130, 91, 341));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 110, 92, 13));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(470, 0, 311, 20));
        pushButton_delete = new QPushButton(tab_2);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(700, 75, 75, 23));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(605, 65, 54, 12));
        lineEdit_11 = new QLineEdit(tab_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(600, 80, 91, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableView_insert2 = new QTableView(tab_3);
        tableView_insert2->setObjectName(QStringLiteral("tableView_insert2"));
        tableView_insert2->setGeometry(QRect(20, 40, 751, 431));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 10, 75, 23));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(680, 10, 75, 23));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(120, 10, 75, 23));
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(270, 10, 75, 23));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tableView_borrow = new QTableView(tab_4);
        tableView_borrow->setObjectName(QStringLiteral("tableView_borrow"));
        tableView_borrow->setGeometry(QRect(20, 120, 751, 181));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 30, 54, 12));
        lineEdit_12 = new QLineEdit(tab_4);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(80, 25, 92, 20));
        pushButton_10 = new QPushButton(tab_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(190, 65, 75, 23));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 70, 54, 12));
        lineEdit_14 = new QLineEdit(tab_4);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(80, 65, 92, 20));
        tableView_borrow_book = new QTableView(tab_4);
        tableView_borrow_book->setObjectName(QStringLiteral("tableView_borrow_book"));
        tableView_borrow_book->setGeometry(QRect(20, 350, 751, 121));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 100, 54, 12));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 320, 54, 12));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(270, 20, 54, 12));
        tableView_borrow_info = new QTableView(tab_4);
        tableView_borrow_info->setObjectName(QStringLiteral("tableView_borrow_info"));
        tableView_borrow_info->setGeometry(QRect(330, 20, 431, 61));
        pushButton_11 = new QPushButton(tab_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(690, 90, 75, 23));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_16 = new QLabel(tab_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 30, 54, 12));
        lineEdit_13 = new QLineEdit(tab_5);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(80, 25, 92, 20));
        tableView_user = new QTableView(tab_5);
        tableView_user->setObjectName(QStringLiteral("tableView_user"));
        tableView_user->setGeometry(QRect(10, 110, 761, 351));
        pushButton_8 = new QPushButton(tab_5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(680, 70, 75, 23));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayoutWidget_3 = new QWidget(tab_6);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(290, 210, 181, 85));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(gridLayoutWidget_3);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_3->addWidget(label_23, 2, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_3);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_3->addWidget(label_22, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        radioButton_5 = new QRadioButton(gridLayoutWidget_3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        gridLayout_4->addWidget(radioButton_5, 0, 1, 1, 1);

        radioButton_6 = new QRadioButton(gridLayoutWidget_3);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setChecked(true);

        gridLayout_4->addWidget(radioButton_6, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 2, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 1, 0, 1, 1);

        lineEdit_15 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout_3->addWidget(lineEdit_15, 0, 1, 1, 1);

        lineEdit_16 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        gridLayout_3->addWidget(lineEdit_16, 1, 1, 1, 1);

        pushButton_9 = new QPushButton(tab_6);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(400, 310, 75, 23));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tableView_info = new QTableView(tab_7);
        tableView_info->setObjectName(QStringLiteral("tableView_info"));
        tableView_info->setGeometry(QRect(10, 10, 761, 461));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tableView_info_2 = new QTableView(tab_8);
        tableView_info_2->setObjectName(QStringLiteral("tableView_info_2"));
        tableView_info_2->setGeometry(QRect(10, 10, 761, 461));
        tabWidget->addTab(tab_8, QString());
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(720, 10, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 10, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 75, 23));
        plainTextEdit_3 = new QPlainTextEdit(centralWidget);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(170, 10, 341, 31));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(720, 25, 75, 23));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(600, 10, 120, 12));
        lineEdit_17 = new QLineEdit(centralWidget);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(600, 30, 113, 20));
        lineEdit_18 = new QLineEdit(centralWidget);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(600, 5, 113, 20));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(560, 10, 24, 12));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(560, 35, 54, 12));
        BookSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BookSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 23));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("BookSystemClass", "\346\243\200\347\264\242", 0));
        label_5->setText(QApplication::translate("BookSystemClass", "\344\271\246\345\220\215", 0));
        label_7->setText(QApplication::translate("BookSystemClass", "\345\207\272\347\211\210\347\244\276", 0));
        label_6->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        label_8->setText(QApplication::translate("BookSystemClass", "\344\275\234\350\200\205", 0));
        label_9->setText(QApplication::translate("BookSystemClass", "\345\207\272\347\211\210\345\271\264\344\273\275", 0));
        label_10->setText(QApplication::translate("BookSystemClass", "\344\273\267\346\240\274", 0));
        label_11->setText(QApplication::translate("BookSystemClass", "\346\225\260\351\207\217", 0));
        pushButton_insert1->setText(QApplication::translate("BookSystemClass", "\346\217\222\345\205\245", 0));
        label_12->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        label_13->setText(QApplication::translate("BookSystemClass", "\345\246\202\346\236\234\344\277\241\346\201\257\345\256\214\345\205\250\347\233\270\345\220\214\345\210\231\350\207\252\345\212\250\345\220\210\345\271\266,\346\217\222\345\205\245\346\227\266ID\346\240\271\346\215\256\347\261\273\345\210\253\350\207\252\345\212\250\347\224\237\346\210\220", 0));
        pushButton_delete->setText(QApplication::translate("BookSystemClass", "\345\210\240\351\231\244", 0));
        label_14->setText(QApplication::translate("BookSystemClass", "ID", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BookSystemClass", "\345\215\225\346\234\254\346\217\222\345\205\245/\345\210\240\351\231\244", 0));
        pushButton_4->setText(QApplication::translate("BookSystemClass", "\350\257\273\345\217\226", 0));
        pushButton_5->setText(QApplication::translate("BookSystemClass", "\346\217\222\345\205\245", 0));
        pushButton_6->setText(QApplication::translate("BookSystemClass", "\346\270\205\347\251\272", 0));
        pushButton_7->setText(QApplication::translate("BookSystemClass", "\345\210\240\351\231\244\346\255\244\346\235\241", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("BookSystemClass", "\346\211\271\351\207\217\345\205\245\345\272\223", 0));
        label_15->setText(QApplication::translate("BookSystemClass", "card_ID", 0));
        pushButton_10->setText(QApplication::translate("BookSystemClass", "\345\200\237\344\271\246", 0));
        label_17->setText(QApplication::translate("BookSystemClass", "book_ID", 0));
        label_18->setText(QApplication::translate("BookSystemClass", "\345\200\237\344\271\246\350\256\260\345\275\225", 0));
        label_19->setText(QApplication::translate("BookSystemClass", "\344\271\246\347\233\256\346\265\217\350\247\210", 0));
        label_20->setText(QApplication::translate("BookSystemClass", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        pushButton_11->setText(QApplication::translate("BookSystemClass", "\350\277\230\344\271\246", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("BookSystemClass", "\345\200\237\351\230\205\347\256\241\347\220\206", 0));
        label_16->setText(QApplication::translate("BookSystemClass", "card_ID", 0));
        pushButton_8->setText(QApplication::translate("BookSystemClass", "\345\210\240\351\231\244", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("BookSystemClass", "\347\224\250\346\210\267\344\277\241\346\201\257\347\256\241\347\220\206", 0));
        label_23->setText(QApplication::translate("BookSystemClass", "\347\261\273\345\210\253", 0));
        label_22->setText(QApplication::translate("BookSystemClass", "\347\224\250\346\210\267\345\220\215", 0));
        radioButton_5->setText(QApplication::translate("BookSystemClass", "\350\200\201\345\270\210", 0));
        radioButton_6->setText(QApplication::translate("BookSystemClass", "\345\255\246\347\224\237", 0));
        label_21->setText(QApplication::translate("BookSystemClass", "\345\215\225\344\275\215", 0));
        pushButton_9->setText(QApplication::translate("BookSystemClass", "\346\226\260\345\273\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("BookSystemClass", "\345\210\233\345\273\272\347\224\250\346\210\267", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("BookSystemClass", "\351\241\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("BookSystemClass", "\351\241\265", 0));
        pushButton->setText(QApplication::translate("BookSystemClass", "\351\200\200\345\207\272", 0));
        pushButton_2->setText(QApplication::translate("BookSystemClass", "\346\222\244\351\224\200\346\223\215\344\275\234", 0));
        pushButton_3->setText(QApplication::translate("BookSystemClass", "\344\277\235\345\255\230", 0));
        pushButton_12->setText(QApplication::translate("BookSystemClass", "\347\231\273\345\275\225", 0));
        label_24->setText(QApplication::translate("BookSystemClass", "TextLabel", 0));
        label_25->setText(QApplication::translate("BookSystemClass", "\350\264\246\345\217\267", 0));
        label_26->setText(QApplication::translate("BookSystemClass", "\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class BookSystemClass: public Ui_BookSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSYSTEM_H
