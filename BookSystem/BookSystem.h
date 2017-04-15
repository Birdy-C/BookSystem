#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BookSystem.h"

class BookSystem : public QMainWindow
{
	Q_OBJECT

public:
	BookSystem(QWidget *parent = Q_NULLPTR);

private:
	Ui::BookSystemClass ui;
};
