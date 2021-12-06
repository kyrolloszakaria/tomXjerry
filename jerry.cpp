#include "jerry.h"


Jerry::Jerry(int** board)
{
    //set image and size
    QPixmap Jerryimage("sources/JerryRight.png");
    //Jerry newjerry(board);
    Jerryimage = Jerryimage.scaledToWidth(25);
    Jerryimage = Jerryimage.scaledToWidth(25);
    setPixmap(Jerryimage);
    //health* H;
    //H = & jerryHealth;

    lives =3;
    cheeseNumber =0;
     //QPix* ne2= &Jerryimage2;


    //set positon
    row =4;
    column = 5;
    setPos(25+(25*column),25+(25*row));

    for(int i =0; i<20; i++)
        for(int j =0; j<20; j++){
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
    Jerryimage = Jerryimage.scaledToWidth(25);
    Jerryimage = Jerryimage.scaledToWidth(25);
    setPixmap(Jerryimage);
}

void Jerry::addhealthtoscence()
{
    scene()->addItem(&jerryHealth);
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
            row = 9;
            column = 10;
            lives--;

            jerryHealth.changeImage(lives);

            if (lives==0)
            {
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setWindowTitle("Game Over!");
                msgBox.setText("Tom Caught Jerry!");
                msgBox.exec();
                scene()->addWidget(&msgBox);
                QApplication::quit();
            }

            qDebug()<< lives ;

//            switch(lives){
//            case 2:
//            {
//                QPixmap heart2image("sources/heart2.png");
//                heart2image=heart2image.scaledToHeight(165);
//                heart2image=heart2image.scaledToWidth(165);
//                heart.setPixmap(heart2image);
//                heart.setPos(25,0);
//               scene()->addItem(&heart);
//               break;
//            }
//            case 1:
//            {
//                QPixmap heartimage("sources/heart1.png");
//                heartimage=heartimage.scaledToHeight(165);
//                heartimage=heartimage.scaledToWidth(165);
//                heart.setPixmap(heartimage);
//                heart.setPos(25,0);
//               scene()->addItem(&heart);
//               break;

//            }
//            case 0:{
//                QPixmap heartimage("sources/heart0.png");
//                heartimage=heartimage.scaledToHeight(165);
//                heartimage=heartimage.scaledToWidth(165);
//                heart.setPixmap(heartimage);
//                heart.setPos(25,0);
//               scene()->addItem(&heart);
//                QMessageBox msgBox;
//                msgBox.setIcon(QMessageBox::Critical);
//                msgBox.setWindowTitle("Game Over!");
//                msgBox.setText("Tom Caught Jerry!");
//                msgBox.exec();
//                scene()->addWidget(&msgBox);
//                QApplication::quit();
//                break;
//            }
//            }

            if (cheesey == true){
                QGraphicsItem* xx = removed.front();
                removed.pop_front();
                scene()->addItem(xx);
                cheesey = false;
                cheeseNumber--;
            }

            setPos(25+(25*column),25+(25*row));
            if (lives <= 0){
                 QMessageBox msgBox;
                 msgBox.setIcon(QMessageBox::Critical);
                 msgBox.setWindowTitle("Game Over!");
                 msgBox.setText("Tom Caught Jerry!");
                 msgBox.exec();
                 scene()->addWidget(&msgBox);
                 QApplication::quit();

            }
            }
        }


        if(typeid((*colliding[i]))==typeid(pellet)){
        ghosted = true;
        scene()->removeItem(colliding[i]);
        QTimer::singleShot(15000,this,SLOT(disableGhosted()));
        }
if (typeid((*colliding[i]))==typeid(home)){
  if (cheesey == true){
      removed.pop_front();
      switch(cheeseNumber){
      case 1:{
          cheesey =false;
          QPixmap cheeseonland1("sources/cheese.png");
          cheeseonland1=cheeseonland1.scaledToHeight(25);
          cheeseonland1=cheeseonland1.scaledToWidth(25);
          land1.setPixmap(cheeseonland1);
          land1.setPos(25+(25*11),25+(25*9));
         scene()->addItem(&land1);
          break;
      }
      case 2:{

          cheesey =false;
          QPixmap cheeseonland2("sources/cheese.png");
          cheeseonland2=cheeseonland2.scaledToHeight(25);
          cheeseonland2=cheeseonland2.scaledToWidth(25);
          land2.setPixmap(cheeseonland2);
          land2.setPos(25+(25*9),25+(25*9));
         scene()->addItem(&land2);
          break;
      }
      case 3:{
          cheesey =false;
          QPixmap cheeseonland3("sources/cheese.png");
          cheeseonland3=cheeseonland3.scaledToHeight(25);
          cheeseonland3=cheeseonland3.scaledToWidth(25);
          land3.setPixmap(cheeseonland3);
          land3.setPos(25+(25*10),25+(25*8));
         scene()->addItem(&land3);
          break;
      }
      case 4:{

          cheesey =false;
          QPixmap cheeseonland4("sources/cheese.png");
          cheeseonland4=cheeseonland4.scaledToHeight(25);
          cheeseonland4=cheeseonland4.scaledToWidth(25);
          land4.setPixmap(cheeseonland4);
          land4.setPos(25+(25*10),25+(25*10));
          scene()->addItem(&land4);
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Information);
          msgBox.setWindowTitle("You Won!!");
          msgBox.setText("Jerry Thanks you!");
         // QPixmap JerryWin("carryingCheese.png");
          //msgBox.setIconPixmap(JerryWin);
          msgBox.exec();

          scene()->addWidget(&msgBox);
          QApplication::quit();

          break;
}
      }
  }
}
}
//qDebug() << row << " " << column;
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
       setPos(25+(25*column),25+(25*row));

}
void Jerry::disableGhosted(){
    ghosted = false;

}



