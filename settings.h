#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QInputDialog>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QList>
#include "income.h"
#include "expense.h"


namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:

    explicit Settings(QWidget *parent = 0);

    ~Settings(); //!< The Destructor of this class deletes the UI

signals:
    void toggleButtons(bool);
    void deleteRecord();

private slots:

    void on_btnIncomeCat_clicked(); //!< Called when Income Category Button is clicked.
    void on_btnExpenseCat_clicked(); //!< Called when Expense Category Button is clicked.

    void on_btnAddCat_clicked(); //!< Called when Add Income Category Button is clicked.
    void on_btnEditCat_clicked(); //!< Called when Add Expense Category Button is clicked.

    void doToggleButtons(bool on);

    void doDeleteRecord();  //!< Called when Delete Category/User Button is clicked.

private:
    Ui::Settings *ui;
    QSqlTableModel *tableModel;
    Transaction *income;
    Transaction *expense;

    void setupViewTable(QString type);


};

#endif // SETTINGS_H
