#ifndef DEFEND_H
#define DEFEND_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
//#include <graph.h>

class defend: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int data[10][10];
    int row;
    int column;
    //int previousMove[10][10];

public:
    defend(int** board);

public slots:
    void Tomplay();
    void TomCollision();

};

#endif // DEFEND_H

