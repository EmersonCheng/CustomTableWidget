#include "widget.h"
#include "ui_widget.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    int row = 11;
    int column = 5;
    table_widget = new TableWidget(row,column,this);
    table_widget->SetText(0,0,tr("No."));
    table_widget->SetText(0,1,tr("Time"));
    table_widget->SetText(0,2,tr("Sys"));
    table_widget->SetText(0,3,tr("Dia"));
    table_widget->SetText(0,4,tr("Mean"));
    table_widget->SetColumnWidth(0,40);
    for(int i = 1; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            table_widget->SetAlignment(i,j,Qt::AlignCenter);
        table_widget->SetText(i,0,QString::number(i));
    }

//    int row = 14;
//    int column = 6;
//    table_widget = new TableWidget(row,column,this);
//    table_widget->SetText(1,0,tr("HR(bpm)"));
//    table_widget->SetText(2,0,tr("PVCs(/min)"));
//    table_widget->SetText(3,0,tr("ST1(mV)"));
//    table_widget->SetText(4,0,tr("ST2(mV)"));
//    table_widget->SetText(5,0,tr("ST3(mV)"));
//    table_widget->SetText(6,0,tr("RR(BrPM)"));
//    table_widget->SetText(7,0,tr("SpO2(%)"));
//    table_widget->SetText(8,0,tr("PR(bpm)"));
//    table_widget->SetText(9,0,tr("Temp1(Celsius)"));
//    table_widget->SetText(10,0,tr("Temp2(Celsius)"));
//    table_widget->SetText(11,0,tr("Sys(mmHg)"));
//    table_widget->SetText(12,0,tr("Dia(mmHg)"));
//    table_widget->SetText(13,0,tr("Mean(mmHg)"));
//    for(int i = 1; i < row; i++)
//    {
//        for(int j = 1; j < column; j++)
//            table_widget->SetAlignment(i,j,Qt::AlignCenter);
//    }

//    table_widget->SetCellBackgroundColor(10,5,Qt::yellow);
//    table_widget->SetCellBackgroundColor(2,2,QColor(Qt::yellow));
//    table_widget->ResetAllCellsBackgroundColor();

//    table_widget->InsertRow(2,3);
//    table_widget->HideRow(2,true);
//    table_widget->HideRow(3,true);
//    table_widget->HideRow(4,true);
//    table_widget->HideRow(5,true);

    QVBoxLayout *a_layout = new QVBoxLayout(this);
    a_layout->addWidget(table_widget);
}

Widget::~Widget()
{
    delete ui;
}
