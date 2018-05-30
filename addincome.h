#ifndef ADDINCOME_H
#define ADDINCOME_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRecord>
#include "income.h"
#include "calculator.h"

namespace Ui {
class AddIncome;
}

class AddIncome : public QWidget
{
    Q_OBJECT

public:

    explicit AddIncome(QWidget *parent = 0);

    ~AddIncome();

    void setupEdit(QSqlTableModel* tableModel);

private slots:

    void save();

    void clear();

    void openCalculator();

    void onEqualsClicked(QString);

private:
    Ui::AddIncome *ui;
    Transaction *income; //polymorphism
    Calculator *calculator;
    int tempId;
};

#endif // ADDINCOME_H
