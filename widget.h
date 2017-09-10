#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <table_widget.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    TableWidget *table_widget;
};

#endif // WIDGET_H
