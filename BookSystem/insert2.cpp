/*
@author: Birdy&C 2017.4.15
多本入库

*/

#include "stdafx.h"
#include "BookSystem.h"

/* 读取txt */
void BookSystem::SL_readtxt()
{
	QFileDialog w;
	//设置选择框
	w.setAcceptMode(QFileDialog::AcceptOpen);   //AcceptOpen打开,AcceptSave保存文件
	w.setFileMode(QFileDialog::ExistingFiles);
	w.setOption(QFileDialog::ReadOnly, true);
	w.setWindowTitle(QString("choose.."));
	w.setDirectory(QString("./"));
	w.setNameFilter(QString("txt(*.txt)"));

	if (w.exec())
	{
		QString file_path = w.selectedFiles().at(0);
		QFile file(file_path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::critical(0, QObject::tr("Database Error"), "driver doesn't support transactions.");
			return;
		}
		QTextStream in(&file);
		QString line = in.readLine();
		while (!line.isNull())
		{
			insert2_line_temp(line);
			line = in.readLine();
		}
		select_model_insert2->select();//更新显示
		select_model_insert2->submitAll();
		db.commit();
		file.close();
	}
}

/* 插入到temp中 */
void BookSystem::insert2_line_temp(const QString line)
{
	QString insert = "insert into book_temp (Type,Title,Publisher,Publish_year,Author,Price,Number)values ";
	insert += line;

	QSqlQuery query(insert);
	if (!query.isActive())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), "Please check the form of input.");
		return;
	}
	else
	{
	}

}

/*清空临时书籍记录表所有内容*/
void BookSystem::SL_insert2_delete() 
{
	QSqlQuery query("delete from book_temp;");
	if (!query.isActive())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), "Please check the table");
		return;
	}
	select_model_insert2->select();//更新显示

}

/*删除临时书籍记录表的一行*/
void BookSystem::SL_insert2_delete_current()
{
	int curRow = ui.tableView_insert2->currentIndex().row();
	//获取选中的行
	select_model_insert2->removeRow(curRow);
	//删除该行
	select_model_insert2->select();//更新显示

}

/*把临时表的内容插入到正式表中*/
void BookSystem::SL_insert2() 
{
	select_model_insert2->submitAll();
	for (int i = select_model_insert2->rowCount()-1; i >= 0; i--)
	{
		QSqlRecord record = select_model_insert2->record(i);
		bool ok;
		ok = SL_insert_book
		(
			record.value("Type").toString(),
			record.value("Title").toString(),
			record.value("Publisher").toString(),
			record.value("Publish_year").toString(),
			record.value("Author").toString(),
			record.value("Price").toString(),
			record.value("Number").toString()
		);
		if(ok)
		{
			select_model_insert2->removeRow(i);
		}
		
	}
	select_model_insert2->select();//更新显示

}
