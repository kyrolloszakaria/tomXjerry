#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>
#include<QObject>
#include <QGraphicsScene>

class health:  public QGraphicsPixmapItem
{

private:
    int numberOfLives;
    QPixmap* Q;
public:
    health();
    void setNmberOfLives(int x);
    int getNumberOflives();
    void changeImage(int x);
};

#endif // HEALTH_H
