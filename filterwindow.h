#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

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

class FilterWindow : public QWidget
{
    Q_OBJECT
public:
    FilterWindow(const QStringList &sources,
                 const QStringList &processes,
                 const QStringList &categories,
                 const QStringList &status,
                 QWidget *parent = 0);

private slots:
    void clearFilters();
    void applayFilters();

private:
    void createFilters();

    QComboBox *sourceComboBox;
    QComboBox *processComboBox;
    QComboBox *classComboBox;
    QComboBox *statusComboBox;
    QComboBox *authorComboBox;
    QLineEdit *approvalFromComboBox;
    QLineEdit *approvalToComboBox;
    QLineEdit *introFromComboBox;
    QLineEdit *introToComboBox;
    QLineEdit *auditFromComboBox;
    QLineEdit *auditToComboBox;

};

#endif // FILTERWINDOW_H
