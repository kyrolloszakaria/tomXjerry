#ifndef PELLET_H
#define PELLET_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class pellet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
    int row;
    int col;
    int board[10][10];
public:
    pellet(int** b, int r, int c);
};

#endif // PELLET_H
