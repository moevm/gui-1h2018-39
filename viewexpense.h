#ifndef VIEWEXPENSE_H
#define VIEWEXPENSE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include "expense.h"

namespace Ui {
class ViewExpense;
}

class ViewExpense : public QWidget
{
    Q_OBJECT

public:

    explicit ViewExpense(QWidget *parent = 0);

    ~ViewExpense(); //!< The Destructor of this class deletes the UI.

    void setupTable(); //!< Sets up the table with all Expense records.

signals:
    void editTransactionClicked(QString type, QSqlTableModel* tableModel);

private slots:
    void on_btnDelete_clicked(); //!< Called when the Delete button is clicked.

    void on_btnEdit_clicked(); //!< Called when the Edit button is clicked.

    void on_expense_graphButton_clicked();

private:
    Ui::ViewExpense *ui;
    Transaction *expense;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
};

#endif // VIEWEXPENSE_H
