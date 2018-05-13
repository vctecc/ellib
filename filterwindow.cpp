#include "filterwindow.h"
#include <QtWidgets>

FilterWindow::FilterWindow(const QStringList &sources,
                           const QStringList &processes,
                           const QStringList &categories,
                           const QStringList &status,
                           QWidget *parent)
{
    setWindowTitle(tr("Фильтры"));
    createFilters();

    //Задание моделей
    sourceComboBox->setModel(new QStringListModel(sources, this));
    processComboBox->setModel(new QStringListModel(processes, this));
    classComboBox->setModel(new QStringListModel(categories, this));
    statusComboBox->setModel(new QStringListModel(status, this));
}

void FilterWindow::createFilters()
{
    QString timeMask = "99.99.99";

    //Создание полей ввода
    sourceComboBox = new QComboBox;
    sourceComboBox->setEditable(true);


    processComboBox = new QComboBox;
    processComboBox->setEditable(true);

    classComboBox = new QComboBox;
    classComboBox->setEditable(true);

    statusComboBox = new QComboBox;
    statusComboBox->setEditable(true);

    authorComboBox = new QComboBox;
    authorComboBox->setEditable(true);

    approvalFromComboBox = new QLineEdit;
    approvalFromComboBox->setInputMask(timeMask);
    approvalFromComboBox->setMaxLength(8);
    approvalToComboBox = new QLineEdit;
    approvalToComboBox->setInputMask(timeMask);
    introFromComboBox = new QLineEdit;
    introFromComboBox->setInputMask(timeMask);
    introToComboBox = new QLineEdit;
    introToComboBox->setInputMask(timeMask);
    auditFromComboBox = new QLineEdit;
    auditFromComboBox->setInputMask(timeMask);
    auditToComboBox = new QLineEdit;
    auditToComboBox->setInputMask(timeMask);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(new QLabel(tr("Происхождение")), 0, 0);
    layout->addWidget(sourceComboBox, 1, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Процесс")), 2, 0);
    layout->addWidget(processComboBox, 3, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Категория")), 4, 0);
    layout->addWidget(classComboBox, 5, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Статус")), 6, 0);
    layout->addWidget(statusComboBox, 7, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Автор")), 8, 0);
    layout->addWidget(authorComboBox, 9, 0, 1, 2);

    layout->addWidget(new QLabel(tr("Утвержден с")), 0, 3);
    layout->addWidget(approvalFromComboBox, 1, 3);

    layout->addWidget(new QLabel(tr("Утвержден до")), 0, 4);
    layout->addWidget(approvalToComboBox, 1, 4);

    layout->addWidget(new QLabel(tr("Введен с")), 2, 3);
    layout->addWidget(introFromComboBox, 3, 3);

    layout->addWidget(new QLabel(tr("Введен до")), 2, 4);
    layout->addWidget(introToComboBox, 3, 4);

    layout->addWidget(new QLabel(tr("Очередная ревизия с")), 4, 3);
    layout->addWidget(auditFromComboBox, 5, 3);

    layout->addWidget(new QLabel(tr("Очередная ревизия до")), 4, 4);
    layout->addWidget(auditToComboBox, 5, 4);

    QPushButton *clearButton = new QPushButton(tr("Очистить"));
    layout->addWidget(clearButton, 9, 4);

    QHBoxLayout *downlayout = new QHBoxLayout;
    QPushButton *applayButton = new QPushButton(tr("Применить"));
    QPushButton *cancelButton = new QPushButton(tr("Отмена"));

    downlayout->setAlignment(Qt::AlignRight);
    downlayout->addWidget(cancelButton);
    downlayout->addWidget(applayButton);

    QGroupBox *buttonBox = new QGroupBox;
    buttonBox->setLayout(downlayout);

    layout->addWidget(buttonBox, 10, 0, 1, 5);
    layout->setColumnStretch(1, 10);
    setLayout(layout);

    connect(clearButton, SIGNAL(clicked()), this, SLOT(clearFilters()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));


}

void FilterWindow::clearFilters()
{
    sourceComboBox->clearEditText();
    processComboBox->clearEditText();
    classComboBox->clearEditText();
    statusComboBox->clearEditText();
    authorComboBox->clearEditText();
    approvalFromComboBox->clear();
    approvalToComboBox->clear();
    introFromComboBox->clear();
    introToComboBox->clear();
    auditFromComboBox->clear();
    auditToComboBox->clear();
}

void FilterWindow::applayFilters()
{

}
