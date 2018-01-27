#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
class QMenu;
class QLabel;
QT_END_NAMESPACE

class LibraryClient : public QWidget
{
    Q_OBJECT

public:
    LibraryClient(QWidget *parent = 0);


private:
    QLabel *label;
    QTableView *tabel;
    QStandardItemModel *model;
};

#endif
