/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef SIGLEGROUPDIALOG_H
#define SIGLEGROUPDIALOG_H

#include "QFramer/fsubwindown.h"
#include "fanmotor/fpublic.h"

class sigleGroupDialog : public FSubWindown
{
    Q_OBJECT
public:
    explicit sigleGroupDialog(QWidget *parent = 0);
    ~sigleGroupDialog();
    void initUI();
    void initConnect();
    static sigleGroupDialog *getS_Instance();
    static void deleteInstance();
signals:

public slots:
    void show(FanGroupInfo *group);

private:
    static sigleGroupDialog *s_Instance;


};

#endif // SIGLEGROUPDIALOG_H
