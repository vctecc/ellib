#ifndef EDITDOCWINDOW_H
#define EDITDOCWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE


class EditDocWindow : public QWidget
{
     Q_OBJECT
public:
    EditDocWindow(QWidget *parent = 0);

private:

    QLineEdit *regNumEdit;
    QLineEdit *sourceEdit;
    QLineEdit *processEdit;
    QLineEdit *classEdit;
    QLineEdit *nameEdit;
    QLineEdit *authorEdit;
};

#endif // EDITDOCWINDOW_H
