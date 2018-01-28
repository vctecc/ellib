#include "editdocwindow.h"
#include <QtWidgets>

EditDocWindow::EditDocWindow(QWidget *parent)

{
    createMasterGroupBox();
    createAuditGroupBox();
    createFileGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QPushButton *okButton = new QPushButton(tr("Принять"));
    QPushButton *cancelButton = new QPushButton(tr("Отмена"));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel);

    mainLayout->addWidget(topGroupBox);
    mainLayout->addWidget(midGroupBox);
    mainLayout->addWidget(botGroupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);


    setWindowTitle(tr("Edit Document"));
}

void EditDocWindow::createMasterGroupBox()
{
    regNumEdit = new QLineEdit;
    nameEdit = new QLineEdit;
    authorEdit = new QLineEdit;

    sourceComboBox = new  QComboBox;
    sourceComboBox ->setEditable(true);
    processComboBox = new  QComboBox;
    processComboBox->setEditable(true);
    classComboBox = new  QComboBox;
    classComboBox->setEditable(true);
    nameEdit = new QLineEdit;
    authorEdit = new QLineEdit;


    topGroupBox = new QGroupBox;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Рег. номер")), 0, 0);
    layout->addWidget(regNumEdit, 1, 0);
    layout->addWidget(new QLabel(tr("Источник")), 0, 1);
    layout->addWidget(sourceComboBox, 1, 1);
    layout->addWidget(new QLabel(tr("Процесс")), 0, 2);
    layout->addWidget(processComboBox, 1, 2);
    layout->addWidget(new QLabel(tr("Категория")), 0, 3);
    layout->addWidget(classComboBox, 1, 3);
    layout->addWidget(new QLabel(tr("Автор")),2, 0);
    layout->addWidget(authorEdit,3, 0, 1, 4);
    topGroupBox->setLayout(layout);
}

void EditDocWindow::createAuditGroupBox()
{

    approvalDateComboBox = new QComboBox;
    approvalDateComboBox->setEditable(true);
    oderComboBox = new QComboBox;
    oderComboBox->setEditable(true);
    introDateComboBox = new QComboBox;
    introDateComboBox->setEditable(true);
    auditDateComboBox = new QComboBox;
    auditDateComboBox->setEditable(true);
    statusComboBox = new QComboBox;
    statusComboBox->setEditable(true);
    midGroupBox = new QGroupBox;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Утверждён")), 0, 0);
    layout->addWidget(approvalDateComboBox, 1, 0);
    layout->addWidget(new QLabel(tr("Номер приказа")), 0, 1);
    layout->addWidget(oderComboBox, 1, 1);
    layout->addWidget(new QLabel(tr("Введён")), 0, 2);
    layout->addWidget(introDateComboBox, 1, 2);
    layout->addWidget(new QLabel(tr("Следующая ревизия")), 0, 3);
    layout->addWidget(auditDateComboBox, 1, 3);
    layout->addWidget(new QLabel(tr("Статус")), 0, 4);
    layout->addWidget(statusComboBox, 1, 4);
    midGroupBox->setLayout(layout);
}

void EditDocWindow::createFileGroupBox()
{
    fileNameEdit = new QLineEdit;
    addRegNumEdit = new QLineEdit;
    applayEdit = new QLineEdit;
    botGroupBox = new QGroupBox;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Source File Name")), 0, 0);
    layout->addWidget(fileNameEdit, 1, 0);
    layout->addWidget(new QLabel(tr("Add reg number")), 2, 0);
    layout->addWidget(addRegNumEdit, 3, 0);
    layout->addWidget(new QLabel(tr("Applay to")), 4, 0);
    layout->addWidget(applayEdit, 5, 0);

    botGroupBox->setLayout(layout);
}
