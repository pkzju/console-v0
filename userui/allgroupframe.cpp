/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "allgroupframe.h"
#include "ui_allgroupframe.h"

AllGroupFrame::AllGroupFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AllGroupFrame)
{
    ui->setupUi(this);
}

AllGroupFrame::~AllGroupFrame()
{
    delete ui;
}
