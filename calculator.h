#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QDebug>
#include "calculatormodel.h"

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:

    explicit Calculator(QWidget *parent = 0);

    ~Calculator();

protected:

    void changeEvent(QEvent *e);

private slots:

    void onNumberClicked(QString num);


    void on_btnNum0_clicked(); //!< Called when Number 0 Button is clicked.
    void on_btnNum1_clicked(); //!< Called when Number 1 Button is clicked.
    void on_btnNum2_clicked(); //!< Called when Number 2 Button is clicked.
    void on_btnNum3_clicked(); //!< Called when Number 3 Button is clicked.
    void on_btnNum4_clicked(); //!< Called when Number 4 Button is clicked.
    void on_btnNum5_clicked(); //!< Called when Number 5 Button is clicked.
    void on_btnNum6_clicked(); //!< Called when Number 6 Button is clicked.
    void on_btnNum7_clicked(); //!< Called when Number 7 Button is clicked.
    void on_btnNum8_clicked(); //!< Called when Number 8 Button is clicked.
    void on_btnNum9_clicked(); //!< Called when Number 9 Button is clicked.

    void on_btnClear_clicked(); //!< Called when Clear Button is clicked.
    void on_btnPlus_clicked(); //!< Called when Plus Button is clicked.
    void on_btnMinus_clicked(); //!< Called when Minus Button is clicked.
    void on_btnEqual_clicked(); //!< Called when Equals Button is clicked.
    void on_btnMultiply_clicked(); //!< Called when Multiply Button is clicked.
    void on_btnDivide_clicked(); //!< Called when Divide Button is clicked.

signals:
    void numberClicked(QString num);
    void equalsClicked(QString answer);

private:
    Ui::Calculator *ui;
    CalculatorModel *cm;
};

#endif // CALCULATOR_H
