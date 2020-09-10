#include "ipv4widgettest.h"
#include "ui_ipv4widgettest.h"

/* Test function to test ipv4Edit Widget **/

IPv4WidgetTest::IPv4WidgetTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IPv4WidgetTest)
{
    ui->setupUi(this);
}

IPv4WidgetTest::~IPv4WidgetTest()
{
    delete ui;
}
