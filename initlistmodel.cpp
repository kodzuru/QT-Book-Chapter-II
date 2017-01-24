#include "initlistmodel.h"

InitListModel::InitListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}
InitListModel::InitListModel(QList<int> &list, QObject *parent)
    : QAbstractListModel(parent)
    , m_list(list)
{
}

QVariant InitListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    return (orientation == Qt::Horizontal)
            ? QString("Number")
            : QString::number(section);
}

bool InitListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int InitListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return m_list.size();
    // FIXME: Implement me!
}

QVariant InitListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return (role == Qt::DisplayRole || role == Qt::EditRole)
            ? m_list.at(index.row())
            : QVariant();
}

bool InitListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        if(index.isValid() && role == Qt::EditRole){
            m_list.replace(index.row(), value.value<int>());
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
    }
    return false;
}

Qt::ItemFlags InitListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    Qt::ItemFlags flags = QAbstractListModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable)
                           :  flags;// FIXME: Implement me!
}
