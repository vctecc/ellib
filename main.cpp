#include "loginmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginMenu login;
    login.show();

    return app.exec();
}
