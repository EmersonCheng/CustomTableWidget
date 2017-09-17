#include "table_widget.h"
#include <QDebug>

TableWidget::TableWidget(int row, int column, QWidget *parent) :
    QFrame(parent),row(row),column(column)
{
    setFrameStyle(QFrame::Box);
    layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            QLabel *label = new QLabel(this);
            label->setFrameStyle(QFrame::Box);
            label->setAlignment(Qt::AlignVCenter);
            label->setAutoFillBackground(true);
            layout->addWidget(label,i,j);
        }
    }

    QLabel *label = static_cast<QLabel *>(layout->itemAtPosition(0,0)->widget());
    default_background_color_palette.setColor(QPalette::Window,label->palette().color(QPalette::Window));
}

void TableWidget::SetText(int row, int column, const QString &text)
{
    QLabel *label = static_cast<QLabel *>(layout->itemAtPosition(row,column)->widget());
    label->setText(text);
}

void TableWidget::HideRow(int row, bool visible)
{
    for(int j = 0; j < column; j++)
        layout->itemAtPosition(row,j)->widget()->setVisible(!visible);
}

void TableWidget::SetCellBackgroundColor(int row, int column, const QColor &color)
{
    QLabel *label = static_cast<QLabel *>(layout->itemAtPosition(row,column)->widget());
    if(label->palette().color(QPalette::Window) == color)
        return;
    QPalette palette = label->palette();
    palette.setColor(QPalette::Window,color);
    label->setPalette(palette);
}

void TableWidget::ResetAllCellsBackgroundColor()
{
    for(int i = 0; i < layout->rowCount(); i++)
    {
        for(int j = 0; j < layout->columnCount(); j++)
        {
            QLabel *label = static_cast<QLabel *>(layout->itemAtPosition(i,j)->widget());
            label->setPalette(default_background_color_palette);
        }
    }
}

void TableWidget::SetAlignment(int row, int column, Qt::Alignment alignment)
{
    QLabel *label = static_cast<QLabel *>(layout->itemAtPosition(row,column)->widget());
    label->setAlignment(alignment);
}

void TableWidget::SetColumnWidth(int column, int width)
{
    for(int i = 0; i < layout->rowCount(); i++)
    {
        QLabel *label = static_cast<QLabel *>(layout->itemAtPosition(i,column)->widget());
        label->setFixedWidth(width);
    }
}

void TableWidget::InsertRow(int insert_postion, int num)
{
    QList<QLayoutItem *> list;
    for(int i = insert_postion; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            QLayoutItem *item;
            item = layout->itemAtPosition(i,j);
            layout->removeItem(item);
            list << item;
        }
    }
    for(int i = insert_postion; i < (insert_postion + num); i++)
    {
        for(int j = 0; j < column; j++)
        {
            QLabel *label = new QLabel(this);
            label->setFrameStyle(QFrame::Box);
            label->setAlignment(Qt::AlignVCenter);
            label->setAutoFillBackground(true);
            layout->addWidget(label,i,j);
        }
    }
    for(int i = insert_postion + num; i < (row + num); i++)
    {
        for(int j = 0; j < column; j++)
        {
            layout->addWidget(list.takeAt(0)->widget(),i,j);
        }
    }
}
