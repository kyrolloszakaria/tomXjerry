#ifndef DEFEND_H
#define DEFEND_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>
#include "graph.h"

class defend: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
   int data[20][20];
    int row;
    int column;
    //int previousMove[10][10];
    static const int N =230;

public:
QVector<QVector<int>> Dijkstra(int Graph[][N], int startVertex);


    defend(int** board);
    //friend class Jerry;
public slots:
void Tomplay();
  //  void TomCollision(Jerry &j);

};

#endif // DEFEND_H
