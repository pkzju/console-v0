/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef BASEQUICKWIDGET_H
#define BASEQUICKWIDGET_H

#include <QQuickWidget>

class BaseQuickWidget : public QQuickWidget
{
    Q_OBJECT
public:
    explicit BaseQuickWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // BASEQUICKWIDGET_H
