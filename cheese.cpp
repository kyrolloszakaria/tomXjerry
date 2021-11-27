#include "cheese.h"

cheese::cheese(int**b)
{
    QPixmap cheese("sources/cheese.png");
    cheese=cheese.scaledToHeight(50);
    cheese=cheese.scaledToWidth(50);
    setPixmap(cheese);
    row=50;
    column= 50;

    setPos(row,column);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board[i][j]=b[i][j];
}

cheese::cheese(int **b, int r,int c){
    QPixmap cheese("sources/cheese.png");
    cheese=cheese.scaledToHeight(50);
    cheese=cheese.scaledToWidth(50);
    setPixmap(cheese);
    row=50*r;
    column=50*c;

    setPos(row,column);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board[i][j]=b[i][j];
}
