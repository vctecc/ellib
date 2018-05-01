//#include "loginmenu.h"
//#include "editdocwindow.h"

//#include "filterwindow.h"
#include "libraryclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //LoginMenu login;
    //FilterWindow w;
    // EditDocWindow login;
    LibraryClient login;
    login.show();

    return app.exec();
}
