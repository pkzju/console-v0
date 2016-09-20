/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "groupmonitorui.h"
#include "ui_groupmonitorui.h"

#include <QTableWidget>

GroupMonitorUi::GroupMonitorUi(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GroupMonitorUi)
{
    ui->setupUi(this);
}

GroupMonitorUi::~GroupMonitorUi()
{
    delete ui;
}

QTableWidget* GroupMonitorUi::getTable()
{
    return ui->table_realtime;
}
