#include "ipv4widgettest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IPv4WidgetTest w;
    w.show();
    return a.exec();
}
