/*
@author: Birdy&C 2017.4.15

初始化
*/
#include "stdafx.h"
#include "BookSystem.h"

BookSystem::BookSystem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initSQL();
	initMotion();
}

BookSystem::~BookSystem()
{
	delete select_model;
}

bool BookSystem::initSQL() 
{
	/*---- LOAD IN DASTABASE ----*/
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("DBSYSTEM.db");
	if (!db.open()) {
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
		qDebug() << QString("LOAD_IN");
		return false;
	}

	QSqlQuery query("SELECT * FROM book");
	if (!query.isActive()) 
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), db.lastError().text());
	}
	while (query.next()) 
	{
		QString country = query.value(0).toString();
	}

	/*---- INIT TABLE & VIEW ----*/
	select_model = new QSqlTableModel(this);
	select_model->setTable("book");
	select_model->select();
	ui.tableView_select->setModel(select_model);
	ui.tableView_select->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
	ui.tableView_select->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中

	return true;
}


void BookSystem::initMotion() 
{
	connect(ui.pushButton_serach, SIGNAL(clicked()),this, SLOT(SL_search_book()));

	connect(ui.checkBox_2, SIGNAL(released()), this, SLOT(SL_search_book_order()));

	connect(ui.radioButton, SIGNAL(released()), this, SLOT(SL_search_book_order()));
	connect(ui.radioButton_2, SIGNAL(released()), this, SLOT(SL_search_book_order()));
	connect(ui.radioButton_3, SIGNAL(released()), this, SLOT(SL_search_book_order()));
	connect(ui.radioButton_4, SIGNAL(released()), this, SLOT(SL_search_book_order()));


}