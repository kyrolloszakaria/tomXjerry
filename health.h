#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsPathItem>
#include<QObject>

class health: public QObject, public QGraphicsPixmapItem
{
private:
    int numberOfLives;
public:
    health(int x);
    void setNmberOfLives(int x);
    int getNumberOflives();
    void changeImage(int x);
};

#endif // HEALTH_H
