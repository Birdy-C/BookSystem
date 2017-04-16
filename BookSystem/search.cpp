/*
@author: Birdy&C 2017.4.15

ËÑË÷Ïà¹Ø
*/

#include "stdafx.h"
#include "BookSystem.h"


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


void BookSystem::SL_search_book() 
{
	QString search="";
	search += "Title like '%" + ui.lineEdit->text() + "%'";
	search += " AND ";
	search += "Type like '%" + ui.lineEdit_2->text() + "%'";
	search += " AND ";
	search += "Author like '%" + ui.lineEdit_3->text() + "%'";

	if (ui.checkBox->isChecked())
	{
		search += " AND ";
		search += " Stocks > 0 ";
	}

	ui.plainTextEdit->setPlainText(search);
	select_model->setFilter(search);
	SL_search_book_order();
	select_model->select();
}


void BookSystem::SL_search_book_empty() 
{
	

}