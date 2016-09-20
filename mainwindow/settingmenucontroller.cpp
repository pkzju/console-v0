/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "settingmenucontroller.h"
#include "dialogs/settingdialog.h"
#include "dialogs/aboutdialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include "mainwindow.h"


SettingMenuController::SettingMenuController(QObject *parent) :
    QObject(parent)
{

}

void SettingMenuController::showSettingDialog()
{
    MainWindow::getInstance()->show();
    SettingDialog* settingDialog = new SettingDialog;
    settingDialog->exec();
}

void SettingMenuController::checkUpdate()
{
    QDesktopServices::openUrl(QUrl("https://baidu.com"));
}

void SettingMenuController::onlineHelp()
{
    QDesktopServices::openUrl(QUrl("https://baidu.com"));
}

void SettingMenuController::showAboutUs()
{
    MainWindow::getInstance()->show();
    AboutDialog* aboutDialog = new AboutDialog;
    aboutDialog->exec();

}

void SettingMenuController::closeMainWindow()
{
    MainWindow* p = MainWindow::getInstance();
    p->animationClose();
}
