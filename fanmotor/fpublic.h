/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#ifndef FPUBLIC_H
#define FPUBLIC_H

#include "qmotor.h"
#include "dialogs/groupmonitordialog.h"

const int gGroupnum = 4; //Number of all groups
const int gMotorMaxnum = 3;

//! \brief g_responseTimeout for modbus device request timeout set
const int g_responseTimeout = 50;

//! \brief g_numberOfTry for modbus device request number of try
const int g_numberOfTry = 2;

enum CommunicationMode:char{
    Init,
    Tcp,
    Modbus,
    CANbus
};

class FanGroupInfo{

public:
    FanGroupInfo(quint16 id):
      m_groupID(id)
      ,m_startAddress((id-1)*gMotorMaxnum + 1)
      ,m_fanMaxNumber(gMotorMaxnum)
    {
        for(int i = 0; i < m_fanMaxNumber; i++){
            m_motors.push_back(new QMotor(m_startAddress + i));
        }
        m_monitorDialog = Q_NULLPTR;
    }

public:

    GroupMonitorDialog *m_monitorDialog;

    quint16 m_groupID;
    quint16 m_startAddress;
    quint16 m_fanMaxNumber;
    QVector<QMotor *> m_motors;



};

#endif // FPUBLIC_H
