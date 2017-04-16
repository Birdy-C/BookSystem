/*
@author: Birdy&C 2017.4.15
*/
#include "stdafx.h"
#include "BookSystem.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BookSystem w;
	w.show();
	return a.exec();
}
