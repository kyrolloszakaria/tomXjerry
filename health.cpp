#include "health.h"

health::health()
{

    QPixmap heart("sources/heart3.png");
    heart=heart.scaledToWidth(50);
    heart=heart.scaledToHeight(50);
    setPixmap(heart);
    setPos(50,0);

}




void health::setNmberOfLives(int x)
{
    numberOfLives=x;
}

int health::getNumberOflives()
{
    return numberOfLives;
}
