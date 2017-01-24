#ifndef INTTABLEMODEL_H
#define INTTABLEMODEL_H

#include <QAbstractTableModel>

class IntTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit IntTableModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    int m_nRows;
    int m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;
public:
    IntTableModel(int, int, QObject *parent = 0);
};

#endif // INTTABLEMODEL_H
