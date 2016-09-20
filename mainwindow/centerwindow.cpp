/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "centerwindow.h"
#include <QHBoxLayout>
#include <qgridlayout.h>
#include "QFramer/ftabwidget.h"

#include "userui/canui.h"
#include "userui/mplotui.h"
#include "userui/modbusui.h"
#include "userui/homewindow.h"

#include "userui/serialportui.h"
#include "userui/tcpclientframe.h"
#include "userui/tcpserverframe.h"

#include "userui/fanhomeframe.h"


CenterWindow::CenterWindow(QWidget *parent) :
    FCenterWindow(parent)
{
    qDebug("CenterWindow init");

    initData();
    initUI();
    initConnect();
}

CenterWindow::~CenterWindow()
{
    CANUi::deleteInstance();
    MPlotUi::deleteInstance();
    ModbusUi::deleteInstance();
    homewindow::deleteInstance();

    qDebug("CenterWindow exit");
}

void CenterWindow::initData()
{
    while(motorGroups.count() < gGroupnum){
        int _groupID = motorGroups.count()+1;
//        int _fanMaxNumber = gMotorMaxnum;
//        int _startAdd = (_groupID-1)*_fanMaxNumber + 1;
        FanGroupInfo *group = new FanGroupInfo(_groupID);
//        group->m_monitorDialog = Q_NULLPTR;
        motorGroups.push_back(group);
    }
}

void CenterWindow::initUI()
{
    setObjectName(tr("needBorder"));

    CANUi *m_canUi{CANUi::getS_Instance()};
//    MPlotUi *m_plotUi{MPlotUi::getInstance()};
    ModbusUi *m_modbusui{ModbusUi::getInstance()};
//    homewindow *m_home{homewindow::getInstance()};

    SerialPortUi *serialport{new SerialPortUi(this)};
//    TcpClientFrame *_TcpClientFrame = new TcpClientFrame(this);
//    TcpServerFrame *_TcpServerFrame = new TcpServerFrame(this);

//    addWidget(tr("TcpClient"),"serialportBtn", _TcpClientFrame);
//    addWidget(tr("TcpServer"),"serialportBtn", _TcpServerFrame);
//    addWidget(tr("Home"), "Home", m_home);
//    addWidget(tr("Scope"), "MathPlot", m_plotUi);
    addWidget(tr("Canbus"),"Communication", m_canUi);
    addWidget(tr("Modbus"),"Communication", m_modbusui);
    addWidget(tr("COMPort"),"serialportBtn", serialport);

//for(int i=0; i<gGroupnum; i+=2){
//    FanHomeFrame *fanHome = new FanHomeFrame;
//    fanHome->setGroup(&motorGroups, i, 2);
//    addWidget(tr("Home%1").arg(i/2+1), "Home", fanHome);
//}

//    FanHomeFrame *fanHome1 = new FanHomeFrame;
//    fanHome1->setGroup(&motorGroups, 0, 2);
//    addWidget(tr("Home1"), "Home", fanHome1);

//    FanHomeFrame *fanHome2 = new FanHomeFrame;
//    fanHome2->setGroup(&motorGroups, 2, 2);
//    addWidget(tr("Home2"), "Home", fanHome2);
//    FanHomeFrame *fanHome3 = new FanHomeFrame;
//    fanHome3->setGroup(&motorGroups, 4, 2);
//    addWidget(tr("Home3"), "Home", fanHome3);
//    FanHomeFrame *fanHome4 = new FanHomeFrame;
//    fanHome4->setGroup(&motorGroups, 6, 2);
//    addWidget(tr("Home4"), "Home", fanHome4);
    setAlignment(TopCenter);
}

void CenterWindow::initConnect()
{

}

QVector<FanGroupInfo *> &CenterWindow::getGroups()
{
    return motorGroups;

}



