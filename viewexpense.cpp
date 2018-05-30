#include "viewexpense.h"
#include "ui_viewexpense.h"
#include "piechart.h"

ViewExpense::ViewExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewExpense)
{
    ui->setupUi(this);
    expense = new Expense;
    setupTable();
}

ViewExpense::~ViewExpense()
{
    delete ui;
}

void ViewExpense::on_btnDelete_clicked()
{
    if(ui->tblExpense->selectionModel()->selectedRows().isEmpty())
        return;

    QModelIndexList list = ui->tblExpense->selectionModel()->selectedRows();
    qDebug() << list.count();
    expense->deleteTransaction(list);
    setupTable();
}

void ViewExpense::setupTable()
{
    ui->tblExpense->setModel(expense->viewTransaction("expense"));
    ui->tblExpense->setColumnHidden(0, true);
}

void ViewExpense::on_btnEdit_clicked()
{
    if(ui->tblExpense->selectionModel()->selectedRows().isEmpty())
        return;

    qDebug() << "inside ViewExpense::on_btnEdit_clicked()";
    QModelIndexList selectedRow = ui->tblExpense->selectionModel()->selectedRows();
    QModelIndex index = selectedRow.takeFirst();
    int in = index.data().toInt();
    tableModel = expense->getTransaction("expense", in);
    emit editTransactionClicked("expense", tableModel);
}

void ViewExpense::on_expense_graphButton_clicked()
{
    PieChart pie(this);
    pie.exec();
}
