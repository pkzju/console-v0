/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "fnofocusdelegate.h"
#include <QStyleOptionViewItem>


FNoFocusDelegate::FNoFocusDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void FNoFocusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem itemOption(option);
    if (itemOption.state & QStyle::State_HasFocus)
    {
        QPen penVal(Qt::white);
        penVal.setWidth(0);
        painter->setPen (penVal);
    }
    QStyledItemDelegate::paint(painter, itemOption, index);
}
