#include "homewindow.h"
#include <QApplication>
#include "controlleradapter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControllerAdapter adapter;
    HomeWindow w(&adapter);
    w.show();

    return a.exec();
}
