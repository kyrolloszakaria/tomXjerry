#include "health.h"
#include <QDebug>
health::health()
{

    numberOfLives = 3;
    Q = new QPixmap ("sources/heart3.png");
    //scene()->addItem(&jerryHealth);
    *Q = Q->scaledToHeight(25);
    *Q = Q->scaledToWidth(75);
    setPixmap(*Q);
    setPos(25,0);

}

void health::setNmberOfLives(int x)
{
    numberOfLives=x;

}

int health::getNumberOflives()
{
    return numberOfLives;
}

void health::changeImage(int x)
{
    numberOfLives = x;
    QString y;
    switch(numberOfLives){
    case 3:
    {

    y= "sources/heart3.png";

        break;

    }
    case 2:
    {
        delete  Q;
        Q = new QPixmap ("sources/heart2.png");
        *Q = Q->scaledToHeight(25);
        *Q = Q->scaledToWidth(75);
        setPixmap(*Q);
        setPos(25,0);

       break;
    }
    case 1:
    {
        delete  Q;
        Q = new QPixmap ("sources/heart1.png");
        *Q = Q->scaledToHeight(25);
        *Q = Q->scaledToWidth(75);
        setPixmap(*Q);
        setPos(25,0);
        break;
    }
    case 0:
    {
        delete  Q;
        Q = new QPixmap ("sources/heart0.png");
        *Q = Q->scaledToHeight(25);
        *Q = Q->scaledToWidth(75);
        setPixmap(*Q);
        setPos(25,0);
        break;
    }

    }

}

