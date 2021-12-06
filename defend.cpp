#include "defend.h"
#include "jerry.h"
#include<QTimer>
#include<QtGlobal>


defend::defend(int** board)
{
        QPixmap tomimage("sources/Tom.png");
        tomimage = tomimage.scaledToWidth(25);
        tomimage = tomimage.scaledToWidth(25);
        setPixmap(tomimage);
        row=8;
        column=8;
        setPos(25+(25*row),25+(25*column));

        for(int i=0;i<20;i++)
        {
            for(int j=0; j<20;j++)
            {
                data[i][j]=board[i][j];

            }
        }

}

void defend::Tomplay()
{
    srand(time(NULL));
    int randamNumber = rand()%4;
   // qDebug() << randamNumber;

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
    //else{exit;}
     setPos(25+(25*column),25+(25*row));
    QTimer::singleShot(130, this, SLOT(Tomplay()));

}

//void defend::TomCollision(Jerry &j){
//    qDebug() << "A\n";
//    QList<QGraphicsItem*> colliding= collidingItems();
//     qDebug() << "B\n";
//    for(int i=0;i<colliding.size();i++){
//        if(typeid((*colliding[i]))== typeid(Jerry)){
//             qDebug() << "C\n";
//            j.takeLife();
//           // qDebug() << "jerry lives: " << j->lives << "\n";
//}
//    }
//}


