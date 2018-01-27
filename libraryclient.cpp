#include <QtWidgets>
#include "libraryclient.h"

LibraryClient::LibraryClient(QWidget *parent) : QWidget(parent)
{
    label = new QLabel(tr("Hello world"));
    model = new QStandardItemModel(10, 6, this);

    tabel = new QTableView(this);
    tabel->setModel(model);
    tabel->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Рег. №"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Происхождение"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Процесс"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Статус"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Имя документа"));
}

