/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "settingmenu.h"
#include "mainwindow.h"
#include "functionpages/rightfloatwindow.h"
#include <QApplication>


SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initController();
    initConnect();
}

void SettingMenu::initData()
{
    setObjectName("titleMenu");
    actionNames << QStringLiteral("Settings")\
                << QStringLiteral("Show Toolbar")\
                << QStringLiteral("Show Floating")\
                << QStringLiteral("Updates")\
                << QStringLiteral("Help") \
                << QStringLiteral("About") \
                << QStringLiteral("Exit");
}

void SettingMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void SettingMenu::initController()
{
    controller = new SettingMenuController();
}

void SettingMenu::initConnect()
{
    connect(actionMaps[QStringLiteral("Settings")], SIGNAL(triggered()), controller, SLOT(showSettingDialog()));
    connect(actionMaps[QStringLiteral("Show Toolbar")], SIGNAL(triggered()), this, SLOT(switchActionState()));
    connect(actionMaps[QStringLiteral("Show Floating")], SIGNAL(triggered()), this, SLOT(switchFloatWindow()));
    connect(actionMaps[QStringLiteral("Updates")], SIGNAL(triggered()), controller, SLOT(checkUpdate()));
    connect(actionMaps[QStringLiteral("Help")], SIGNAL(triggered()), controller, SLOT(onlineHelp()));
    connect(actionMaps[QStringLiteral("About")], SIGNAL(triggered()), controller, SLOT(showAboutUs()));
    connect(actionMaps[QStringLiteral("Exit")], SIGNAL(triggered()), controller, SLOT(closeMainWindow()));
}

QMap<QString, QAction*> SettingMenu::getActionMaps()
{
    return actionMaps;
}


void SettingMenu::switchActionState()
{
    MainWindow::getInstance()->getFlyWidget()->setVisible(
                ! MainWindow::getInstance()->getFlyWidget()->isVisible());

    if(MainWindow::getInstance()->getFlyWidget()->isVisible())
    {
        actionMaps[QStringLiteral("Show Toolbar")]->setText(QStringLiteral("Hide Toolbar"));
    }
    else
    {
        actionMaps[QStringLiteral("Show Toolbar")]->setText(QStringLiteral("Show Toolbar"));
    }
}

void SettingMenu::switchFloatWindow()
{
    MainWindow::getInstance()->getRightFloatWindow()->setVisible(\
        ! MainWindow::getInstance()->getRightFloatWindow()->isVisible());

    if(MainWindow::getInstance()->getRightFloatWindow()->isVisible())
    {
        actionMaps[QStringLiteral("Show Floating")]->setText(QStringLiteral("Hide Floating"));
    }
    else
    {
        actionMaps[QStringLiteral("Show Floating")]->setText(QStringLiteral("Show Floating"));
    }
}
