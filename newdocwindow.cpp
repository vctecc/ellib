#include "newdocwindow.h"
#include <QtWidgets>

NewDocWindow::NewDocWindow(QWidget *parent)
{
    setWindowTitle(tr("Ввод нового докуента"));

    //Создание полей ввода
    sourceComboBox = new QComboBox;
    sourceComboBox->setEditable(true);
    processComboBox = new QComboBox;
    processComboBox->setEditable(true);
    categoryComboBox = new QComboBox;
    categoryComboBox->setEditable(true);
    nameEdit = new QLineEdit;

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
