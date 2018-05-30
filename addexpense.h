#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRecord>
#include "expense.h"
#include "calculator.h"

namespace Ui {
class AddExpense;
}

class AddExpense : public QWidget
{
    Q_OBJECT

public:

    explicit AddExpense(QWidget *parent = 0);

    ~AddExpense();

    void setupEdit(QSqlTableModel *tableModel);

private slots:

    void save();

    void clear();

    void openCalculator();

    void onEqualsClicked(QString answer);

private:
    Ui::AddExpense *ui;
    Transaction *expense; //polymorphism
    Calculator *calculator;
    int tempId;
};

#endif // ADDEXPENSE_H
