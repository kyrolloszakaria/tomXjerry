#include "health.h"

health::health(int x)
{

    switch(x){

    case 1:
     {
        QPixmap heart("sources/heart.png");
        heart=heart.scaledToWidth(50);
        heart=heart.scaledToHeight(50);
        setPixmap(heart);
        setPos(50,0);
        break;
    }
    case 2:
    {
        QPixmap heart("sources/2hearts.png");
        heart=heart.scaledToWidth(50);
        heart=heart.scaledToHeight(50);
        setPixmap(heart);
        setPos(50,0);
        break;
    }
    case 3:
    {
        QPixmap heart("sources/3hearts.png");
        heart=heart.scaledToWidth(50);
        heart=heart.scaledToHeight(50);
        setPixmap(heart);
        setPos(50,0);
        break;

    }
   }


}

void health::setNmberOfLives(int x)
{
    numberOfLives=x;
}

int health::getNumberOflives()
{
    return numberOfLives;
}
