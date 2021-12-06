#include "pellet.h"

pellet::pellet(int **b)
{
    QPixmap pellet1("sources/ghost.png");
    pellet1=pellet1.scaledToWidth(25);
    pellet1=pellet1.scaledToHeight(25);
    setPixmap(pellet1);
    row=25*9;
    col=25*3;
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            board[i][j]=b[i][j];
    setPos(row,col);

}

