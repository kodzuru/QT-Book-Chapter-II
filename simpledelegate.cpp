#include "simpledelegate.h"

SimpleDelegate::SimpleDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void SimpleDelegate::paint(QPainter *painter,
                      const QStyleOptionViewItem &option,
                      const QModelIndex &index) const{

    if(option.state & QStyle::State_MouseOver){
        QRect rect = option.rect;
        QLinearGradient gradient(0, 0, rect.width(), rect.height());
        gradient.setColorAt(0, Qt::white);
        gradient.setColorAt(0.5, Qt::blue);
        gradient.setColorAt(1, Qt::green);
        painter->setBrush(gradient);
        painter->drawRect(rect);
    }
    QStyledItemDelegate::paint(painter, option, index);
}
