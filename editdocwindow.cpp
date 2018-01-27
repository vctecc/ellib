#include "editdocwindow.h"
#include <QtWidgets>

EditDocWindow::EditDocWindow(QWidget *parent)

{
    regNumEdit = new QLineEdit;
    QLabel *regNumLabel = new QLabel;
    regNumLabel->setText(tr("Number"));

    sourceEdit = new QLineEdit;
    QLabel *sourceLabel = new QLabel;
    sourceLabel->setText(tr("Source"));

    processEdit = new QLineEdit;
    QLabel *processLabel = new QLabel;
    processLabel->setText(tr("Process"));

    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget();
}
