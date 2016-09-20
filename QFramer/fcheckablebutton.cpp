/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "fcheckablebutton.h"

FCheckabelButton::FCheckabelButton(const QString& text)
{
    setFlat(true);
    setCheckable(true);
    setFixedSize(80, 60);
    setText(text);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("checkable");
}
