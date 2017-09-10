#ifndef TABLE_WIDGET_H
#define TABLE_WIDGET_H

#include <QFrame>
#include <QGridLayout>
#include <QLabel>

class TableWidget : public QFrame
{
public:
    explicit TableWidget(int row, int column, QWidget *parent = 0);
    void SetText(int row, int column, const QString &text);
    void HideRow(int row, bool invisible);
    void SetCellBackgroundColor(int row, int column, const QColor &color);
    void ResetAllCellsBackgroundColor();
    void SetHorizonAlignment(int row, int column, Qt::Alignment alignment);
    void SetColumnWidth(int column, int width);

protected:
    void paintEvent(QPaintEvent *);

private:
    void InsertRow(int insert_postion, int num);

    QVector< QVector<QString> > data;
    int row;
    int column;
    QVector<bool> row_invisible;
    QColor default_background_color;
    QVector< QVector<QColor> > color_vec;
    QVector< QVector<Qt::Alignment> > alignment_vec;
    int row_height;
    QVector<int> column_width;

    bool is_need_resize;

};

#endif // TABLE_WIDGET_H
