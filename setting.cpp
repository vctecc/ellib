#include "setting.h"

#include <QtWidgets>

Setting::Setting()
{
    QStringList sources;
    sources << tr("Внешний") << tr("Внутренний");
    sourceModel = new QStringListModel(sources, this);

    QStringList processes;
    processes << tr("Производство") << tr("Менеджмент");
    processModel = new QStringListModel(processes, this);

    QStringList categories;
    categories << tr("Производство") << tr("Менеджмент");
    categoryModel = new QStringListModel(categories, this);

    QStringList status;
    status << tr("ГОСТ") << tr("Документы предприятия");
    statusModel = new QStringListModel(status, this);
}
