#include "jerry.h"


Jerry::Jerry(int** board)
{
    //set image and size
    QPixmap Jerryimage("sources/JerryRight.png");
    //Jerry newjerry(board);
    Jerryimage = Jerryimage.scaledToWidth(50);
    Jerryimage = Jerryimage.scaledToWidth(50);
    setPixmap(Jerryimage);
    lives =3;
    cheeseNumber =0;
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



void Jerry::setImage(bool cheesey, int UDRL ){

    if(cheesey == true) {
        switch(UDRL){

        case 0:
           x = "sources/carryingCheseeRight.png";
        case 1:
            x="sources/carryingCheseeLeft.png";
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
        case 0:
            x="sources/JerryRight.png";
            break;
        case 1:
            x="sources/JerryRight.png";
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

        if (cheesey == false){
        if(typeid((*colliding[i]))== typeid(cheese)){
            removed.push_back(colliding[i]);
            scene()->removeItem(colliding[i]);
            cheesey=true;
            cheeseNumber++;

}
        }
        if (ghosted == false){
        if(typeid((*colliding[i]))==typeid(defend)){
            row = 4;
            column = 5;
            lives--;
         //   qDebug() << lives;

            if (cheesey == true){
                QGraphicsItem* xx = removed.front();
                removed.pop_front();
                scene()->addItem(xx);
                cheesey = false;
            }

            setPos(50+(50*column),50+(50*row));
            //if (lives <= 0){}
            }
        }


        if(typeid((*colliding[i]))==typeid(pellet)){
        ghosted = true;
        scene()->removeItem(colliding[i]);
        QTimer::singleShot(15000,this,SLOT(disableGhosted()));
        }
if (typeid((*colliding[i]))==typeid(home)){
  if (cheesey == true){
      switch(cheeseNumber){
      case 1:{
          cheesey =false;
          QPixmap cheeseonland1("sources/cheese.png");
          cheeseonland1=cheeseonland1.scaledToHeight(50);
          cheeseonland1=cheeseonland1.scaledToWidth(50);
          land1.setPixmap(cheeseonland1);
          land1.setPos(50+(50*6),50+(50*4));
         scene()->addItem(&land1);
          break;
      }
      case 2:{

          cheesey =false;
          QPixmap cheeseonland2("sources/cheese.png");
          cheeseonland2=cheeseonland2.scaledToHeight(50);
          cheeseonland2=cheeseonland2.scaledToWidth(50);
          land2.setPixmap(cheeseonland2);
          land2.setPos(50+(50*4),50+(50*4));
         scene()->addItem(&land2);
          break;
      }
      case 3:{
          cheesey =false;
          QPixmap cheeseonland3("sources/cheese.png");
          cheeseonland3=cheeseonland3.scaledToHeight(50);
          cheeseonland3=cheeseonland3.scaledToWidth(50);
          land3.setPixmap(cheeseonland3);
          land3.setPos(50+(50*5),50+(50*3));
         scene()->addItem(&land3);
          break;
      }
      case 4:{

          cheesey =false;
          QPixmap cheeseonland4("sources/cheese.png");
          cheeseonland4=cheeseonland4.scaledToHeight(50);
          cheeseonland4=cheeseonland4.scaledToWidth(50);
          land4.setPixmap(cheeseonland4);
          land4.setPos(50+(50*5),50+(50*5));
         scene()->addItem(&land4);
          break;
}
      }
  }
}
}
qDebug() << row << " " << column;
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
//qDebug() << row << " " << column;
       setPos(50+(50*column),50+(50*row));

}
void Jerry::disableGhosted(){
    ghosted = false;

}



