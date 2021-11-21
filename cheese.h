#ifndef CHEESE_H
#define CHEESE_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class cheese:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
    int row;
    int col;
    int board[10][10];
public:
    cheese(int** b);
};

#endif // CHEESE_H
