/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef GROUPMONITORUI_H
#define GROUPMONITORUI_H

#include <QFrame>
class QTableWidget;

namespace Ui {
class GroupMonitorUi;
}

class GroupMonitorUi : public QFrame
{
    Q_OBJECT

public:
    explicit GroupMonitorUi(QWidget *parent = 0);
    ~GroupMonitorUi();
    QTableWidget *getTable();

private:
    Ui::GroupMonitorUi *ui;
};

#endif // GROUPMONITORUI_H
