#include "cheese.h"

cheese::cheese(int **b)
{
    QPixmap cheese1("sources/meatcartoon_prev_ui.png");
    cheese1=cheese1.scaledToWidth(50);
    cheese1=cheese1.scaledToHeight(50);
    setPixmap(cheese1);
    row=50*5;
    col=50*9;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board[i][j]=b[i][j];
    setPos(row,col);

}

