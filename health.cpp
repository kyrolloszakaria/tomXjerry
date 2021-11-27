#include "health.h"

health::health(int x)
{
    QString newimage;
    switch(x){
    case 1:

        newimage = "sources/heart.png";
        break;

    case 2:

       newimage = "sources/2hearts.png";

        break;

    case 3:

        newimage="sources/3hearts.png";

        break;

     }

    QPixmap heart(newimage);
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
