#ifndef PIECHART_H
#define PIECHART_H

#include <QDialog>
#include <QGraphicsScene>

#include "tablemodel.h"
namespace Ui {
class PieChart;
}

class PieChart : public QDialog
{
    Q_OBJECT

public:
    explicit PieChart(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    ~PieChart();
    void selectRowFromGraph(int selectedIndex);
public slots:
    void selectPieceOfPie(QModelIndex index);
    void catchPieSelectionChange();
private:
    Ui::PieChart *ui;
    QGraphicsScene *scene;
    TableModel *model;
};

#endif // PIECHART_H

