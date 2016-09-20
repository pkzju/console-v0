/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef SETTINGMENUCONTROLLER_H
#define SETTINGMENUCONTROLLER_H

#include <QObject>

class SettingMenuController : public QObject
{
    Q_OBJECT
public:
    explicit SettingMenuController(QObject *parent = 0);

signals:

public slots:
    void showSettingDialog();
    void checkUpdate();
    void onlineHelp();
    void showAboutUs();
    void closeMainWindow();
};

#endif // FSETTINGMENUCONTROLLER_H
