#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "dbconn.h"
#include "addincome.h"
#include "addexpense.h"
#include "viewincome.h"
#include "viewexpense.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow(); //!< The Destructor of this class deletes the UI and closes the Database connection.

signals:
    void on_actionLog_out_triggered();

private slots:

    void onAddIncome(); //!< Opens a new tab and sets up the UI for New Income

    void onAddExpense(); //!< Opens a new tab and sets up the UI for New Expense

    void onViewIncome(); //!< Opens a new tab and sets up the UI for View Income

    void onViewExpense(); //!< Opens a new tab and sets up the UI for View Expense

    void closeTab(int index);

    bool tabExists(QString label);

    void showSummary(int index);

    void showSettings(); //!< Opens the Settings tab if not already open.

    void editTransaction(QString type, QSqlTableModel* tableModel);

    void quitApp(); //!< Called when Quit Applicaion is triggered.

private:
    Ui::MainWindow *ui;
    DbConn *dbConn;

    AddIncome *addIncome;
    AddExpense *addExpense;
    ViewIncome *viewIncome;
    ViewExpense *viewExpense;
    Settings *settings;

};

#endif // MAINWINDOW_H
