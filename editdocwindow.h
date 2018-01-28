#ifndef EDITDOCWINDOW_H
#define EDITDOCWINDOW_H

#include <QWidget>

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
    EditDocWindow(QWidget *parent = 0);

private:
    void createMasterGroupBox();
    void createAuditGroupBox();
    void createFileGroupBox();

    QLineEdit *regNumEdit;
    QLineEdit *nameEdit;
    QLineEdit *authorEdit;
    QLineEdit *addRegNumEdit;
    QLineEdit *fileNameEdit;
    QLineEdit *applayEdit;
    QLineEdit *masterEdit;

    QComboBox *sourceComboBox;
    QComboBox *processComboBox;
    QComboBox *classComboBox;
    QComboBox *approvalDateComboBox;
    QComboBox *introDateComboBox;
    QComboBox *auditDateComboBox;
    QComboBox *oderComboBox;
    QComboBox *statusComboBox;
    QGroupBox *topGroupBox;
    QGroupBox *midGroupBox;
    QGroupBox *botGroupBox;

    QDialogButtonBox *buttonBox;
};

#endif // EDITDOCWINDOW_H
