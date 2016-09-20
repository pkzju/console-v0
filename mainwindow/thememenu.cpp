/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "thememenu.h"
#include "QFramer/futil.h"
#include <QApplication>
#include <QFileDialog>
#include <QDir>
ThemeMenu::ThemeMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initConnect();
    actionMaps[tr("BB")]->trigger();
}

void ThemeMenu::initData()
{
    setObjectName("titleMenu");
    actionNames<<tr("BB") << tr("GBG") << tr("Custom theme");
}

void ThemeMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actions.at(i)->setCheckable(true);
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void ThemeMenu::initConnect()
{
    connect(actionMaps[tr("BB")], SIGNAL(triggered()), this, SLOT(changeTheme1()));
    connect(actionMaps[tr("GBG")], SIGNAL(triggered()), this, SLOT(changeTheme2()));
    connect(actionMaps[tr("Custom theme")], SIGNAL(triggered()), this, SLOT(changeThemeFromFile()));
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(updateCheckedAction(QAction*)));
}

void ThemeMenu::changeTheme1()
{
    setSkinForApp(QString(":/qss/skin/qss/BB.qss"));
}

void ThemeMenu::changeTheme2()
{
    setSkinForApp(QString(":/qss/skin/qss/GBG.qss"));
}

void ThemeMenu::changeThemeFromFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Laod qss"), QDir::currentPath(), tr("Qss Files (*.qss)"));
    if (fileName != ""){
        setSkinForApp(fileName);
    }
}

void ThemeMenu::updateCheckedAction(QAction *action)
{
    foreach (QAction* actionItem, actions) {
        if(actionItem == action){
            action->setChecked(true);
        }else {
            actionItem->setChecked(false);
        }
    }
}
