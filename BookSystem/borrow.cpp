/*
@author: Birdy&C 2017.4.15

借书界面
*/
#include "stdafx.h"
#include "BookSystem.h"

void BookSystem::SL_borrow_IDchange(const QString &text)
{
	QString search = "card_ID like '%" + text + "%'";
	select_model_borrow_ID->setFilter(search);
	select_model_borrow_ID->select();
	select_model_borrow_info->setFilter(search);
	select_model_borrow_info->select();	
}

void BookSystem::SL_borrow_Bookchange(const QString &text)
{
	QString search = "Book_id like '%" + text + "%'";
	select_model_borrow_book->setFilter(search);
	select_model_borrow_book->select();
}

void BookSystem::SL_borrow_select(const QModelIndex &, const QModelIndex &)
{
	QModelIndex index = ui.tableView_borrow->currentIndex();
	QModelIndex temp;
	QString str;
	{
		temp = index.sibling(index.row(), 0);
		str = temp.data().toString();
		ui.lineEdit_12->setText(str);

		temp = index.sibling(index.row(), 1);
		str = temp.data().toString();
		ui.lineEdit_14->setText(str);
	}
}

bool BookSystem::borrow_precheck()
{
	QString Book_ID = ui.lineEdit_14->text();
	QString card_ID = ui.lineEdit_12->text();
	QString Type;
	QString Title;
	int number;
	//Type=student/teacher
	{
		QSqlQuery query("select Type from library_card where card_ID = '" + card_ID + "'");
		if (query.next())
		{
			Type = query.value(0).toString();

		}
		else
		{
			QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the card ");
			return false;
		}
	
	}
	//number
	{
		QSqlQuery query("select count ( Book_ID ) from record where card_ID = '" + card_ID + "'");
		if (query.next())
		{
			number = query.value(0).toInt();
		}
		else
		{
			QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the card");
			return false;
		}
	} 
	//check if the card has storage
	{
		if (Type == "student" && number >= 3)
		{
			QMessageBox::warning(0, QObject::tr("FULL CARD"), "Sorry, card for student can only borrow 3 books at most. ");
			return false;

		}
		if (Type == "teacher" && number >= 5)
		{
			QMessageBox::warning(0, QObject::tr("FULL CARD"), "Sorry, card for teacher can only borrow 5 books at most. ");
			return false;

		}
	}
	//check the stock
	{
		int stocks;
		QSqlQuery query("select Stocks,Title from book where Book_id = '" + Book_ID + "'");
		if (query.next())
		{
			stocks = query.value(0).toInt();
			Title = query.value(1).toString();
		}
		else
		{
			QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the BOOK ");
			return false;
		}

		if (0 == stocks) 
		{
			QString date;
			QSqlQuery query("select MIN(return_data) from record where Book_id = '" + Book_ID + "'");
			if (query.next())
			{
				date = query.value(0).toString();
				QMessageBox::warning(0, QObject::tr("NO REMAINING"), "The Book <"+ Title +"> will be returned at the date "+ date);
			}
			else
			{
				QMessageBox::warning(0, QObject::tr("INACCURACY DATA"), "Please check the BOOK record");
			}

			return false;
		}

	}

	return true;
}

void BookSystem::SL_borrow( )
{
	if (false == borrow_precheck())
		return;
	QSqlQuery borrow;
	borrow.prepare("insert into record(Book_ID, card_ID, borrow_data, return_data, manager_ID) values"
		"(? , ? , ? , ? , ? ); ");
	borrow.addBindValue(ui.lineEdit_14->text());
	borrow.addBindValue(ui.lineEdit_12->text());

	//借书还书时间
	QDate borrow_day = QDate::currentDate();
	QDate return_day = borrow_day.addDays(40);
	QString strday1 = borrow_day.toString("yyyy-MM-dd");
	QString strday2 = return_day.toString("yyyy-MM-dd");

	borrow.addBindValue(strday1);
	borrow.addBindValue(strday2);
	borrow.addBindValue(manager_ID);
	//borrow.addBindValue("3150102459");

	borrow.exec();

	if (!borrow.isActive())
	{
		QMessageBox::critical(0, QObject::tr("Database Error"), "can't borrow the same book twice");
		return ;
	}
	//ui.lineEdit_12->setText("");
	ui.lineEdit_14->setText("");

	borrow_renew();//更新显示

}

void BookSystem::SL_borrow_return()
{
	int curRow = ui.tableView_borrow->currentIndex().row();
	//获取选中的行
	QSqlRecord record = select_model_borrow_ID->record(curRow);

	//删除该行
	int ok = QMessageBox::warning(this, tr("return book"), tr("sure to return?"),
		QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::No)
	{
		return;
	}
	else
	{
		QString Book_ID = record.value("Book_ID").toString();
		QString card_ID = record.value("card_ID").toString();
		QSqlQuery delete_record;	
		delete_record.prepare("delete from record where Book_ID=? AND card_ID=?");
		delete_record.addBindValue(Book_ID);
		delete_record.addBindValue(card_ID);
		bool check = delete_record.exec();
		if (!check)
		{
			QMessageBox::warning(0, QObject::tr("Database Error"), "Error when delete");
			return;
		}
	}
	borrow_renew();//更新显示


}

void BookSystem::borrow_renew() 
{
	SL_borrow_IDchange("");
	SL_borrow_Bookchange("");
	select_model_borrow_book->select();
	select_model_borrow_ID->select();
	select_model_borrow_info->select();
}
