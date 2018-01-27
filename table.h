#ifndef TABLE_H
#define TABLE_H

#include <QTableView>

class Table : public QTableView
{
    Q_OBJECT

public:
    Table(QAbstractItemModel * model);
    ~Table();


private:
    void initTable();
    void updateTableGeometry();


private slots:
    void updateSectionWidth(int localIndex, int oldSize, int newSize);
     void updateSectionHeight(int localIndex, int oldSize, int newSize);
};

#endif // TABLE_H
