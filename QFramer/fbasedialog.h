/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef FBASEDIALOG_H
#define FBASEDIALOG_H
#include <QVBoxLayout>
#include <QDialog>
#include <QMouseEvent>
#include <QShowEvent>
#include <QCloseEvent>
#include "ftitlebar.h"


class FBaseDialog : public QDialog
{
    Q_OBJECT
private:
    QPoint dragPosition;

private:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    FTitleBar* titlebar;
    QVBoxLayout* mLayout;

protected:
    void showEvent(QShowEvent * event);
    void closeEvent(QCloseEvent * event);
public:
    QSize normalSize;

public:
    explicit FBaseDialog(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    FTitleBar* getTitleBar();
    QLayout *layout();

signals:

public slots:
   virtual void animationClose();
};

#endif // FBASEDIALOG_H
