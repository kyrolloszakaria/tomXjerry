#include "home.h"

home::home()
{
    QPixmap homeimage("sources/home.png");
    homeimage = homeimage.scaledToWidth(50);
    homeimage = homeimage.scaledToWidth(50);
    setPixmap(homeimage);
    row=4;
    column=5;
    setPos(50+(50*column),50+(50*row));

}
