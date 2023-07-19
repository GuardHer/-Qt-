#include "widget.h"

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource("./nilu.rcc");
    Widget w;
    w.show();
    return a.exec();
}
