#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T07:55:38
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFinance
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addincome.cpp \
    addexpense.cpp \
    dbconn.cpp \
    viewincome.cpp \
    viewexpense.cpp \
    income.cpp \
    expense.cpp \
    transaction.cpp \
    calculator.cpp \
    calculatormodel.cpp \
    settings.cpp \
    colors.cpp \
    pieceofpie.cpp \
    piechart.cpp \
    tablemodel.cpp

HEADERS  += mainwindow.h \
    addincome.h \
    addexpense.h \
    dbconn.h \
    viewincome.h \
    viewexpense.h \
    income.h \
    expense.h \
    transaction.h \
    calculator.h \
    calculatormodel.h \
    settings.h \
    colors.h \
    pieceofpie.h \
    piechart.h \
    tablemodel.h

FORMS    += mainwindow.ui \
    addincome.ui \
    addexpense.ui \
    viewincome.ui \
    viewexpense.ui \
    calculator.ui \
    settings.ui \
    piechart.ui
