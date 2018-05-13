#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlTableModel>

#include <database.h>
#include "setting.h"

QT_BEGIN_NAMESPACE
class QMenu;
class QLabel;
class QStringListModel;
class QStringList;
QT_END_NAMESPACE

class LibraryClient : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryClient(QWidget *parent = 0);
    ~LibraryClient();

private slots:

    void newDocument();
    void editDocument();
    void slotUpdateModels();
    void slotEditDocument(QModelIndex index);
    void deleteDocument();

    void filterTurnOn();
    void filterTurnOff();
    void extendFilter();

private:

    QTableView *table;
    DataBase *db;
    QSqlTableModel *model;
    Setting *setting;
    //от это костыля нужно избавиться
    QString *sources;
    QString *processes;
    QString *categories;
    QString *status;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif
