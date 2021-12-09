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
    Node *next;
    QString name; // key for hashing.
    QString password;
    int topscore;
};

class accounts
{
    Node *arr[10]; //hash table using seprate chaining for collision handling
    Node *NewNode(QString s, QString p, int sscore); // crete new node
    int hash(QString n); // hashing function

public:
    accounts();
    QString currentaccount; // for the leader board
    int currentscore; // for the leader board
    void AddAccount(QString nme, QString pass, int score);
    void copyTableToFile(); // update the file with the new accounts
    void readFile(); // to read the already created accounts and insert them in the hash table
    void RemoveAccount(QString nme);
    void correctHighScore(QString n, int newscore); // for the leader board
    bool Login(QString n, QString pass); // vaidate credentials
    QString showAccounts(); // for the leader board
    ~accounts();
};

#endif // ACCOUNTS_H
