/****************************************************************************
**
** Copyright (C) 2016 pkzju
** Version	: 0.0.1.0
** Author	: pkzju
** 
****************************************************************************/

#include "writeregistermodel.h"
#include  <QDebug>

#define ROW_COUNT 30
#define COLUMN_COUNT 3

#define COLUMN_NUM 0
#define COLUMN_COILS 1
#define COLUMN_HOLDING 2

WriteRegisterModel::WriteRegisterModel(QObject *parent)
    : QAbstractTableModel(parent),
      m_coils(ROW_COUNT, false), m_holdingRegisters(ROW_COUNT, 0u)
{

    setData(this->index(1,COLUMN_HOLDING), QString::number(16), Qt::EditRole);
}

int WriteRegisterModel::rowCount(const QModelIndex &/*parent*/) const
{
    return ROW_COUNT;
}

int WriteRegisterModel::columnCount(const QModelIndex &/*parent*/) const
{
    return COLUMN_COUNT;
}

QVariant WriteRegisterModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= ROW_COUNT || index.column() >= COLUMN_COUNT)
        return QVariant();

    Q_ASSERT(m_coils.count() == ROW_COUNT);
    Q_ASSERT(m_holdingRegisters.count() == ROW_COUNT);

    if (index.column() == COLUMN_NUM && role == Qt::DisplayRole)
        return QString("0x%1").arg(QString::number((index.row()+m_address), 16));

    if (index.column() == COLUMN_COILS && role == Qt::CheckStateRole) // coils
        return m_coils.at(index.row()) ? Qt::Checked : Qt::Unchecked;

    else if (index.column() == COLUMN_HOLDING && role == Qt::DisplayRole) //holding registers
        return QString("0x%1").arg(QString::number(m_holdingRegisters.at(index.row()), 16));

    return QVariant();

}

QVariant WriteRegisterModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case COLUMN_NUM:
            return QStringLiteral("Address");
        case COLUMN_COILS:
            return QStringLiteral("Coils  ");
        case COLUMN_HOLDING:
            return QStringLiteral("Holding Registers");
        default:
            break;
        }
    }
    return QVariant();
}

bool WriteRegisterModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() ||  index.row() >= ROW_COUNT || index.column() >= COLUMN_COUNT)
        return false;

    Q_ASSERT(m_coils.count() == ROW_COUNT);
    Q_ASSERT(m_holdingRegisters.count() == ROW_COUNT);


    if (index.column() == COLUMN_COILS && role == Qt::CheckStateRole) { // coils
        Qt::CheckState s = static_cast<Qt::CheckState>(value.toUInt());
        s == Qt::Checked ? m_coils.setBit(index.row()) : m_coils.clearBit(index.row());
        emit dataChanged(index, index);
        return true;
    }

    if (index.column() == COLUMN_HOLDING && Qt::EditRole) { // holding registers
        bool result = false;
        quint16 newValue = value.toString().toUShort(&result, 16);
        if (result)
            m_holdingRegisters[index.row()] = newValue;

        emit dataChanged(index, index);
        return result;
    }


    return false;
}

Qt::ItemFlags WriteRegisterModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || index.row() >= ROW_COUNT || index.column() >= COLUMN_COUNT)
        return QAbstractTableModel::flags(index);

    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if (index.row() >= m_number)
        flags &= ~Qt::ItemIsEnabled;

    if (index.column() == COLUMN_COILS) //coils
        return flags | Qt::ItemIsUserCheckable;
    if (index.column() == COLUMN_HOLDING) //holding registers
        return flags | Qt::ItemIsEditable;

    return flags;
}

void WriteRegisterModel::setStartAddress(int address)
{
    m_address = address;
    emit updateViewport();
}

void WriteRegisterModel::setNumberOfValues(const QString &number)
{
    m_number = number.toInt();
    emit updateViewport();
}
