/*
@author: Birdy&C 2017.4.15

³õÊ¼»¯
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
	ui.tableView_insert1->currentIndex().row();


}

void BookSystem::SL_insert1()
{
	QString Type = ui.lineEdit_8->text();
	QString ID;
	QSqlQuery query_getID("select MAX(Book_id)+1 from book where Type = " + Type);
	ui.plainTextEdit_2->setPlainText("select MAX(Book_id)+1 from book where Type = '" + Type +"'");

	if (query_getID.next()) 
	{
		ID = query_getID.value(0).toString();
		//ui.plainTextEdit_2->setPlainText(ID);
	}
	else
	{
		QSqlQuery query_temp("select Type_number * 1000 from type where Book_type = '" + Type + "'");
		if (query_temp.next())
		{
			ID = query_temp.value(0).toString();
			//ui.plainTextEdit_2->setPlainText(ID);

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
		insert1 += " ',' ";
		insert1 += ui.lineEdit_7->text();
		insert1 += "','";
		insert1 += ui.lineEdit_9->text();
		insert1 += "','";
		insert1 += ui.lineEdit_10->text();
		insert1 += "','";
		insert1 += ui.lineEdit_10->text();
		insert1 += "');";
		//ui.plainTextEdit_2->setPlainText(insert1);
	}

}
