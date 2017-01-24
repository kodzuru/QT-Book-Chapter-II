#include "mainwindow.h"
#include <QApplication>

#include <QStringListModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QHBoxLayout>
#include <QLayout>
#include <QWidget>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}
