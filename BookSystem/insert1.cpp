/*
@author: Birdy&C 2017.4.15

初始化
*/
#include "stdafx.h"
#include "BookSystem.h"

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


}

void BookSystem::SL_insert1_selectType(const QModelIndex &, const QModelIndex &)
{
	QModelIndex index=ui.tableView_insert1_type->currentIndex();
	QModelIndex i1 = index.sibling(index.row(), 0); 
	QString str1 = i1.data().toString();
	ui.lineEdit_8->setText(str1);
}

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


	}
}

void BookSystem::SL_insert1()
{

	QString Type = ui.lineEdit_8->text();
	QString ID;

	//如果得到的是零或者负数
	int number_in = ui.lineEdit_10->text().toInt();
	if (number_in <= 0)
	{
		QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the number");
		return;
	}
	QString number = QString::number(number_in, 10);//取整



	QSqlQuery query_getID("select MAX(Book_id)+1 from book where Type = '" + Type + "'");

	if (query_getID.next()) 
	{
		ID = query_getID.value(0).toString();
		ui.plainTextEdit_2->setPlainText(ID);
	}
	else
	{
		QSqlQuery query_temp("select Type_number * 1000 from type where Book_type = '" + Type + "'");
		if (query_temp.next())
		{
			ui.plainTextEdit_2->setPlainText(ID);

		}
		else 
		{
			QMessageBox::warning(0, QObject::tr("NO SUCH TYPE"), "make sure you add the accuracy type");
			return;
		}
	}

	QString insert1;
	{
		insert1 = "insert into book (Book_id,Type,Title,Publisher,Publish_year,Author,Price,Number,Stocks)values ('";
				insert1 += ID;
		insert1 += "','";
		insert1 += Type;
		insert1 += "','";
		insert1 += ui.lineEdit_4->text();
		insert1 += "','";
		insert1 += ui.lineEdit_5->text();
		insert1 += "','";
		insert1 += ui.lineEdit_6->text();
		insert1 += "','";
		insert1 += ui.lineEdit_7->text();
		insert1 += "','";
		insert1 += ui.lineEdit_9->text();
		insert1 += "','";
		
		insert1 += number;
		insert1 += "','";
		insert1 += number;
		insert1 += "');";
		ui.plainTextEdit_2->setPlainText(insert1);
	}

	{
		QSqlQuery query(insert1);
		if (!query.isActive())
		{
			QMessageBox::warning(0, QObject::tr("Database Error"), "Please check the input ,especially the accurcy in year");
			return;
		}	
		else
		{
			QMessageBox::about(0, QObject::tr("SUCCESS"), "Success in inserting book <" + ui.lineEdit_4->text()+">");
			SL_insert1_empty();
			select_model_insert1->select();//更新显示

		}
	}
}

void BookSystem::SL_delete()
{

	QString ID= ui.lineEdit_11->text();	
	QSqlQuery query_getStocks("select Stocks,Number from book where Book_id = '" + ID + "'");
	ui.plainTextEdit_2->setPlainText("select Stocks,Number from book where Book_id = '" + ID + "'");

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

	//如果得到的是零或者负数
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
	//如果为零则删除此条
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
			select_model_insert1->select();//更新显示
		}
		return;
	}
	//删除后不为零则更新

	QString newStocks = QString::number(newStocks_int, 10);//取整
	QString newAll = QString::number(newAll_int, 10);//取整

	QSqlQuery query_update("UPDATE Book SET Stocks = '" + newStocks + "',Number='" + newAll + "'where Book_ID = '" + ID + "';");
	if (!query_update.isActive())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), "Error in update");
		return;
	}
	else
	{
		QMessageBox::about(0, QObject::tr("SUCCESS"), "Success in update ");
		select_model_insert1->select();//更新显示

	}

}

void BookSystem::SL_insert1_change(const QString & text)
{
	QString search =  "Title like '%" + text + "%'";

	select_model_insert1->setFilter(search);
	select_model_insert1->select();

}

void BookSystem::SL_insert1_IDchange(const QString & text)
{
	QString search = "ID like '" + text + "%'";
	select_model_insert1->setFilter(search);
	select_model_insert1->select();
}