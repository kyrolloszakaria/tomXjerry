#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>
#include<QObject>


class health: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
private:
    int numberOfLives;
public:
    health();
    void setNmberOfLives(int x);
    int getNumberOflives();
    void changeImage(int x);
};

#endif // HEALTH_H
