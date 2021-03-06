/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "fmainwindow.h"
#include "futil.h"
#include <QtCore>

#include <QMouseEvent>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
#include <QDir>


FMainWindow::FMainWindow(QWidget *parent)
    : QMainWindow(parent),titleBar(FTitleBar::getInstace()),
      pstatusbar(new QStatusBar),flyWidget(new FlyWidget),
      trayicon (new QSystemTrayIcon
                (QIcon(QString(":/images/skin/images/ico.ico")), this))
{
    qDebug("fmainwindow init");
    initData();
    initUI();
    initConnect();
}

void FMainWindow::initData()
{
    leftbuttonpressed = false;
    m_isLocked = false;
}

void FMainWindow::initUI()
{
    setObjectName(QString("FMainWindow"));
    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());
    readSettings();

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("SuperConsole");

    pstatusbar->setFixedHeight(30);
    setStatusBar(pstatusbar);

    trayicon->setObjectName(QString("trayicon"));
    trayicon->setToolTip(QString(qApp->applicationName()));
    trayicon->show();


    flyWidget->move(desktopWidget->availableGeometry().width() * 0.8, desktopWidget->availableGeometry().height() *0.2);

}


void FMainWindow::initConnect( )
{
    connect(titleBar, SIGNAL(minimuned()), this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(closed()), this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(showMinimized()));
//    connect(titleBar, SIGNAL(minimuned()), this, SLOT(showFlyWidget()));
    connect(titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(hide()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(showFlyWidget()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
    connect(titleBar, SIGNAL(LockChanged(bool)), this, SLOT(setLocked(bool)));

    connect(flyWidget, SIGNAL(doubleClicked()), this, SLOT(onflyWidgetDoubleClicked()));
}

void FMainWindow::readSettings()
{
   QDesktopWidget* desktopWidget = QApplication::desktop();
   int w = desktopWidget->availableGeometry().width();
   int h = desktopWidget->availableGeometry().height();
   qDebug() << w << h;
   setMinimumSize(QSize(w * 0.5, h * 0.6));
   QSettings settings(QDir::currentPath() + "/SuperConsole.ini", QSettings::IniFormat);
   settings.beginGroup("FMainWindow");
   resize(settings.value("size", QSize(w * 0.7, h * 0.9)).toSize());
   move(settings.value("pos", QPoint(w * 0.2, h * 0.1)).toPoint());
   settings.endGroup();
   qDebug() << this->size();

}

void FMainWindow::writeSettings()
{
    QSettings settings(QDir::currentPath() + "/SuperConsole.ini", QSettings::IniFormat);
    qDebug(qPrintable(QDir::currentPath() + "/SuperConsole.ini"));
    qDebug() << this->size();
    settings.beginGroup("FMainWindow");
    settings.setValue("size", this->size());
    settings.setValue("pos", pos());
    settings.endGroup();


}

bool FMainWindow::isLocked()
{
    return m_isLocked;
}

void FMainWindow::setLocked(bool flag)
{
    m_isLocked = flag;
}

void FMainWindow::onflyWidgetDoubleClicked()
{
    this->setVisible(!isVisible());
}

FTitleBar* FMainWindow::getTitleBar()
{
    return titleBar;
}

QStatusBar* FMainWindow::getStatusBar()
{
    return pstatusbar;
}

QSystemTrayIcon* FMainWindow::getQSystemTrayIcon()
{
    return trayicon;
}

FlyWidget* FMainWindow::getFlyWidget()
{
    return flyWidget;
}

void FMainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}


void FMainWindow::showFlyWidget()
{
    flyWidget->show();
}

void FMainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)
        {
            leftbuttonpressed = false;
        }
        else
        {
            dragPosition = e->globalPos() - frameGeometry().topLeft();
            leftbuttonpressed = true;
        }
    }
    e->accept();
}

void FMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < titleBar->height() && e->x() < titleBar->width() - 120)
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void FMainWindow::SetCursorStyle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
    case eTop:
    case eBottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case eRight:
    case eLeft:
        setCursor(Qt::SizeHorCursor);
        break;
    case eNormal:
        setCursor(Qt::ArrowCursor);
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void FMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    titleBar->clearChecked();
    e->accept();
}

void FMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {

        if(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)
        {
            e->ignore();
        }
        else{
            if(leftbuttonpressed)
            {
                if(!isLocked())
                {
                    move(e->globalPos() - dragPosition);
                }
                e->accept();
            }

        }
    }

}

void FMainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        titleBar->getMaxButton()->click();
    }
}

void FMainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    QMainWindow::closeEvent(event);
}


void FMainWindow::animationClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}

void FMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //单击
        case QSystemTrayIcon::Trigger:
            //双击
        case QSystemTrayIcon::DoubleClick:
            if(isHidden())
            {
                //恢复窗口显示
                show();
                //一下两句缺一均不能有效将窗口置顶
                setWindowState(Qt::WindowActive);
                activateWindow();
                setLocked(m_isLocked);
            }
            else
            {
                if(! isLocked())
                {
                    hide();
                }
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}

FMainWindow::~FMainWindow()
{
    qDebug("fmainwindow exit");

}
