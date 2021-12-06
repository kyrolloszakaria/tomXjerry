#ifndef PELLET_H
#define PELLET_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class pellet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
    int row;
    int col;
    int board[20][20];
public:
    pellet(int** b);
};

#endif // PELLET_H
