#include "inttablemodel.h"

IntTableModel::IntTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}
IntTableModel::IntTableModel(int nRow, int nColumns, QObject *parent)
    : QAbstractTableModel(parent),
      m_nRows(nRow),
      m_nColumns(nColumns)
{
}

QVariant IntTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

bool IntTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int IntTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_nRows;
}

int IntTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_nColumns;
}

QVariant IntTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    //данные модели
    QString str = QString("%1,%2").arg(index.row() + 1).arg(index.column() + 1);
    return (role == Qt::DisplayRole || role == Qt::EditRole)
            ? m_hash.value(index, QVariant(str))
            : QVariant();
}

bool IntTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        if(index.isValid() && role == Qt::EditRole){
            m_hash[index] = value;
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
    }
    return false;
}

Qt::ItemFlags IntTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable)
                           : flags; // FIXME: Implement me!
}
