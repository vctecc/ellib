#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QWidget>


QT_BEGIN_NAMESPACE
class QStringListModel;
QT_END_NAMESPACE

class Setting : public QWidget
{
    Q_OBJECT

public:
   Setting();
   QStringListModel *sourceModel;
   QStringListModel *processModel;
   QStringListModel *categoryModel;
   QStringListModel *statusModel;
   QStringList *status;

};

#endif // SETTING_H
