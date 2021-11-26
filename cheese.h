#ifndef CHEESE_H
#define CHEESE_H
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>


class cheese:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
int board[10][10];
int row;
int column;
public:
    cheese(int**b);
    cheese(int**b,int row, int col);
};

#endif // CHEESE_H
