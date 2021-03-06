/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef FWIGGLYWIDGET_H
#define FWIGGLYWIDGET_H

#include <QBasicTimer>
#include <QWidget>
#include <QLabel>
#include <QTimerEvent>
#include <QPainter>

class FWigglyWidget : public QLabel
{
    Q_OBJECT

public:
    FWigglyWidget(const QString &text, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    QBasicTimer timer;
    QString text;
    int step;
};


#endif // FWIGGLYWIDGET_H
