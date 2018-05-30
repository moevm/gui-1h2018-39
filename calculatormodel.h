#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QDebug>
#include <QSqlQuery>

class CalculatorModel
{
public:

    void firstNumEntered(int n);

    void secondNumEntered(int n);

    void additionMode(); //!< Sets operation mode to Addition
    void subtractionMode(); //!< Sets operation mode to Subtraction
    void multiplicationMode(); //!< Sets operation mode to Multiplication
    void divisionMode(); //!< Sets operation mode to Division

    int calculate();

    void clear(); //!< Clears the entered fields.

private:
    int firstNumber, secondNumber = 0;
    bool addition;
    bool subtraction;
    bool multiplication;
    bool division;
    int result = 0;

};

#endif // CALCULATORMODEL_H
