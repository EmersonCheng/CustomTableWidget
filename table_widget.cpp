#include "table_widget.h"
#include <QApplication>
#include <QDebug>
#include <QPainter>

TableWidget::TableWidget(int row, int column, QWidget *parent) :
    QFrame(parent),row(row),column(column)
{
    data.resize(row);
    for(int i = 0; i < row; i++)
    {
        data[i].resize(column);
        for(int j = 0; j < column; j++)
            data[i][j].append("");
    }

    row_invisible.resize(row);
    for(int i = 0; i < row; i++)
    {
        row_invisible.fill(false);
    }

    column_width.resize(column);
    for(int i = 0; i < column; i++)
    {
        column_width.fill(40);
    }

    default_background_color = this->palette().color(QPalette::Window);
    color_vec.resize(row);
    for(int i = 0; i < row; i++)
    {
        color_vec[i].resize(column);
        color_vec[i].fill(default_background_color);
    }

    alignment_vec.resize(row);
    for(int i = 0; i < row; i++)
    {
        alignment_vec[i].resize(column);
        alignment_vec[i].fill(Qt::AlignLeft);
    }

    is_need_resize = true;
}

void TableWidget::SetText(int row, int column, const QString &text)
{
    data[row].replace(column, text);
}

void TableWidget::HideRow(int row, bool invisible)
{
    row_invisible.replace(row, invisible);

    is_need_resize = true;
}

void TableWidget::SetCellBackgroundColor(int row, int column, const QColor &color)
{
    color_vec[row].replace(column, color);
}

void TableWidget::ResetAllCellsBackgroundColor()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            color_vec[row].replace(column, default_background_color);
        }
    }
}

void TableWidget::SetHorizonAlignment(int row, int column, Qt::Alignment alignment)
{
   alignment = alignment & ~(Qt::AlignAbsolute | Qt::AlignVertical_Mask);
   alignment_vec[row].replace(column,alignment);
}

void TableWidget::SetColumnWidth(int column, int width)
{
    column_width.replace(column, width);

    is_need_resize = true;
}

void TableWidget::paintEvent(QPaintEvent *)
{
    qDebug() << "paint";

    static QVector< QVector<QRect> > rect_vec;
    static int line_width = 0;
    int actual_row = 0;
    for(int i = 0; i < row; i++)
    {
        if(!row_invisible.at(i))
            actual_row++;
    }
    if(is_need_resize)
    {
        QFontMetrics metriecs(qApp->font());
        row_height = metriecs.height() + 4;
        for(int i = 0; i < row; i++)
        {
            if(row_invisible.at(i))
                continue;

            for(int j = 0; j < column; j++)
            {
                int temp = metriecs.width(data.at(i).at(j)) + 4;
                if(temp > column_width.at(j))
                {
                    column_width.replace(j,temp);
                }
            }
        }
        rect_vec.clear();
        rect_vec.resize(actual_row);
        for(int m = 0; m < actual_row; m++)
        {
            rect_vec[m].resize(column);
            for(int n = 0; n < column; n++)
            {
                int left = 0;
                for(int j = n-1; j >= 0; j--)
                    left += column_width.at(j);
                rect_vec[m][n].setLeft(left);
                rect_vec[m][n].setTop(row_height * m);
                rect_vec[m][n].setWidth(column_width.at(n));
                rect_vec[m][n].setHeight(row_height);

            }
        }
        line_width = 0;
        for(int i = 0; i < column; i++)
            line_width += column_width.at(i);

        is_need_resize = false;
    }

    QPainter painter(this);


    for(int i = 0; i < actual_row + 1; i++)
    {
        // draw horizontal lines
        painter.drawLine(0,i * row_height,line_width,i * row_height);
    }

    int current_column_x = 0;
    for(int i = 0; i < column + 1; i++)
    {
        // draw vertical lines
        painter.drawLine(current_column_x,0,current_column_x,actual_row * row_height);
        if(i == column)
            continue;
        current_column_x += column_width.at(i);
    }

    //fillRect
    int m = 0;
    for(int i = 0; i < row; i++)
    {
        if(row_invisible.at(i))
            continue;

        for(int n = 0; n < column; n++)
        {
            QRect temp = rect_vec.at(m).at(n);
            temp.setLeft(temp.left()+1);
            temp.setTop(temp.top()+1);
            painter.fillRect(temp,color_vec.at(i).at(n));
        }
        m++;
    }

    //draw text
    m = 0;
    for(int i = 0; i < row; i++)
    {
        if(row_invisible.at(i))
            continue;

        for(int n = 0; n < column; n++)
        {
            QRect temp = rect_vec.at(m).at(n);
            temp.setLeft(temp.left()+2);
            temp.setTop(temp.top()+2);
            temp.setRight(temp.right()-2);
            temp.setBottom(temp.bottom()-2);
            painter.drawText(temp,alignment_vec.at(i).at(n) | Qt::AlignBottom,data.at(i).at(n));
        }
        m++;
    }

}

void TableWidget::InsertRow(int insert_postion, int num)
{
    row += num;

    QVector<QString> insert_row(column);
    data.insert(insert_postion,num,insert_row);

    row_invisible.insert(insert_postion,num,false);

    QVector<QColor> insert_row_color(column);
    color_vec.insert(insert_postion,num,insert_row_color);

    QVector<Qt::Alignment> insert_row_alignment(column);
    color_vec.insert(insert_postion,num,insert_row_alignment);

    is_need_resize = true;
}
