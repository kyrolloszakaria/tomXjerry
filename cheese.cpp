#include "cheese.h"

cheese::cheese(int**b)
{
    QPixmap cheese("sources/cheese.png");
    cheese=cheese.scaledToHeight(50);
    cheese=cheese.scaledToWidth(50);
    setPixmap(cheese);
    row=50*6;
    column= 50*6;

    setPos(row,column);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board[i][j]=b[i][j];




}
