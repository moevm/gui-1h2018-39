#ifndef VIEWINCOME_H
#define VIEWINCOME_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include "income.h"

namespace Ui {
class ViewIncome;
}

class ViewIncome : public QWidget
{
    Q_OBJECT

public:

    explicit ViewIncome(QWidget *parent = 0);

    ~ViewIncome(); //!< The Destructor of this class deletes the UI.

void setupTable(); //!< Sets up the table with all Income records.

signals:
    void editTransactionClicked(QString type, QSqlTableModel* tableModel);

private slots:
    void on_btnDelete_clicked(); //!< Called when the Delete button is clicked.

    void on_btnEdit_clicked(); //!< Called when the Edit button is clicked.

private:
    Ui::ViewIncome *ui;
    Transaction *income;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
};

#endif // VIEWINCOME_H
