#include "health.h"

health::health()
{

<<<<<<< HEAD
    QPixmap heart("sources/heart3.png");
=======


    QPixmap heart("sources/3hearts.png");
>>>>>>> 6f109116665c4b6cc25a64a7ebe813a672b754dd
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
