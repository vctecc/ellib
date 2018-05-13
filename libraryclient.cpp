#include <QtWidgets>
#include "libraryclient.h"
#include "filterwindow.h"
#include "editdocwindow.h"
#include "newdocwindow.h"
#include "setting.h"
LibraryClient::LibraryClient(QWidget *parent) : QWidget(parent)
{
    setting = new Setting();
    db = new DataBase();
    db->connectToDataBase();

    this->setupModel(TABLE,
                     QStringList() << trUtf8("Рег. №")
                                   << trUtf8("Происхождение")
                                   << trUtf8("Процесс")
                                   << trUtf8("Категория")
                                   << trUtf8("Имя документа"));

    //Адский костыль
    sources = new QString();
    sources->append(tr("Внешний,"
                       "Внутренний"));

    processes = new QString();
    processes->append(tr("Заключение договоров,"
                         "Проектирование и разработка,"
                         "Закупки комплектующих и материалов,"
                         "Производство продукции,"
                         "Контроль и испытание,"
                         "Хранение и поставка,"
                         "Обеспечение средствами производства,"
                         "Обеспечение средствами контроля,"
                         "Обеспечение персоналом,"
                         "Обеспечение информацией,"
                         "Обеспечение иными ресурсами,"
                         "Планирование действий,"
                         "Документирование процедур,"
                         "Распределение ответственности,"
                         "Анализ со стороны руководства,"
                         "Улучшение результативности"));

    categories = new QString();
    categories->append("Положение,"
                       "Инструкция,"
                       "Журнал,"
                       "Технология,"
                       "Ведомость,"
                       "Стандарт,"
                       "Карта,"
                       "Пооперационная ведомость,"
                       "Перечень,"
                       "Регламент,"
                       "Руководство,"
                       "Технические условия,"
                       "Спецификация");

    status = new QString();
    status->append("Действующий,"
                   "Отменённый");

    //createDocBar();
    createUI();
}

LibraryClient::~LibraryClient()
{

}

void LibraryClient::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->select(); // Делаем выборку данных из таблицы

    /* Устанавливаем названия колонок в таблице с сортировкой данных
     */
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(0,Qt::AscendingOrder);
    model->select(); // Делаем выборку данных из таблицы
}

void LibraryClient::createUI()
{
    QHBoxLayout *layout;
    QGroupBox *documentGroupBox = new QGroupBox;

    QToolButton *newButton = new QToolButton;
    QToolButton *editButton = new QToolButton;
    QToolButton *deleteButton = new QToolButton;

    newButton->setText("Новый документ");
    editButton->setText("Редактировать документ");
    deleteButton->setText("Удалить документ");

    connect(newButton, SIGNAL(clicked()), this, SLOT(newDocument()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(slotEditDocument(QModelIndex)));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteDocument()));

    layout = new QHBoxLayout;
    layout->addWidget(newButton);
    layout->addWidget(editButton);
    layout->addWidget(deleteButton);
    documentGroupBox->setLayout(layout);

    QGroupBox *filterGroupBox = new QGroupBox;

    QToolButton *turnOnFilterButton = new QToolButton;
    QToolButton *turnOffFilterButton = new QToolButton;
    QToolButton *extendFilterButton = new QToolButton;

    turnOnFilterButton->setText("Фильтр по выделеному вкл");
    turnOffFilterButton->setText("Фильтр по выделеному выкл");
    extendFilterButton->setText("Расширенный фильтр");

    connect(turnOnFilterButton, SIGNAL(clicked()), this, SLOT(filterTurnOn()));
    connect(turnOffFilterButton, SIGNAL(clicked()), this, SLOT(filterTurnOff()));
    connect(extendFilterButton, SIGNAL(clicked()), this, SLOT(extendFilter()));

    layout = new QHBoxLayout;
    layout->addWidget(turnOnFilterButton);
    layout->addWidget(turnOffFilterButton);
    layout->addWidget(extendFilterButton);
    filterGroupBox->setLayout(layout);



    table = new QTableView(this);
    table->setRowHeight(100, 100);
    table->setModel(model);     // Устанавливаем модель на TableView
    // Разрешаем выделение строк
    //table->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    table->resizeColumnsToContents();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->setStretchLastSection(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(documentGroupBox, 0, 0);
    mainLayout->addWidget(filterGroupBox, 1, 0);
    mainLayout->addWidget(table, 2, 0);

    setLayout(mainLayout);
    setWindowTitle(tr("Электронная библиотека"));
    // Открытие окна редактирования по двойному клику по документу
    connect(table, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditDocument(QModelIndex)));
}


void LibraryClient::newDocument()
{
    QStringList sourcesList;
    QStringList processesList;
    QStringList categoriesList;

    sourcesList << sources->split(',');
    processesList <<processes->split(',');
    categoriesList << categories->split(',');

    /* Создаем диалог и подключаем его сигнал завершения работы
    * к слоту обновления вида модели представления данных
    * */
    NewDocWindow *creator = new NewDocWindow(sourcesList, processesList, categoriesList);
    connect(creator, SIGNAL(signalRegister()), this, SLOT(slotUpdateModels()));
    creator->show();
}

void LibraryClient::slotUpdateModels()
{
    qDebug()<<"SetUpModel";
    model->select();
}

void LibraryClient::slotEditDocument(QModelIndex index)
{
    QStringList sourcesList;
    QStringList processesList;
    QStringList categoriesList;
    QStringList statusList;;


    sourcesList << sources->split(',');
    processesList << processes->split(',');
    categoriesList << categories->split(',');
    statusList << status->split(',');

    EditDocWindow *editWindow = new EditDocWindow(sourcesList, processesList,
                                                  categoriesList, statusList, index.row());
    connect(editWindow, SIGNAL(signalReady()), this, SLOT(slotUpdateModels()));

    editWindow->show();

}

void LibraryClient::deleteDocument()
{

}

void LibraryClient::filterTurnOn()
{

}

void LibraryClient::filterTurnOff()
{

}

void LibraryClient::extendFilter()
{
    QStringList sourcesList;
    QStringList processesList;
    QStringList categoriesList;
    QStringList statusList;;


    sourcesList << sources->split(',');
    processesList << processes->split(',');
    categoriesList << categories->split(',');
    statusList << status->split(',');

    FilterWindow *filter = new FilterWindow(sourcesList, processesList,
                                            categoriesList, statusList);
    filter->show();
}
