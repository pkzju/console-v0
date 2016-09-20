/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "basequickwidget.h"
#include<QQmlEngine>
#include<QDir>
BaseQuickWidget::BaseQuickWidget(QWidget *parent) :
    QQuickWidget(parent)
{
    setResizeMode(QQuickWidget::SizeRootObjectToView);
    engine()->addImportPath(QString("%1/qml/").arg(QDir::currentPath()));
    qDebug(qPrintable(QString("%1/qml/").arg(QDir::currentPath())));
}
