#ifndef SIMPLEDELEGATE_H
#define SIMPLEDELEGATE_H

#include <QtWidgets>

class SimpleDelegate : public QStyledItemDelegate
{
public:
    SimpleDelegate(QObject *parent = 0);
    //~SimbpeDelegate();
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
};

#endif // SIMPLEDELEGATE_H
