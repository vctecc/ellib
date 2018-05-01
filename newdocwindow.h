#ifndef NEWDOCWINDOW_H
#define NEWDOCWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QGroupBox;
class QComboBox;
class QAction;
class QGridLayout;
class QDialogButtonBox;
class QHBoxLayout;
QT_END_NAMESPACE

class NewDocWindow : public QWidget
{
    Q_OBJECT

public:
    NewDocWindow(const QStringList &sources,
                 const QStringList &processes,
                 const QStringList &categories,
                 QWidget *parent = 0);

private:

    QComboBox *sourceComboBox;
    QComboBox *processComboBox;
    QComboBox *categoryComboBox;
    QLineEdit *nameEdit;


};

#endif // NEWDOCWINDOW_H
