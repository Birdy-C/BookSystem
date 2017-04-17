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

/**/
void BookSystem::empty(int)
{
	// part NO.1
	SL_search_book_empty();
	void SL_search_book();

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
	//NO1 SELECT
	select_model = new QSqlTableModel(this);
	select_model->setTable("book");
	select_model->select();
	ui.tableView_select->setModel(select_model);
	ui.tableView_select->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
	ui.tableView_select->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中

	//NO2 INSERT1
	select_model_insert1 = new QSqlTableModel(this);
	select_model_insert1->setTable("book");
	//select_model_insert1->removeColumns(7, 2);	//remove Number & Stocks
	//select_model_insert1->removeColumn(0);		//remove Book_id

	select_model_insert1->select();
	ui.tableView_insert1->setModel(select_model_insert1);
	ui.tableView_insert1->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
	ui.tableView_insert1->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中

	select_model_insert1_tp = new QSqlTableModel(this);
	select_model_insert1_tp->setTable("type");
	select_model_insert1_tp->select();
	select_model_insert1_tp->removeColumn(1);
	ui.tableView_insert1_type->setModel(select_model_insert1_tp);
	ui.tableView_insert1_type->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
	ui.tableView_insert1_type->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中


	return true;
}

/* 初始化信号和槽 */
void BookSystem::initMotion() 
{
	//
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(empty(int)));


	//NO.1 SELECT
	connect(ui.pushButton_serach, SIGNAL(clicked()),this, SLOT(SL_search_book()));
	connect(ui.pushButton_serach_empty, SIGNAL(clicked()), this, SLOT(SL_search_book_empty()));

	connect(ui.checkBox_2, SIGNAL(released()), this, SLOT(SL_search_book_order()));

	connect(ui.radioButton, SIGNAL(released()), this, SLOT(SL_search_book_order()));
	connect(ui.radioButton_2, SIGNAL(released()), this, SLOT(SL_search_book_order()));
	connect(ui.radioButton_3, SIGNAL(released()), this, SLOT(SL_search_book_order()));
	connect(ui.radioButton_4, SIGNAL(released()), this, SLOT(SL_search_book_order()));

	//NO 2 INSERT1
	connect(ui.pushButton_insert1, SIGNAL(clicked()), this, SLOT(SL_insert1()));
	connect(ui.pushButton_delete, SIGNAL(clicked()), this, SLOT(SL_delete()));
	connect(ui.lineEdit_4, SIGNAL(textEdited(const QString & )), this, SLOT(SL_insert1_change(const QString & )));
	connect(ui.lineEdit_11, SIGNAL(textChanged(const QString & )), this, SLOT(SL_insert1_IDchange(const QString & )));

	//这两行注意model改变
	connect(ui.tableView_insert1->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)), 
		this, SLOT(SL_insert1_selectBook(const QModelIndex &, const QModelIndex &)));
	connect(ui.tableView_insert1_type->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
		this, SLOT(SL_insert1_selectType(const QModelIndex &, const QModelIndex &)));
}

