/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef FNOFOCUSDELEGATE_H
#define FNOFOCUSDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>


class FNoFocusDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit FNoFocusDelegate(QObject *parent = 0);
    void paint( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
signals:

public slots:

};

#endif // FNOFOCUSDELEGATE_H
