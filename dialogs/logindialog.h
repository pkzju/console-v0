/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "QFramer/fbasedialog.h"


class LoginDialog : public FBaseDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    void initUI();
    void initConnect();
signals:

public slots:

};

#endif // LoginDialog_H
