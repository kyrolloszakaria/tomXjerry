#include "defend.h"
#include<QTimer>
#include<QtGlobal>

defend::defend(int** board)
{
        QPixmap tomimage("sources/Tom.png");
        tomimage = tomimage.scaledToWidth(50);
        tomimage = tomimage.scaledToWidth(50);
        setPixmap(tomimage);
        row=8;
        column=8;
        setPos(50+(50*row),50+(50*column));

        for(int i=0;i<10;i++)
        {
            for(int j=0; j<10;j++)
            {
                data[i][j]=board[i][j];

            }
        }

}

void defend::Tomplay()
{
    srand(time(NULL));
    int randamNumber = rand()%4;
    qDebug() << randamNumber;

    if ((randamNumber == 0 )&& (data[row+1][column]!=-1))//down
    {
        row++;
    }
    else if ((randamNumber == 1) && (data[row-1][column]!=-1)) //up
    {
      row--;
    }
    else if ((randamNumber == 2 )&& (data[row][column-1]!= -1))//right
    {
 column--;

    } else if ((randamNumber == 3) && (data[row][column+1]!= -1))//left
    {
     column++;
    }
     setPos(50+(50*column),50+(50*row));
    QTimer::singleShot(350, this, SLOT(Tomplay()));

}


