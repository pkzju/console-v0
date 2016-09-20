/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "fsetpushbutton.h"


FSetPushButton::FSetPushButton(const QString& text)
{
    setFlat(true);
    setCheckable(true);
    setFixedSize(40, 40);
 //   setText(text);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("checkable");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

