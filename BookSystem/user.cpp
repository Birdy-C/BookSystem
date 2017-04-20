/*
@author: Birdy&C 2017.4.15

用户管理界面 用户信息相关
*/
#include "stdafx.h"
#include "BookSystem.h"


void BookSystem::SL_user_insert( )
{

	QString ID;
	{
		QSqlQuery query_getID("select MAX(card_ID)+1 from library_card ;");

		if (query_getID.next())
		{
			ID = query_getID.value(0).toString();
		}
		if (ID == "")
		{
			ID = "1";
		}
	}

	QString Username= ui.lineEdit_15->text();
	QString company = ui.lineEdit_16->text();
	QString Type="student";
	if (ui.radioButton_5->isChecked())
	{
		Type = "teacher";
	}
	{
		QSqlQuery query_insert("insert into library_card (card_ID,Username,Company,Type) "
			"values('"+ ID +"', '"+ Username +"', '"+ company +"', '"+ Type +"'); ");

		if (!query_insert.isActive())
		{
			QMessageBox::warning(0, QObject::tr("Database Error"), "Error when Insert");
		}

	}
	QMessageBox::about(0, QObject::tr("Add New Card"), "Create new card success, the card_ID is "+ID+".");
	ui.lineEdit_15->setText("");
	ui.lineEdit_16->setText("");
	ui.radioButton_6->clicked(true);
	select_model_user->select();//更新显示

}

void BookSystem::SL_user_select(const QString & text)
{
	QString search = "";
	search += "card_ID like '" + ui.lineEdit_13->text() + "%'";
	select_model_user->setFilter(search);
	select_model_user->select();

}

void BookSystem::SL_user_delete()
{
	int curRow = ui.tableView_user->currentIndex().row();
	//获取选中的行
	QSqlRecord record = select_model_user->record(curRow);

	//删除该行
	{
		int ok = QMessageBox::warning(this, tr("DELETE USER"), tr("sure to delete this user?"),
		QMessageBox::Yes, QMessageBox::No);
		if (ok == QMessageBox::No)
		return;	
	}
	
	QString card_ID = record.value("card_ID").toString();
	QString check = "select count( Book_ID ) from record where card_ID = '" + card_ID + "';";
	QSqlQuery check_query(check);
	int count = 0;
	if (check_query.next())
	{
		count = check_query.value(0).toInt();
		ui.plainTextEdit_3->setPlainText(check_query.value(0).toString());
	}

	if (0 == count) 
	{
		QSqlQuery delete_record;
		bool check=delete_record.exec("delete from library_card where card_ID ='" + card_ID + "';");
		if (!check)
		{
			ui.plainTextEdit_3->setPlainText("delete from library_card where card_ID ='" + card_ID + "';");
			QMessageBox::warning(0, QObject::tr("Database Error"), "Error when delete card");
			return;
		}

		select_model_user->select();//更新显示

	}
	else 
	{
		int ok = QMessageBox::warning(this, tr("DELETE USER"), tr("the card still has unreturned book. Still delete it? ( all the book will be returned )"),
			QMessageBox::Yes, QMessageBox::No);
		if (ok == QMessageBox::No)
		{
			return;
		}
		{
			QSqlQuery delete_record;
			bool check = delete_record.exec("delete from record where card_ID ='" + card_ID + "';");

			if (!check)
			{
				QMessageBox::warning(0, QObject::tr("Database Error"), "Error when delete record");
				return;
			}
		}
		{
			QSqlQuery delete_record("delete from library_card where card_ID='" + card_ID + "';");

			if (!delete_record.isActive())
			{
				QMessageBox::warning(0, QObject::tr("Database Error"), "Error when delete card");
				return;
			}
		}
	}

	select_model_user->select();//更新显示

}

void BookSystem::SL_user_loadin()
{
	if (false == checkManager()) 
	{
		ui.lineEdit_17->setText("");
		return;	
	}

	QMessageBox::about(0, QObject::tr("LOAD IN"), "Welcome ! " + manager_name + ".");

	load_statues = true;
	//manager_ID = ui.lineEdit_18->text().toInt();
	ui.label_24->setText("Welcome ! " + manager_name + ".");
	ui.lineEdit_17->setText("");
	ui.lineEdit_18->setText("");

	{
		ui.tabWidget->addTab(ui.tab_2, QString::fromLocal8Bit("单本插入/删除"));
		ui.tabWidget->addTab(ui.tab_3, QString::fromLocal8Bit("批量入库"));
		ui.tabWidget->addTab(ui.tab_4, QString::fromLocal8Bit("借阅管理"));
		ui.tabWidget->addTab(ui.tab_5, QString::fromLocal8Bit("用户信息管理"));
		ui.tabWidget->addTab(ui.tab_6, QString::fromLocal8Bit("创建用户"));
		ui.tabWidget->addTab(ui.tab_7, QString::fromLocal8Bit("借书记录"));
		ui.tabWidget->addTab(ui.tab_8, QString::fromLocal8Bit("管理员信息"));

		connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(empty(int)));

	}
	{ //set the buttom

		bool ok = false;
		ui.label_25->setVisible(ok);
		ui.label_26->setVisible(ok);
		ui.lineEdit_17->setVisible(ok);
		ui.lineEdit_18->setVisible(ok);
		ui.pushButton_12->setVisible(ok);
		ui.label_24->setVisible(!ok);
		ui.pushButton->setVisible(!ok);
	}

}

bool BookSystem:: checkManager() 
{
	QSqlQuery query_temp("select manager_ID, Name  from manager where manager_ID = '" + ui.lineEdit_18->text()
		+ "'AND Password = '" + ui.lineEdit_17->text() + "';");
	ui.plainTextEdit_3->setPlainText("select manager_ID, Name  from manager where manager_ID = '" + ui.lineEdit_18->text()
		+ "'AND Password = '" + ui.lineEdit_17->text() + "';");

	if (query_temp.next())
	{
		manager_ID = query_temp.value(0).toInt();
		manager_name = query_temp.value(1).toString();

	}
	else
	{
		QMessageBox::warning(0, QObject::tr("NO SUCH INFORMATION"), "make sure you add the accurate information");
		return false;
	}
	return true;
}

void BookSystem::SL_user_checkout() 
{
	/*{
		int ok = QMessageBox::warning(this, tr("LOAD OUT"), tr("sure to quit?"),
		QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::No)
		return;
	}*/
	manager_ID = 0;
	manager_name = "";
	load_statues = false;

	for (int i = 1; i < 8; i++) 
	{
		ui.tabWidget->removeTab(1);
	}

	{ //set the buttom		
		bool ok = true;
		ui.label_25->setVisible(ok);
		ui.label_26->setVisible(ok);
		ui.lineEdit_17->setVisible(ok);
		ui.lineEdit_18->setVisible(ok);
		ui.pushButton_12->setVisible(ok);
		ui.label_24->setVisible(!ok);
		ui.pushButton->setVisible(!ok);
	}
}
