/*
@author: Birdy&C 2017.4.15

��ʼ��
*/
#include "stdafx.h"
#include "BookSystem.h"

/*����������Ϣ*/
void BookSystem::SL_insert1_empty()
{
	ui.lineEdit_4->setText("");
	ui.lineEdit_5->setText("");
	ui.lineEdit_6->setText("");
	ui.lineEdit_7->setText("");
	ui.lineEdit_8->setText("");
	ui.lineEdit_9->setText("");
	ui.lineEdit_10->setText("");
	ui.lineEdit_11->setText("");

	select_model_insert1->setFilter("");
	select_model_insert1->select();


}

/*ѡ������*/
void BookSystem::SL_insert1_selectType(const QModelIndex &, const QModelIndex &)
{
	QModelIndex index=ui.tableView_insert1_type->currentIndex();
	QModelIndex i1 = index.sibling(index.row(), 0); 
	QString str1 = i1.data().toString();
	ui.lineEdit_8->setText(str1);
}

/*ѡ����*/
void BookSystem::SL_insert1_selectBook(const QModelIndex &, const QModelIndex &)
{
	QModelIndex index=ui.tableView_insert1->currentIndex();
	QModelIndex temp; 
	QString str; 
	{
		//Type
		temp = index.sibling(index.row(), 1);
		str = temp.data().toString();
		ui.lineEdit_8->setText(str);

		//Title
		temp = index.sibling(index.row(), 2);
		str = temp.data().toString();
		ui.lineEdit_4->setText(str);

		//Publisher
		temp = index.sibling(index.row(), 3);
		str = temp.data().toString();
		ui.lineEdit_5->setText(str);

		//Publish year
		temp = index.sibling(index.row(), 4);
		str = temp.data().toString();
		ui.lineEdit_6->setText(str);

		//Author
		temp = index.sibling(index.row(), 5);
		str = temp.data().toString();
		ui.lineEdit_7->setText(str);

		//Price
		temp = index.sibling(index.row(), 6);
		str = temp.data().toString();
		ui.lineEdit_9->setText(str);

		//ID
		temp = index.sibling(index.row(), 0);
		str = temp.data().toString();
		ui.lineEdit_11->setText(str);

		//���
		temp = index.sibling(index.row(), 7);
		str = temp.data().toString();
		ui.lineEdit_10->setText(str);



	}
}

/*��������*/
void BookSystem::SL_insert1()
{
	if(SL_insert_book(ui.lineEdit_8->text(), ui.lineEdit_4->text(), ui.lineEdit_5->text(), ui.lineEdit_6->text(), 
		ui.lineEdit_7->text(), ui.lineEdit_9->text(), ui.lineEdit_10->text()))
	{
		select_model_insert1->select();//������ʾ
		QMessageBox::about(0, QObject::tr("SUCCESS"), "Success in inserting book <" + ui.lineEdit_4->text() + ">");
		SL_insert1_empty();

	}

}

bool BookSystem::SL_insert_book(QString Type, QString Title, QString Publisher,
	QString Publish_year, QString  Author, QString Price, QString Number) 
{
	QString ID;

	if (""== Title )
	{
		QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please put in accurate name");
		return false;
	}


	//����õ���������߸���
	int number_in = Number.toInt();
	if (number_in <= 0)
	{
		QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the number");
		return false;
	}
	QString number = QString::number(number_in, 10);//ȡ��



	QSqlQuery query_getID("select MAX(Book_id)+1 from book where Type = '" + Type + "'");

	if (query_getID.next())
	{
		ID = query_getID.value(0).toString();
	}
	if (ID == "")
	{
		QSqlQuery query_temp("select Type_number * 1000 + 1 from type where Book_type = '" + Type + "'");
		ui.plainTextEdit_3->setPlainText(ID);

		if (query_temp.next())
		{
			ID = query_temp.value(0).toString();
		}
		else
		{
			QMessageBox::warning(0, QObject::tr("NO SUCH TYPE"), "make sure you add the accuracy type");
			return false;
		}
	}

	
	//����
	QSqlQuery insert;
	insert.prepare("INSERT INTO book (Book_id,Type,Title,Publisher,Publish_year,Author,Price,Number,Stocks) "
		"VALUES (?,?,?,?,?,?,?,?,?);");
	insert.addBindValue(ID);
	insert.addBindValue(Type);
	insert.addBindValue(Title);
	insert.addBindValue(Publisher);
	insert.addBindValue(Publish_year);
	insert.addBindValue(Author);
	insert.addBindValue(Price);
	insert.addBindValue(Number);
	insert.addBindValue(Number);
	insert.exec();

	if (!insert.isActive())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), "Please check the input ,especially the accurcy in publish year,"
			"or maybe the ID need to be reset.");
		//���ݿⷵ�ش���ļ��ֿ����� 1.����Լ���� ID��������һ���������� 2.trigger��Լ�� ��ݴ���1800 С�����ڵ����
		return false;
	}

	return true;


}

 /*ɾ������*/
void BookSystem::SL_delete()
{

	QString ID= ui.lineEdit_11->text();	
	QSqlQuery query_getStocks("select Stocks,Number from book where Book_id = '" + ID + "'");
	ui.plainTextEdit_3->setPlainText("select Stocks,Number from book where Book_id = '" + ID + "'");

	int Stocks_int, All_int;
	if (query_getStocks.next())
	{
		Stocks_int = query_getStocks.value(0).toInt();
		All_int = query_getStocks.value(1).toInt();
		//ui.plainTextEdit_2->setPlainText(ID);
	}
	else
	{
		QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the ID");
		return;
	}
	int number_int = ui.lineEdit_10->text().toInt();

	//����õ���������߸���
	if (number_int <= 0)
	{
		QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the number");
		return;
	}

	if (Stocks_int < number_int) 
	{
		QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "The Storage Smaller Than Input");	
		return;
	}

	int newStocks_int, newAll_int;
	newStocks_int = Stocks_int - number_int;
	newAll_int = All_int - number_int;
	//���Ϊ����ɾ������
	if (0 == newAll_int) 
	{
		QString delete_book = "delete from book where Book_ID = '" + ID + "';";
		QSqlQuery query(delete_book);

		if (!query.isActive())
		{
			QMessageBox::warning(0, QObject::tr("Database Error"), " Error in delete ");
		}
		else 
		{
			QMessageBox::about(0, QObject::tr("SUCCESS"), "Success in delete ");
			select_model_insert1->select();//������ʾ
		}
		return;
	}
	//ɾ����Ϊ�������

	QString newStocks = QString::number(newStocks_int, 10);//ȡ��
	QString newAll = QString::number(newAll_int, 10);//ȡ��

	QSqlQuery query_update("UPDATE Book SET Stocks = '" + newStocks + "',Number='" + newAll + "'where Book_ID = '" + ID + "';");
	if (!query_update.isActive())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), "Error in update");
		return;
	}
	else
	{
		QMessageBox::about(0, QObject::tr("SUCCESS"), "Success in update ");
		select_model_insert1->select();//������ʾ

	}

}

/*�����������������ɸѡ*/
void BookSystem::SL_insert1_change(const QString & text)
{
	QString search =  "Title like '%" + text + "%'";

	select_model_insert1->setFilter(search);
	select_model_insert1->select();

}

/*���������ID����ɸѡ*/
void BookSystem::SL_insert1_IDchange(const QString & text)
{
	QString search = "Book_ID like '" + text + "%'";
	select_model_insert1->setFilter(search);
	select_model_insert1->select();
}