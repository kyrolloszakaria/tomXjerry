#include "cheese.h"

cheese::cheese(int **b)
{
    QPixmap cheese("sources/cheese.png");
    cheese = cheese.scaledToHeight(25);
    cheese = cheese.scaledToWidth(25);
    setPixmap(cheese);
    row = 25;
    column = 25;

    setPos(row, column);
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            board[i][j] = b[i][j];
}

cheese::cheese(int **b, int r, int c)
{
    QPixmap cheese("sources/cheese.png");
    cheese = cheese.scaledToHeight(25);
    cheese = cheese.scaledToWidth(25);
    setPixmap(cheese);
    row = 25 * r;
    column = 25 * c;

    setPos(row, column);
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            board[i][j] = b[i][j];
}
