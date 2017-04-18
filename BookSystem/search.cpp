/*
@author: Birdy&C 2017.4.15

搜索相关
*/

#include "stdafx.h"
#include "BookSystem.h"

/*调整排序*/
void BookSystem::SL_search_book_order()
{
	bool ok = ui.checkBox_2->checkState();
	int column = 0;

	if (ui.radioButton->isChecked())
		column = 2;
	if (ui.radioButton_2->isChecked()) 
		column = 1;
	if (ui.radioButton_3->isChecked())
		column = 5;


	if (!ok)
		select_model->setSort(column, Qt::AscendingOrder);
	else
		select_model->setSort(column, Qt::DescendingOrder);

	select_model->select();

}

/*查找*/

void BookSystem::SL_search_book(const QString &)
{
	QString search="";
	search += "Title like '%" + ui.lineEdit->text() + "%'";
	search += " AND ";
	search += "Type like '%" + ui.lineEdit_2->text() + "%'";
	search += " AND ";
	search += "Author like '%" + ui.lineEdit_3->text() + "%'";
	search += " AND ";
	search += "Title like '%" + ui.lineEdit->text() + "%'";
	search += " AND ";
	search += "Publisher like '%" + ui.lineEdit_19->text() + "%'";
	search += " AND ";
	search += "Publish_year >=" + ui.spinBox->text() ;
	search += " AND ";
	search += "Publish_year <=" + ui.spinBox_2->text();
	search += " AND ";
	search += "Price >=" + ui.doubleSpinBox->text();
	search += " AND ";
	search += "Price <=" + ui.doubleSpinBox_2->text();



	if ( ui.checkBox->checkState() )
	{
		search += " AND ";
		search += " Stocks > 0 ";
	}

	//ui.plainTextEdit->setPlainText(search);
	select_model->setFilter(search);
	SL_search_book_order();
	//select_model->select();在前一个函数中已经存在
}


/*这个函数只是为了连接信号*/
void BookSystem::SL_search_book_reset()
{
	SL_search_book(" ");
}
void BookSystem::SL_search_book_reset(int i)
{
	SL_search_book(" ");
}
void BookSystem::SL_search_book_reset(double i)
{
	SL_search_book(" ");
}

/*清空信息*/
void BookSystem::SL_search_book_empty() 
{
	ui.lineEdit->setText("");
	ui.lineEdit_2->setText("");
	ui.lineEdit_3->setText("");
}