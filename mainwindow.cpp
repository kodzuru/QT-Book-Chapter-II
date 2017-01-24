#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "simpledelegate.h"
#include "selectionmodel.h"
#include "initlistmodel.h"
#include "inttablemodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// selection model example
void MainWindow::on_pushButton_clicked()
{
    SelectionModel *item = new SelectionModel;
    item->show();

}
//delegate example
void MainWindow::on_pushButton_2_clicked()
{
    QStringListModel *model = new QStringListModel;
    model->setStringList(QStringList() << "Item1" << "Item2" << "Item3");

    QListView *listView = new QListView;
    listView->setModel(model);
    listView->setItemDelegate(new SimpleDelegate(listView));
    listView->viewport()->setAttribute(Qt::WA_Hover);
    listView->show();
}

//Hierarchical model example
void MainWindow::on_pushButton_3_clicked()
{
    QStandardItemModel *model = new QStandardItemModel(5, 10);

    for(int nTopRow(0); nTopRow < 5; ++nTopRow){
        QModelIndex index = model->index(nTopRow, 0);
        model->setData(index, "item" + QString::number(nTopRow + 1));

        model->insertRows(0, 10, index);
        model->insertColumns(0, 10, index);
        for(int nRow(0); nRow < 10; ++nRow){
            for(int nCol(0); nCol < 10; ++nCol){
                QString strPos = QString("%1, %2").arg(nRow).arg(nCol);
                model->setData(model->index(nRow, nCol, index), strPos);
            }
        }
    }
    QTreeView *pTreeView = new QTreeView;
    pTreeView->setModel(model);
    pTreeView->show();


}
//Directory tree path
void MainWindow::on_pushButton_4_clicked()
{
    QFileSystemModel *model = new QFileSystemModel();
    QTreeView *pTreeView = new QTreeView();

    model->setRootPath(QDir::rootPath());

    //QModelIndex *index = model->index(QDir::currentPath());
    //pTreeView->setRootIndex(index);
    pTreeView->setModel(model);
    pTreeView->show();
}
//Directory Explorer
void MainWindow::on_pushButton_5_clicked()
{
    QSplitter *spl = new QSplitter(Qt::Horizontal);
    QFileSystemModel *model = new QFileSystemModel;

    model->setRootPath(QDir::rootPath());

    QTreeView *pTreeView = new QTreeView;
    pTreeView->setModel(model);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(model);

    connect( pTreeView, SIGNAL(clicked(QModelIndex)), pTableView, SLOT(setRootIndex(QModelIndex)) );
    connect( pTableView, SIGNAL(activated(QModelIndex)), pTreeView, SLOT(setCurrentIndex(QModelIndex)) );
    connect( pTableView, SIGNAL(activated(QModelIndex)), pTableView, SLOT(setRootIndex(QModelIndex)) );

    spl->addWidget(pTreeView);
    spl->addWidget(pTableView);
    spl->resize(640, 480);
    spl->show();


}
//Role Example
void MainWindow::on_pushButton_6_clicked()
{
    QStringList lst;// = new QStringList;
    lst << "Linux" << "Windows" << "MacOSX" << "Android";

    QStandardItemModel *model = new QStandardItemModel(lst.size(), 1);
    for(int i(0); i < model->rowCount(); ++i){
        QModelIndex index = model->index(i, 0);
        QString str = lst.at(i);
        model->setData(index, str, Qt::DisplayRole);
        model->setData(index, "ToolTip  " + str, Qt::ToolTipRole);

        model->setData(index, QIcon(":/res/imgs/" + str + ".jpg"), Qt::DecorationRole);
    }
    QListView *pListView = new QListView;
    pListView->setViewMode(QListView::IconMode);
    pListView->setModel(model);
    pListView->show();


}

void MainWindow::on_pushButton_7_clicked()
{
    QSplitter *pSplitter = new QSplitter(Qt::Horizontal);
    InitListModel *model = new InitListModel(QList<int>() << 123 << 321 << 32 << 12 << 55);

    QListView *pListView = new QListView;
    pListView->setModel(model);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(model);


    pSplitter->addWidget(pListView);
    pSplitter->addWidget(pTableView);
    pSplitter->resize(640, 480);
    pSplitter->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    IntTableModel *model = new IntTableModel(10, 10);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(model);

    pTableView->show();
}
//Proxy model Example
void MainWindow::on_pushButton_9_clicked()
{
    QWidget *wgt = new QWidget;

    QStringListModel *model = new QStringListModel;
    model->setStringList(QStringList() << "Xandra"
                                       << "Epica"
                                       << "Therion"
                                       << "Evanescence"
                                       << "Nightwish");

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel(model);
    proxyModel->setFilterWildcard("E*");

    QListView *pListView = new QListView;
    pListView->setModel(model);

    QListView *pListView2 = new QListView;
    pListView2->setModel(proxyModel);

    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pListView2);
    wgt->setLayout(phbxLayout);
    wgt->show();

}

void MainWindow::on_pushButton_10_clicked()
{
    QWidget *wnd = new QWidget;


    QStringList lst;
    QListWidget *pListWidget = new QListWidget;
    QListWidgetItem *pItem = 0;

    pListWidget->setIconSize(QSize(48, 48));
    lst << "Linux" << "Windows" << "MacOSX" << "Android";

    foreach (QString str, lst) {
        pItem = new QListWidgetItem(str, pListWidget);
        pItem->setIcon(QPixmap(":/res/imgs/" + str + ".jpg"));
    }
    pListWidget->setWindowTitle("ListWidget");

    QListView * pListView = new QListView;
    pListView->setModel(pListWidget->model());
    pListView->setSelectionModel(pListWidget->selectionModel());
    pListView->setWindowTitle("ListView");

    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pListWidget);
    phbxLayout->addWidget(pListView);
    wnd->setLayout(phbxLayout);
    wnd->resize(640, 480);
    wnd->show();


}

void MainWindow::on_pushButton_11_clicked()
{



    QSpinBox *pSpinBox = new QSpinBox;
    QPalette pal =  pSpinBox->palette();



    pal.setBrush(QPalette::Button, QBrush(Qt::red, Qt::Dense3Pattern) );
    pal.setColor( QPalette::ButtonText, Qt::blue );
    pal.setColor( QPalette::Text, Qt::magenta );
    pal.setColor( QPalette::Active, QPalette::Base ,Qt::green );

    pSpinBox->setPalette(pal);
    pSpinBox->resize(50, 50);
    QFont font = pSpinBox->font();
    font.setPointSize(20);
    pSpinBox->setFont( font );

    pSpinBox->show();


}
