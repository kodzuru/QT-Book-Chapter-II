#include "selectionmodel.h"
#include <QtWidgets>

SelectionModel::SelectionModel(QWidget *parent) : QWidget(parent)
{
    //QWidget *wgt = new QWidget();
    //wgt->setParent(this, Qt::Window);
    QStringListModel *model = new QStringListModel();
    model->setStringList(QStringList() << "Item1" << "Item2" << "Item3");

    QTreeView *pTreeView = new QTreeView();
    pTreeView->setModel(model);

    QListView *pListView = new QListView;
    pListView->setModel(model);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(model);



    QItemSelectionModel *selection = new QItemSelectionModel(model);
    pTreeView->setSelectionModel(selection);
    pListView->setSelectionModel(selection);
    pTableView->setSelectionModel(selection);

    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pTreeView);
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pTableView);

    setLayout(phbxLayout);

}
