#include "piechart.h"
#include "ui_piechart.h"
#include "mainwindow.h"
#include <QPainter>


#include "pieceofpie.h"
#include <QGraphicsPathItem>
#include "colors.h"
#include "tablemodel.h"

#include <QDebug>

PieChart::PieChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PieChart)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    model = new TableModel(this);

    int value1;

    QSqlQuery query1;
    query1.prepare("select total(amount) from tblexpense where category = 'Food'");if( !query1.exec() )
        qDebug() << query1.lastError();
      while (query1.next())
          value1 = query1.value(0).toInt();

      int value2;
      QSqlQuery query2;
      query2.prepare("select total(amount) from tblexpense where category = 'Stationery'");if( !query2.exec() )
          qDebug() << query2.lastError();
        while (query2.next())
            value2 = query2.value(0).toInt();

        int value3;
        QSqlQuery query3;
        query3.prepare("select total(amount) from tblexpense where category = 'Rent'");if( !query3.exec() )
            qDebug() << query3.lastError();
          while (query3.next())
              value3 = query3.value(0).toInt();

          int value4;
          QSqlQuery query4;
          query4.prepare("select total(amount) from tblexpense where category = 'Clothing'");if( !query4.exec() )
              qDebug() << query4.lastError();
            while (query4.next())
                value4 = query4.value(0).toInt();

            int value5;
            QSqlQuery query5;
            query5.prepare("select total(amount) from tblexpense where category = 'Utilities'");if( !query5.exec() )
                qDebug() << query5.lastError();
              while (query5.next())
                  value5 = query5.value(0).toInt();

              int value6;
              QSqlQuery query6;
              query6.prepare("select total(amount) from tblexpense where category = 'Transport'");if( !query6.exec() )
                  qDebug() << query6.lastError();
                while (query6.next())
                    value6 = query6.value(0).toInt();

                int value7;
                QSqlQuery query7;
                query7.prepare("select total(amount) from tblexpense where category = 'Education'");if( !query7.exec() )
                    qDebug() << query7.lastError();
                  while (query7.next())
                      value7 = query7.value(0).toInt();

                  int value8;
                  QSqlQuery query8;
                  query8.prepare("select total(amount) from tblexpense where category = 'Entertainment'");if( !query8.exec() )
                      qDebug() << query8.lastError();
                    while (query8.next())
                        value8= query8.value(0).toInt();

                    int value9;
                    QSqlQuery query9;
                    query9.prepare("select total(amount) from tblexpense where category = 'Groceries'");if( !query9.exec() )
                        qDebug() << query9.lastError();
                      while (query9.next())
                          value9 = query9.value(0).toInt();

                      int value10;
                      QSqlQuery query10;
                      query10.prepare("select total(amount) from tblexpense where category = 'Personal Savings'");if( !query10.exec() )
                          qDebug() << query10.lastError();
                        while (query10.next())
                            value10 = query10.value(0).toInt();

                        int value11;
                        QSqlQuery query11;
                        query11.prepare("select total(amount) from tblexpense where category = 'Vehicle'");if( !query11.exec() )
                            qDebug() << query11.lastError();
                          while (query11.next())
                              value11 = query11.value(0).toInt();

                          int value12;
                          QSqlQuery query12;
                          query12.prepare("select total(amount) from tblexpense where category = 'Medical'");if( !query12.exec() )
                              qDebug() << query12.lastError();
                            while (query12.next())
                                value12 = query12.value(0).toInt();

                            int value13;
                            QSqlQuery query13;
                            query13.prepare("select total(amount) from tblexpense where category = 'Tax'");if( !query13.exec() )
                                qDebug() << query13.lastError();
                              while (query13.next())
                                  value13 = query13.value(0).toInt();

                              int value14;
                              QSqlQuery query14;
                              query14.prepare("select total(amount) from tblexpense where category = 'Insurance'");if( !query14.exec() )
                                  qDebug() << query3.lastError();
                                while (query14.next())
                                    value14 = query14.value(0).toInt();

                                int value15;
                                QSqlQuery query15;
                                query15.prepare("select total(amount) from tblexpense where category = 'Others'");if( !query15.exec() )
                                    qDebug() << query15.lastError();
                                  while (query15.next())
                                      value15 = query15.value(0).toInt();


    QList<DataRow*>* dataRows = new QList<DataRow*>();
    dataRows->append(new DataRow("Food",value1));
    dataRows->append(new DataRow("Stationery",value2));
    dataRows->append(new DataRow("Rent",value3));
    dataRows->append(new DataRow("Clothing",value4));
    dataRows->append(new DataRow("Utilities",value5));
    dataRows->append(new DataRow("Transport",value6));
    dataRows->append(new DataRow("Education",value7));
    dataRows->append(new DataRow("Entertainment",value8));
    dataRows->append(new DataRow("Groceries",value9));
    dataRows->append(new DataRow("Personal Savings",value10));
    dataRows->append(new DataRow("Vehicle",value11));
    dataRows->append(new DataRow("Medical",value12));
    dataRows->append(new DataRow("Tax",value13));
    dataRows->append(new DataRow("Insurance",value14));
    dataRows->append(new DataRow("Others",value15));

    model->setList(dataRows);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

 //  connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this, SLOT(selectPieceOfPie(QModelIndex)));
 //  connect(scene,SIGNAL(selectionChanged()),this, SLOT(catchPieSelectionChange()));


    QList<double> values;
    for(DataRow* row: *dataRows)  {
        values.append(row->num);
    }
    int summ = std::accumulate(values.begin(),values.end(),0);

    QList<double> angles;
    for(double val: values)   {
        val= val*1.0;
        double val2= val*360.0;
        double summ2=summ*1.0;
        double val3 = val2/summ2;
        angles.append(val3);
    }


    Pie* pie1 = new Pie(angles);
    scene->addItem(pie1->rectIt);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),pie1, SLOT(selectPiece(QModelIndex)));
    connect(scene,SIGNAL(selectionChanged()),pie1, SLOT(catchSelection()));
    connect(pie1,SIGNAL(selectedPice(int)),ui->tableView,SLOT(selectRow(int)));

    Pie* pie2 = new Pie(angles);
    scene->addItem(pie2->rectIt);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),pie2, SLOT(selectPiece(QModelIndex)));
    connect(scene,SIGNAL(selectionChanged()),pie2, SLOT(catchSelection()));
    connect(pie2,SIGNAL(selectedPice(int)),ui->tableView,SLOT(selectRow(int)));
    pie2->rectIt->setRect(50,50,100,100);
}

void PieChart::paintEvent(QPaintEvent *)
{



}

void PieChart::selectRowFromGraph(int selectedIndex)
{
    int selectedrow =   ui->tableView->model()->index(selectedIndex,0).row();
    ui->tableView->setFocus();
    ui->tableView->selectRow(selectedrow);
}

void PieChart::selectPieceOfPie(QModelIndex index)
{
    int row = index.row();
    QList<QGraphicsItem*> itemList =  scene->items();

    for(QGraphicsItem* it:itemList )
        it->setSelected(false);

    if(row < itemList.length()){
        itemList.at(row)->setSelected(true);
        bool b=itemList.at(row)->isSelected();
        qDebug()<<b;
    }
    scene->update();
}


void PieChart::catchPieSelectionChange()
{
    int selectedIndex;
    QList<QGraphicsItem*> itemList =  scene->items();

    for(int i=0;i<itemList.length();i++)
    {
        if(itemList.at(i)->isSelected())
            selectedIndex = i;
    }
    ui->tableView->selectRow(selectedIndex);
}

PieChart::~PieChart()
{
    delete ui;
}

