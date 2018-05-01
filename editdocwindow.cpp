#include "editdocwindow.h"
#include "loginmenu.h"
#include "setting.h"
#include <QtWidgets>

EditDocWindow::EditDocWindow(const QStringList &sources,
                             const QStringList &processes,
                             const QStringList &categories,
                             const QStringList &status,
                             QWidget *parent)

{
    setWindowTitle(tr("Редактирование документа"));

    //Setting setting;
    //Создание верннего раздела полей
    regNumEdit = new QLineEdit;

    sourceComboBox = new  QComboBox;
    sourceComboBox ->setEditable(true);

    sourceComboBox->setModel(new QStringListModel(sources, this));

    processComboBox = new  QComboBox;
    processComboBox->setEditable(true);
    processComboBox->setModel(new QStringListModel(processes, this));

    categoryComboBox = new QComboBox;
    categoryComboBox->setEditable(true);
    categoryComboBox->setModel(new QStringListModel(categories, this));

    nameEdit = new QLineEdit;

    QGroupBox *topGroupBox = new QGroupBox;
    QGridLayout *topLayout = new QGridLayout;

    topLayout->addWidget(new QLabel(tr("Рег. номер")), 0, 0);
    topLayout->addWidget(regNumEdit, 1, 0);
    topLayout->addWidget(new QLabel(tr("Происхождение")), 0, 1);
    topLayout->addWidget(sourceComboBox, 1, 1);
    topLayout->addWidget(new QLabel(tr("Процесс")), 0, 2);
    topLayout->addWidget(processComboBox, 1, 2);
    topLayout->addWidget(new QLabel(tr("Категория")), 0, 3);
    topLayout->addWidget(categoryComboBox, 1, 3);
    topLayout->addWidget(new QLabel(tr("Имя документа")),2, 0);
    topLayout->addWidget(nameEdit,3, 0, 1, 4);
    topGroupBox->setLayout(topLayout);

    //Создание среднего раздела полей
    QGroupBox *midGroupBox = new QGroupBox;
    QGridLayout *midLayout = new QGridLayout;

    approvalDateComboBox = new QComboBox;
    approvalDateComboBox->setEditable(true);
    oderEdit = new QLineEdit;
    introDateComboBox = new QComboBox;
    introDateComboBox->setEditable(true);
    auditDateComboBox = new QComboBox;
    auditDateComboBox->setEditable(true);

    statusComboBox = new QComboBox;
    statusComboBox->setEditable(true);
    statusComboBox->setModel(new QStringListModel(status, this));

    midLayout->addWidget(new QLabel(tr("Утверждён:")), 0, 0);
    midLayout->addWidget(approvalDateComboBox, 1, 0);
    midLayout->addWidget(new QLabel(tr("Номер приказа")), 0, 1);
    midLayout->addWidget(oderEdit, 1, 1);
    midLayout->addWidget(new QLabel(tr("Введён:")), 0, 2);
    midLayout->addWidget(introDateComboBox, 1, 2);
    midLayout->addWidget(new QLabel(tr("Следующая ревизия:")), 0, 3);
    midLayout->addWidget(auditDateComboBox, 1, 3);
    midLayout->addWidget(new QLabel(tr("Статус:")), 0, 4);
    midLayout->addWidget(statusComboBox, 1, 4);
    midGroupBox->setLayout(midLayout);

    //Создание нижнего раздела полей
    QGridLayout *botLayout = new QGridLayout;
    QGroupBox *botGroupBox = new QGroupBox;

    authorEdit = new QLineEdit;
    fileNameEdit = new QLineEdit;
    addRegNumEdit = new QLineEdit;
    applayEdit = new QLineEdit;

    botLayout->addWidget(new QLabel(tr("Автор:")), 0, 0);
    botLayout->addWidget(authorEdit, 1, 0);
    botLayout->addWidget(new QLabel(tr("Наименование исходного файла документа:")), 2, 0);
    botLayout->addWidget(fileNameEdit, 2, 0);
    botLayout->addWidget(new QLabel(tr("Дополнительный рег. номер")), 3, 0);
    botLayout->addWidget(addRegNumEdit, 4, 0);
    botLayout->addWidget(new QLabel(tr("Распространяется на")), 5, 0);
    botLayout->addWidget(applayEdit, 6, 0);
    botGroupBox->setLayout(botLayout);


    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(topGroupBox);
    mainLayout->addWidget(midGroupBox);
    mainLayout->addWidget(botGroupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

}

void EditDocWindow::setA(const QStringList &setting)
{

}
