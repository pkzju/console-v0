/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "qmlviwer.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QFileDialog>
QmlViwer::QmlViwer(QWidget *parent) :
    QWidget(parent)
{
    initData();
    initUI();
    initConnect();
}

void QmlViwer::initData()
{

}

void QmlViwer::initUI()
{
    loadQmlButton = new QToolButton;
    loadQmlButton->setIcon(QIcon(":/skin/icons/dark/appbar.upload.png"));
    loadQmlButton->setIconSize(QSize(20, 20));
    loadQmlButton->setToolTip(QString("Load QML"));

    qmlUrlEdit = new QLineEdit;
    qmlUrlEdit->setFixedHeight(25);
    QHBoxLayout* loadLayout = new QHBoxLayout;
    loadLayout->addWidget(loadQmlButton);
    loadLayout->addWidget(qmlUrlEdit);

    viewer = new BaseQuickWidget;
    viewer->setSource(QUrl(QString("qrc:/home/qml/home.qml")));
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(loadLayout);
    mainLayout->addWidget(viewer);

    setLayout(mainLayout);


}

void QmlViwer::initConnect()
{
    connect(loadQmlButton, SIGNAL(clicked()), this, SLOT(getQmlUrl()));
    connect(qmlUrlEdit, SIGNAL(editingFinished()), this, SLOT(loadQml()));
    connect(qmlUrlEdit, SIGNAL(returnPressed()), this, SLOT(loadQml()));
    connect(qmlUrlEdit, SIGNAL(textChanged()), this, SLOT(loadQml()));
}

void QmlViwer::getQmlUrl()
{
    QString qmlurl = QFileDialog::getOpenFileName(this, tr("Open QML"), QDir::currentPath(), tr("QML Files(*.qml)"));
    if(qmlurl != QString(""))
    {
        qmlUrlEdit->setText(QString("file:///%1").arg(qmlurl));
    }
    else
    {
        viewer->setSource(QUrl(QString("qrc:/home/welcom.qml")));
        qmlUrlEdit->setText("");
    }

}

void QmlViwer::loadQml()
{
    viewer->setSource(QUrl(qmlUrlEdit->text()));
}




