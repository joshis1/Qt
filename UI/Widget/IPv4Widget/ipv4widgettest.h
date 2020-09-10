#ifndef IPV4WIDGETTEST_H
#define IPV4WIDGETTEST_H

#include <QDialog>

namespace Ui {
class IPv4WidgetTest;
}

class IPv4WidgetTest : public QDialog
{
    Q_OBJECT

public:
    explicit IPv4WidgetTest(QWidget *parent = 0);
    ~IPv4WidgetTest();

private:
    Ui::IPv4WidgetTest *ui;
};

#endif // IPV4WIDGETTEST_H
