/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef FTOOLBUTTON_H
#define FTOOLBUTTON_H

#include <QMenu>
#include <QToolButton>

class FToolButton : public QToolButton
{
    Q_OBJECT
public:
    FToolButton(QWidget* parent = 0);
    ~FToolButton();

    void setMenu(QMenu *menu);

public slots:
    void recover();

};

#endif // FTOOLBUTTON_H
