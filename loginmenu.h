#ifndef LOGINMENU_H
#define LOGINMENU_H

#include "libraryclient.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE

class LoginMenu : public QWidget
{
    Q_OBJECT

public:
    LoginMenu(QWidget *parent = 0);

private slots:
    void enableEnter();
    bool checkUser();
    void connectLibrary();

private:

    QLineEdit *userLineEdit;
    QLineEdit *passwdLineEdit;
    QLineEdit *databaseLineEdit;

    QPushButton *enterButton;
    QPushButton *quitButton;

    QDialogButtonBox *buttonBox;

    LibraryClient *client;

};
#endif
