#include "jerry.h"
#include "pellet.h"
#include "cheese.h"

Jerry::Jerry(int** board)
{
    //set image and size
    QPixmap Jerryimage("sources/Jerry.png");
   // QPixmap Jerryimage2("sources/Jerry.png");
    //Jerry newjerry(board);
    Jerryimage = Jerryimage.scaledToWidth(50);
    Jerryimage = Jerryimage.scaledToWidth(50);
    setPixmap(Jerryimage);


    //QPix* ne2= &Jerryimage2;


    //set positon
    row =1;
    column = 1;
    setPos(50+(50*column),50+(50*row));

    for(int i =0; i<10; i++)
        for(int j =0; j<10; j++){
            data[i][j] = board[i][j];
        }
}

void Jerry::setjerrydata(int board[10][10]){


}

void Jerry:: keyPressEvent(QKeyEvent* event){
    if(event->key() ==Qt::Key_Up && data[row-1][column] >=0){
           row--;

       }
       else if(event->key()==Qt::Key_Down && data[row+1][column] >=0){
           row++;

       }
       else if(event->key() == Qt::Key_Right && data[row][column+1]>=0){
           column++;

       }
       else if(event->key()==Qt::Key_Left && data[row][column-1]>=0){
           column--;

       }
    QList<QGraphicsItem*> colliding= collidingItems();

    for(int i=0;i<colliding.size();i++){

        if(typeid((*colliding[i]))== typeid(pellet)){
            scene()->removeItem(colliding[i]);
            //scene()->removeItem(this);
            QPixmap Jerryimage("sources/jerryrunning2.png");

            Jerryimage = Jerryimage.scaledToWidth(50);
            Jerryimage = Jerryimage.scaledToWidth(50);
            setPixmap(Jerryimage);

             // i am trying to make the jerry with cheese icon

        }
        else if(typeid(*colliding[i])==typeid(cheese)){
            scene()->removeItem(colliding[i]);


        }
    }
    setPos(50+(50*column),50+(50*row));
}
