#ifndef EDITDOCWINDOW_H
#define EDITDOCWINDOW_H

#include <QWidget>
#include "setting.h"

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QGroupBox;
class QComboBox;
class QAction;
QT_END_NAMESPACE


class EditDocWindow : public QWidget
{
     Q_OBJECT

public:
    EditDocWindow(const QStringList &sources,
                  const QStringList &processes,
                  const QStringList &categories,
                  const QStringList &status,
                  QWidget *parent = 0);
    //~EditDocWindow();

    void setA(const QStringList &source);

private:
    void createMasterGroupBox();
    QLineEdit *regNumEdit;
    QComboBox *sourceComboBox;
    QComboBox *processComboBox;
    QComboBox *categoryComboBox;
    QLineEdit *nameEdit;

    QComboBox *introDateComboBox;
    QLineEdit *oderEdit;
    QComboBox *approvalDateComboBox;
    QComboBox *auditDateComboBox;
    QComboBox *statusComboBox;

    QLineEdit *authorEdit;
    QLineEdit *addRegNumEdit;
    QLineEdit *fileNameEdit;
    QLineEdit *applayEdit;
    //QLineEdit *masterEdit;

};

#endif // EDITDOCWINDOW_H
