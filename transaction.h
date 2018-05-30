#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QModelIndexList>
#include <QStandardItemModel>
#include <QStandardItem>
#include "dbconn.h"

class Transaction
{
public:

    int getId() const;

    void setId(int value);

    QString getDate() const;

    void setDate(const QString &value);

    int getAmount() const;

    void setAmount(int value);

    QString getParty() const;

    void setParty(const QString &value);

    void setCategory(const QString &value);

    QString getCategory() const;

    QString getDescription() const;

    void setDescription(const QString &value);


public slots:

    virtual bool insertTransaction(Transaction* transaction) = 0;

    virtual bool updateTransaction(Transaction* transaction) = 0;

    QSqlTableModel* viewTransaction(QString type);

    QSqlTableModel* getTransaction(QString type, int id);

    void deleteTransaction(QModelIndexList list);

    QStandardItemModel* getCategoriesList(QString type);

private:
    DbConn *dbConn;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
    QStandardItemModel *itemModel;

    int id;
    QString date;
    int amount;
    QString party; //payer | payee
    QString category;
    QString description;
};

#endif // TRANSACTION_H
