/*
@author: Birdy&C 2017.4.15
�౾���

*/

#include "stdafx.h"
#include "BookSystem.h"

/* ��ȡtxt */
void BookSystem::SL_readtxt()
{
	QFileDialog w;
	//����ѡ���
	w.setAcceptMode(QFileDialog::AcceptOpen);   //AcceptOpen��,AcceptSave�����ļ�
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
		select_model_insert2->select();//������ʾ
		select_model_insert2->submitAll();
		db.commit();
		file.close();
	}
}

/* ���뵽temp�� */
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

/*�����ʱ�鼮��¼����������*/
void BookSystem::SL_insert2_delete() 
{
	QSqlQuery query("delete from book_temp;");
	if (!query.isActive())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"), "Please check the table");
		return;
	}
	select_model_insert2->select();//������ʾ

}

/*ɾ����ʱ�鼮��¼���һ��*/
void BookSystem::SL_insert2_delete_current()
{
	int curRow = ui.tableView_insert2->currentIndex().row();
	//��ȡѡ�е���
	select_model_insert2->removeRow(curRow);
	//ɾ������
	select_model_insert2->select();//������ʾ

}

/*����ʱ������ݲ��뵽��ʽ����*/
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
	select_model_insert2->select();//������ʾ

}
