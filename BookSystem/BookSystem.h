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
#include <QMessageBox>  
#include "ui_BookSystem.h"

using namespace std;


class BookSystem : public QMainWindow
{
	Q_OBJECT

public:
	BookSystem(QWidget *parent = Q_NULLPTR);
	~BookSystem();
	bool initSQL();//≥ı ºªØ
	void initMotion();

private:
	Ui::BookSystemClass ui;
	QSqlDatabase db;
	QSqlTableModel *select_model;

public slots:
	void SL_search_book();
	void SL_search_book_order();
	void SL_search_book_empty();

};
