#include "newdocwindow.h"
#include <QtWidgets>

NewDocWindow::NewDocWindow(const QStringList &sources,
                           const QStringList &processes,
                           const QStringList &categories,
                           QWidget *parent)
{
    setWindowTitle(tr("Ввод нового докуента"));

    //Создание полей ввода
    sourceComboBox = new QComboBox;
    processComboBox = new QComboBox;
    categoryComboBox = new QComboBox;
    nameEdit = new QLineEdit;

    sourceComboBox->setEditable(true);
    processComboBox->setEditable(true);
    categoryComboBox->setEditable(true);

    sourceComboBox->setModel(new QStringListModel(sources, this));
    processComboBox->setModel(new QStringListModel(processes, this));
    categoryComboBox->setModel(new QStringListModel(categories, this));



    QGridLayout *layout = new QGridLayout;

    layout->addWidget(new QLabel(tr("Происхождение")), 0, 0);
    layout->addWidget(sourceComboBox, 1, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Процесс")), 2, 0);
    layout->addWidget(processComboBox, 3, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Категория")), 4, 0);
    layout->addWidget(categoryComboBox, 5, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Имя документа")), 6, 0);
    layout->addWidget(nameEdit, 7, 0, 1, 2);


    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *applayButton = new QPushButton(tr("Зарегистрировать"));
    QPushButton *cancelButton = new QPushButton(tr("Отмена"));

    buttonLayout->setAlignment(Qt::AlignRight);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(applayButton);

    QGroupBox *buttonBox = new QGroupBox;
    buttonBox->setLayout(buttonLayout);

    layout->addWidget(buttonBox, 8, 0, 1, 5);
    //layout->setColumnStretch(1, 10);
    setLayout(layout);

    connect(applayButton, SIGNAL(clicked()), this, SLOT(clearFilters()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}
