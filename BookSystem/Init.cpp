/*
@author: Birdy&C 2017.4.15

��ʼ�� ��ȫ�ֵ�һЩ����
*/
#include "stdafx.h"
#include "BookSystem.h"

BookSystem::BookSystem(QWidget *parent)
	: QMainWindow(parent), load_statues(false)
{
	ui.setupUi(this);
	initSQL();
	initMotion();
	loadIn_Setboard();

}

BookSystem::~BookSystem()
{
	db.commit(); 
	SL_insert2_delete();
	delete select_model;
}

/*�ڸ��µ�ʱ��Ѹ���ģ�黹ԭ*/
void BookSystem::empty(int)
{
	// part NO.1
	SL_search_book_empty();
	SL_search_book("");
	//part NO.2
	SL_insert1_empty();
	select_model_insert1->select();//������ʾ

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

	if (!db.transaction()) {
		QMessageBox::warning(0, QObject::tr("Database Error"),"driver doesn't support transactions.");
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
	ui.tableView_select->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.tableView_select->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��

	//NO2 INSERT1
	select_model_insert1 = new QSqlTableModel(this);
	select_model_insert1->setTable("book");
	//select_model_insert1->removeColumns(7, 2);	//remove Number & Stocks
	//select_model_insert1->removeColumn(0);		//remove Book_id

	select_model_insert1->select();
	ui.tableView_insert1->setModel(select_model_insert1);
	ui.tableView_insert1->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.tableView_insert1->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��

	select_model_insert1_tp = new QSqlTableModel(this);
	select_model_insert1_tp->setTable("type");
	select_model_insert1_tp->select();
	select_model_insert1_tp->removeColumn(1);
	ui.tableView_insert1_type->setModel(select_model_insert1_tp);
	ui.tableView_insert1_type->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.tableView_insert1_type->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��

	//NO3																		   //NO2 INSERT1
	select_model_insert2 = new QSqlTableModel(this);
	select_model_insert2->setTable("book_temp");
	select_model_insert2->select();
	select_model_insert2->setEditStrategy(QSqlTableModel::OnFieldChange);//�༭ģʽ

	ui.tableView_insert2->setModel(select_model_insert2);
	ui.tableView_insert2->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
	
																			  
	//NO4
	//QSqlTableModel *select_model_borrow_book;
	//QSqlTableModel *select_model_borrow_ID;
	select_model_borrow_ID = new QSqlTableModel(this);
	select_model_borrow_ID->setTable("borrow_info");
	select_model_borrow_ID->select();
	ui.tableView_borrow->setModel(select_model_borrow_ID);
	ui.tableView_borrow->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.tableView_borrow->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
	
	select_model_borrow_book = new QSqlTableModel(this);
	select_model_borrow_book->setTable("book");
	select_model_borrow_book->select();
	ui.tableView_borrow_book->setModel(select_model_borrow_book);
	ui.tableView_borrow_book->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.tableView_borrow_book->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
	
	select_model_borrow_info = new QSqlTableModel(this);
	select_model_borrow_info->setTable("library_card");
	select_model_borrow_info->select();
	ui.tableView_borrow_info->setModel(select_model_borrow_info);
	ui.tableView_borrow_info->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ɱ༭
	ui.tableView_borrow_info->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��


	return true;  	
}

/* ��ʼ���źźͲ� */
void BookSystem::initMotion() 
{
	//

	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(empty(int)));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(SL_rollback()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(SL_transaction()));

	

	//NO.1 SELECT
	//connect(ui.pushButton_serach, SIGNAL(clicked()),this, SLOT(SL_search_book()));���ֿ��Բ��Ӳ�ѯ��ť
	connect(ui.lineEdit, SIGNAL(textEdited(const QString &)), this, SLOT(SL_search_book(const QString &)));
	connect(ui.lineEdit_2, SIGNAL(textEdited(const QString &)), this, SLOT(SL_search_book(const QString &)));
	connect(ui.lineEdit_3, SIGNAL(textEdited(const QString &)), this, SLOT(SL_search_book(const QString &)));

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
	connect(ui.lineEdit_11, SIGNAL(textEdited(const QString & )), this, SLOT(SL_insert1_IDchange(const QString & )));

	//������ע��model�ı�
	connect(ui.tableView_insert1->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)), 
		this, SLOT(SL_insert1_selectBook(const QModelIndex &, const QModelIndex &)));
	connect(ui.tableView_insert1_type->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
		this, SLOT(SL_insert1_selectType(const QModelIndex &, const QModelIndex &)));

	//NO 3
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(SL_readtxt()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(SL_insert2()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(SL_insert2_delete()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(SL_insert2_delete_current()));

	//NO 4
	connect(ui.lineEdit_14, SIGNAL(textEdited(const QString &)), this, SLOT(SL_borrow_Bookchange(const QString &)));
	connect(ui.lineEdit_12, SIGNAL(textEdited(const QString &)), this, SLOT(SL_borrow_IDchange(const QString &)));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(SL_borrow()));
	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(SL_borrow_return()));

	//NO 5
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(SL_user_insert()));
	

}


void BookSystem::SL_rollback() 
{
	if (!db.rollback()) {
		QMessageBox::warning(0, QObject::tr("Database Error"), db.lastError().text());
	}
	else
	{
		QMessageBox::about(0, QObject::tr("Database Error"), "Success in Rollback");

	}
	empty(0);//���½���
	db.transaction();
}

//��ǳ��صĵ�
void BookSystem::SL_transaction() 
{
	db.commit();
	db.transaction();
}

void BookSystem::loadIn_Setboard() 
{
	//pushButton_back = new QPushButton(ui.centralWidget);
	//pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
	//pushButton_back->setGeometry(QRect(20, 10, 75, 23));
	//pushButton_back->setText(QString::fromUtf8("��������"));
}
