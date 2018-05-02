#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QWidget>


QT_BEGIN_NAMESPACE
class QStringListModel;
class QStringList;
QT_END_NAMESPACE

class Setting : public QWidget
{
    Q_OBJECT

public:
   Setting();

   QStringList  *titels;

   QStringList *sources;
   QStringList *status;
   QStringList *processes;
   QStringList *categories;




};

#endif // SETTING_H
