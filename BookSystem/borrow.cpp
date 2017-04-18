/*
@author: Birdy&C 2017.4.15

�������
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


void BookSystem::SL_borrow( )
{
	//if (false == load_statues)
	//	return;
	QSqlQuery borrow;
	borrow.prepare("insert into record(Book_ID, card_ID, borrow_data, return_data, manager_ID) values"
		"(? , ? , ? , ? , '3150102459' ); ");
	borrow.addBindValue(ui.lineEdit_14->text());
	borrow.addBindValue(ui.lineEdit_12->text());

	//���黹��ʱ��
	QDate borrow_day = QDate::currentDate();
	QDate return_day = borrow_day.addDays(40);
	QString strday1 = borrow_day.toString("yyyy-MM-dd");
	QString strday2 = return_day.toString("yyyy-MM-dd");

	borrow.addBindValue(strday1);
	borrow.addBindValue(strday2);
	//borrow.addBindValue(manager_ID);
	//borrow.addBindValue("3150102459");

	borrow.exec();

	if (!borrow.isActive())
	{
		QMessageBox::critical(0, QObject::tr("Database Error"), "error when borrow the book,"
			"please check the storage and input");
		return ;
	}
	ui.lineEdit_12->setText("");
	ui.lineEdit_14->setText("");

	borrow_renew();//������ʾ

}

void BookSystem::SL_borrow_return()
{
	int curRow = ui.tableView_borrow->currentIndex().row();
	//��ȡѡ�е���
	QSqlRecord record = select_model_borrow_ID->record(curRow);

	//ɾ������
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
	borrow_renew();//������ʾ


}

void BookSystem::borrow_renew() 
{
	select_model_borrow_book->select();
	select_model_borrow_ID->select();
	select_model_borrow_info->select();
}
