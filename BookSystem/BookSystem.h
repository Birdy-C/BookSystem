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
	QString manager_name;
	bool load_statues;
	void insert2_line_temp(QString);
	bool SL_insert_book(QString Type, QString Title, QString Publisher, QString Publish_year, QString  Author, QString Price, QString Number);
	void borrow_renew();
	bool checkManager();
	Ui::BookSystemClass ui;
	QSqlDatabase db;
	QSqlTableModel *select_model;//
	QSqlTableModel *select_model_insert1;
	QSqlTableModel *select_model_insert1_tp;
	QSqlTableModel *select_model_insert2;
	QSqlTableModel *select_model_borrow_book;
	QSqlTableModel *select_model_borrow_ID;
	QSqlTableModel *select_model_borrow_info;
	QSqlTableModel *select_model_user;
	QSqlTableModel *select_model_View_info;
	QSqlTableModel *select_model_View_info_2;


	//µÇÂ¼
	QPushButton *pushButton_back;


public slots:
	void SL_rollback();
	void SL_transaction();


	void empty(int);
	void SL_search_book(const QString &);
	void SL_search_book_order();
	void SL_search_book_reset();
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
	void SL_borrow_select(const QModelIndex &, const QModelIndex &);
	void SL_borrow();
	void SL_borrow_return();
	void SL_user_insert();
	void SL_user_select(const QString &);
	void SL_user_delete();
	void SL_user_loadin();
	void SL_user_checkout();

};


