#include "home.h"

home::home()
{
    QPixmap homeimage("sources/CartoonHouse.png");
    homeimage = homeimage.scaledToWidth(25);
    homeimage = homeimage.scaledToWidth(25);
    setPixmap(homeimage);
    row=9;
    column=10;
    setPos(25+(25*column),25+(25*row));

}
