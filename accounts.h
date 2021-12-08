#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include "QString"
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
struct Node
{
public:
    Node *next; // another idea is use Breadth first search for something
    QString name;
    QString password; // we can take this because it is unique.
    int topscore;
};

class accounts
{
    Node *arr[10];

    Node *NewNode(QString s, QString p, int sscore);
    int hash(QString n);

public:
    accounts();
    QString currentaccount;
    int currentscore;
    void AddAccount(QString nme, QString pass, int score);
    void copyTableToFile();
    void readFile();
    void RemoveAccount(QString nme);
    void correctHighScore(QString n, int newscore);
    bool Login(QString n, QString pass);
    void showAccounts();
    ~accounts();
};

#endif // ACCOUNTS_H
