#include "setting.h"

#include <QtWidgets>

Setting::Setting()
{



     sources = new QStringList;
    //sources << tr("Внешний") << tr("Внутренний");

    processes = new QStringList;
    //processes << tr("Производство") << tr("Менеджмент");

    categories = new QStringList;
    //categories << tr("Производство") << tr("Менеджмент");

    status = new QStringList;
    //status << tr("ГОСТ") << tr("Документы предприятия");
}
