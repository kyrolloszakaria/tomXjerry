#ifndef PELLET_H
#define PELLET_H
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>


class pellet:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
int board[10][10];
int row;
int column;
public:
    pellet(int**b);
};

#endif // PELLET_H
