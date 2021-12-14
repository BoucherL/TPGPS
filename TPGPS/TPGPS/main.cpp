#include "TPGPS.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPGPS w;
    w.show();
    return a.exec();
}
