#include "jerry.h"
#include "pellet.h"
#include "cheese.h"



Jerry::Jerry(int** board)
{
    //set image and size
    QPixmap Jerryimage("sources/JerryRight.png");
    //Jerry newjerry(board);
    Jerryimage = Jerryimage.scaledToWidth(50);
    Jerryimage = Jerryimage.scaledToWidth(50);
    setPixmap(Jerryimage);
    lives =3;

    //QPix* ne2= &Jerryimage2;


    //set positon
    row =4;
    column = 5;
    setPos(50+(50*column),50+(50*row));

    for(int i =0; i<10; i++)
        for(int j =0; j<10; j++){
            data[i][j] = board[i][j];
        }
}

void Jerry::takeLife(){
    lives--;
    setPos(50+(50*5),50+(50*4));
}
void Jerry::setjerrydata(int board[10][10]){


}
void Jerry::setImage(bool cheesey, int UDRL ){

    if(cheesey == true) {
        switch(UDRL){

        //case 0:
           // break;
//        case 1:
//            QPixmap Jerryimage("sources/carryingCheseeLeft.png");
//            break;
        case 2:
            x="sources/carryingCheseeRight.png";
            break;
        case 3:
            x="sources/carryingCheseeLeft.png";
            break;
        //default:

        }

    }
    else{
        switch(UDRL){
        case 2:
            x="sources/JerryRight.png";
            break;
        case 3:
            x="sources/JerryLeft.png";
            break;
       // default:

        }
    }
    QPixmap Jerryimage(x);
    Jerryimage = Jerryimage.scaledToWidth(50);
    Jerryimage = Jerryimage.scaledToWidth(50);
    setPixmap(Jerryimage);
}

void Jerry:: keyPressEvent(QKeyEvent* event){
    QList<QGraphicsItem*> colliding= collidingItems();
    int  UDRL;// U0 D1 R2 L3   R true


    for(int i=0;i<colliding.size();i++){
        if(typeid((*colliding[i]))== typeid(cheese)){
            scene()->removeItem(colliding[i]);
            cheesey=true;

        }}

       if(event->key() ==Qt::Key_Up && data[row-1][column] >=0){
           row--;
           UDRL = 0;
           setImage(cheesey,UDRL);

       }
       else if(event->key()==Qt::Key_Down && data[row+1][column] >=0){
           row++;
           UDRL = 1;
           setImage(cheesey,UDRL);

       }
       else if(event->key() == Qt::Key_Right && data[row][column+1]>=0){
           column++;
           UDRL = 2;
           setImage(cheesey,UDRL);

       }
       else if(event->key()==Qt::Key_Left && data[row][column-1]>=0){
           column--;
           UDRL = 3;
           setImage(cheesey,UDRL);

       }

    // cheese is the pellete and pellete is the cheese.

    setPos(50+(50*column),50+(50*row));
}
