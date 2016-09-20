/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef FTITLEBAR_H
#define FTITLEBAR_H

#include "ftoolbutton.h"
#include <QFrame>
#include <QLabel>


#define Title_Height 25

class FTitleBar : public QFrame
{
    Q_OBJECT
private:
    QIcon* logoIcon;
    QIcon* settingsIcon;
    QIcon* skinIcon;
    QIcon* minIcon;
    QIcon* maxIcon;
    QIcon* normalIcon;
    QIcon* closeIcon;
    QLabel* titleLabel;
    FToolButton* logoButton;
    FToolButton* settingButton;
    FToolButton* skinButton;
    FToolButton* fixButton;
    FToolButton* minButton;
    FToolButton* maxButton;
    FToolButton* closeButton;
    bool normal_max_flag;
    bool fixflag;

private:
    void initData();
    void initConnect();
    void initUI();

public:
    QString title;
    static FTitleBar* instance;

public:
    explicit FTitleBar(QWidget *parent = 0);
    static FTitleBar* getInstace();

    bool getFixedflag();

    void setTitleBarHeight(int height);
    void setSettingMenu(QMenu* menu);

    void setLogoButton(const char * str, const char *objectName=NULL);
    FToolButton* getLogoButton();
    void setLogoButtonVisible(bool visible);
    bool isLogoButtonVisible();

    void setTitleLabel(QString str , const char *objectName=NULL);
    QLabel* getTitleLabel();
    void setTitleLabelVisible(bool visible);
    bool isTitleLabelVisible();

    void setSettingButton(const char * str, const char *objectName=NULL);
    FToolButton* getSettingButton();
    void setSettingButtonVisible(bool visible);
    bool isSettingButtonVisible();

    void setSkinButton(const char * str, const char *objectName=NULL);
    FToolButton* getSkinButton();
    void setSkinButtonVisible(bool visible);
    bool isSkinButtonVisible();

    void setFixButton(const char * str, const char *objectName=NULL);
    FToolButton* getFixButton();
    void setFixButtonVisible(bool visible);
    bool isFixButtonVisible();

    void setMinButton(const char * str, const char *objectName=NULL);
    FToolButton* getMinButton();
    void setMinButtonVisible(bool visible);
    bool isMinButtonVisible();

    void setMaxButton(const char * str, const char *objectName=NULL);
    FToolButton* getMaxButton();
    void setMaxButtonVisible(bool visible);
    bool isMaxButtonVisible();

    void setCloseButton(const char * str, const char *objectName=NULL);
    FToolButton* getCloseButton();
    void setCloseButtonVisible(bool visible);
    bool isCloseButtonVisible();

signals:
    void maximumed();
    void minimuned();
    void normaled();
    void closed();
    void LockChanged(const bool lock);

public slots:
    void switchMaxMin();
    void changeSkin();
    void clearChecked();
    void changeFix();

};

#endif // FTITLEBAR_H
