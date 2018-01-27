#include <QtWidgets>
#include "loginmenu.h"
#include "libraryclient.h"

LoginMenu::LoginMenu(QWidget *parent)
    : QWidget(parent)
{
    userLabel = new QLabel(tr("User name:"));
    passwdLabel = new QLabel(tr("Password:"));
    databaseLabel  = new QLabel(tr("DataBase"));

    userLineEdit = new QLineEdit();
    passwdLineEdit = new QLineEdit();
    passwdLineEdit->setEchoMode(QLineEdit::Password);
    databaseLineEdit = new QLineEdit();

    userLabel->setBuddy(userLineEdit);
    passwdLabel->setBuddy(passwdLineEdit);
    databaseLabel->setBuddy(passwdLineEdit);

    enterButton = new QPushButton(tr("Enter"));
    enterButton->setDefault(true);
    enterButton->setEnabled(false);

    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(enterButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(enterButton, SIGNAL(clicked()), this, SLOT(connectLibrary()));

    connect(userLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableEnter()));
    connect(passwdLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableEnter()));
    connect(databaseLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableEnter()));


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(userLabel, 0, 0);
    mainLayout->addWidget(userLineEdit, 0, 1);
    mainLayout->addWidget(passwdLabel, 1, 0);
    mainLayout->addWidget(passwdLineEdit, 1, 1);
    mainLayout->addWidget(databaseLabel, 2, 0);
    mainLayout->addWidget(databaseLineEdit, 2, 1);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Connect to DB"));
    userLineEdit->setFocus();
}

void LoginMenu::enableEnter()
{
    bool enable(!userLineEdit->text().isEmpty() && !passwdLineEdit->text().isEmpty() && !databaseLineEdit->text().isEmpty());
    enterButton->setEnabled(enable);
}

void LoginMenu::connectLibrary()
{
    client = new LibraryClient();
    client->show();

}
