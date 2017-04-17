/*
@author: Birdy&C 2017.4.15
*/
#pragma once
#include <iostream>
#include <QtWidgets/QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>  
#include <QDate>
#include "ui_BookSystem.h"

using namespace std;

class Ui_Dialog : public QMainWindow
{
public:
	QDialogButtonBox *buttonBox;
	QWidget *gridLayoutWidget_2;
	QGridLayout *gridLayout_2;
	QLabel *label_2;
	QLabel *label;
	QLabel *label_3;
	QGridLayout *gridLayout;
	QRadioButton *radioButton_2;
	QRadioButton *radioButton;

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QStringLiteral("Dialog"));
		Dialog->resize(320, 100);
		Dialog->setMinimumSize(QSize(320, 100));
		Dialog->setMaximumSize(QSize(320, 100));
		buttonBox = new QDialogButtonBox(Dialog);
		buttonBox->setObjectName(QStringLiteral("buttonBox"));
		buttonBox->setGeometry(QRect(235, 40, 80, 50));
		buttonBox->setOrientation(Qt::Vertical);
		buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
		gridLayoutWidget_2 = new QWidget(Dialog);
		gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
		gridLayoutWidget_2->setGeometry(QRect(10, 10, 211, 80));
		gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
		gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
		gridLayout_2->setContentsMargins(0, 0, 0, 0);
		label_2 = new QLabel(gridLayoutWidget_2);
		label_2->setObjectName(QStringLiteral("label_2"));

		gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

		label = new QLabel(gridLayoutWidget_2);
		label->setObjectName(QStringLiteral("label"));

		gridLayout_2->addWidget(label, 0, 0, 1, 1);

		label_3 = new QLabel(gridLayoutWidget_2);
		label_3->setObjectName(QStringLiteral("label_3"));

		gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

		gridLayout = new QGridLayout();
		gridLayout->setObjectName(QStringLiteral("gridLayout"));
		radioButton_2 = new QRadioButton(gridLayoutWidget_2);
		radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

		gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);

		radioButton = new QRadioButton(gridLayoutWidget_2);
		radioButton->setObjectName(QStringLiteral("radioButton"));
		radioButton->setChecked(true);

		gridLayout->addWidget(radioButton, 0, 0, 1, 1);


		gridLayout_2->addLayout(gridLayout, 2, 1, 1, 1);


		retranslateUi(Dialog);
		QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
		QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

		QMetaObject::connectSlotsByName(Dialog);
	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
		label_2->setText(QApplication::translate("Dialog", "\345\215\225\344\275\215", 0));
		label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", 0));
		label_3->setText(QApplication::translate("Dialog", "\347\261\273\345\210\253", 0));
		radioButton_2->setText(QApplication::translate("Dialog", "\350\200\201\345\270\210", 0));
		radioButton->setText(QApplication::translate("Dialog", "\345\255\246\347\224\237", 0));
	} // retranslateUi

};


class BookSystem : public QMainWindow
{
	Q_OBJECT

public:
	BookSystem(QWidget *parent = Q_NULLPTR);
	~BookSystem();
	bool initSQL();//³õÊ¼»¯
	void initMotion();
	void loadIn_Setboard();
private:
	int manager_ID;
	bool load_statues;
	void insert2_line_temp(QString);
	bool SL_insert_book(QString Type, QString Title, QString Publisher, QString Publish_year, QString  Author, QString Price, QString Number);
	void borrow_renew();

	Ui::BookSystemClass ui;
	QSqlDatabase db;
	QSqlTableModel *select_model;//
	QSqlTableModel *select_model_insert1;
	QSqlTableModel *select_model_insert1_tp;
	QSqlTableModel *select_model_insert2;
	QSqlTableModel *select_model_borrow_book;
	QSqlTableModel *select_model_borrow_ID;
	QSqlTableModel *select_model_borrow_info;

	
	//µÇÂ¼
	QPushButton *pushButton_back;


public slots:
	void SL_rollback();
	void SL_transaction();


	void empty(int);
	void SL_search_book(const QString &);
	void SL_search_book_order();
	void SL_search_book_empty();
	void SL_insert1_empty();
	void SL_insert1_selectType(const QModelIndex &, const QModelIndex &);
	void SL_insert1_selectBook(const QModelIndex &, const QModelIndex &);
	void SL_insert1();
	void SL_delete();
	void SL_insert1_change(const QString & text);
	void SL_insert1_IDchange(const QString & text);
	void SL_readtxt();
	void SL_insert2();
	void SL_insert2_delete();
	void SL_insert2_delete_current();
	void SL_borrow_IDchange(const QString &text);
	void SL_borrow_Bookchange(const QString &text);
	void SL_borrow();
	void SL_borrow_return();
	void SL_user_insert();
};
