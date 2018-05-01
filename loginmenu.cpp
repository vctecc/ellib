#include <QtWidgets>
#include "loginmenu.h"
#include "libraryclient.h"

LoginMenu::LoginMenu(QWidget *parent)
    : QWidget(parent)
{

    userLineEdit = new QLineEdit();
    passwdLineEdit = new QLineEdit();
    passwdLineEdit->setEchoMode(QLineEdit::Password);
    databaseLineEdit = new QLineEdit();


    enterButton = new QPushButton(tr("Войти"));
    enterButton->setDefault(true);
    enterButton->setEnabled(false);

    quitButton = new QPushButton(tr("Отмена"));

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


    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(new QLabel(tr("Пользователь:")), 0, 0);
    mainLayout->addWidget(userLineEdit, 0, 1);
    mainLayout->addWidget(new QLabel(tr("Пороль:")), 1, 0);
    mainLayout->addWidget(passwdLineEdit, 1, 1);
    mainLayout->addWidget(new QLabel(tr("База данных:")), 2, 0);
    mainLayout->addWidget(databaseLineEdit, 2, 1);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Подключение к БД"));
    userLineEdit->setFocus();
}

void LoginMenu::enableEnter()
{
    bool enable(!userLineEdit->text().isEmpty() && !passwdLineEdit->text().isEmpty() && !databaseLineEdit->text().isEmpty());
    enterButton->setEnabled(enable);
}

bool LoginMenu::checkUser()
{
    return true;
}

void LoginMenu::connectLibrary()
{
    if (this->checkUser())
    {
        client = new LibraryClient();
        this->close();
        client->show();
    }
}
