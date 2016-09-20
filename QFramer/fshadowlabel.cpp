/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "fshadowlabel.h"
#include <QGraphicsDropShadowEffect>


FShadowLabel::FShadowLabel(const QString &text, QWidget *parent) :
    QLabel(text, parent)
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::darkGreen);
    shadow_effect->setBlurRadius(8);
    setGraphicsEffect(shadow_effect);
}

FShadowLabel::FShadowLabel(QWidget *parent) :
    QLabel(parent)
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::darkGreen);
    shadow_effect->setBlurRadius(8);
    setGraphicsEffect(shadow_effect);
}
