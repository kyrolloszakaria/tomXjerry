#include "pellet.h"

pellet::pellet(int **b, int r, int c)
{
    QPixmap pellet1("sources/ghost.png");
    pellet1=pellet1.scaledToWidth(50);
    pellet1=pellet1.scaledToHeight(50);
    setPixmap(pellet1);
    row=50*c;
    col=50*r;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board[i][j]=b[i][j];
    setPos(row,col);

}

