#ifndef DEFEND_H
#define DEFEND_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "jerry.h"
//#include <graph.h>

class defend: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int data[10][10];
    int row;
    int column;
    Jerry* jerryhere;
    //int previousMove[10][10];

public:

    defend(int** board,Jerry* j);
    //friend class Jerry;
public slots:
    void Tomplay();
    void TomCollision(Jerry* j);

};

#endif // DEFEND_H

