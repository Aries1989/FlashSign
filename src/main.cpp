#include "FlashSign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlashSign w;
    w.SetPowerLeft(0.5);

    w.show();

    return a.exec();
}
