/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "rightfloatwindow.h"
#include "mainwindow/mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include "mainwindow/settingmenu.h"

RightFloatWindow::RightFloatWindow(QWidget *parent) :
    FMovableWidget(parent)
{
    initData();
    initUI();
    initConnect();

}

void RightFloatWindow::initData()
{
    cwidth = 200;
}

void RightFloatWindow::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::ToolTip);
    setObjectName(QString("RightFloatWindow"));
}

void RightFloatWindow::initConnect()
{

}

void RightFloatWindow::showEvent(QShowEvent *event)
{
    move(MainWindow::getInstance()->x()+ MainWindow::getInstance()->width() + 2,\
         MainWindow::getInstance()->y());
    resize(cwidth, MainWindow::getInstance()->height());
    MainWindow::getInstance()->getSettingMenu()->\
            getActionMaps()[QStringLiteral("Show Floating")]->setText(QStringLiteral("Hide Floating"));
    QWidget::showEvent(event);
}

void RightFloatWindow::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event)
    MainWindow::getInstance()->getSettingMenu()->\
            getActionMaps()[QStringLiteral("Show Floating")]->setText(QStringLiteral("Show Floating"));
}

void RightFloatWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(x() + width(), y());
    FMovableWidget::mouseMoveEvent(event);
}

