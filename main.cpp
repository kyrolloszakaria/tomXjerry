#include <QApplication>
#include<QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QDir>
#include<QFile>
#include<QTextStream>
#include <QDebug>
#include <QObject>
#include "cheese.h"
#include <jerry.h>
#include "pellet.h"
#include "home.h"
#include<defend.h>
#include <QList>
#include<health.h>
#include<QPushButton>
#include<QAbstractButton>
#include "graph.h"
QApplication* aptr;
QGraphicsView* ptrview;
QGraphicsView* ptrview2;
QGraphicsScene* ptrsc;


void insert()
{
    ptrview->hide();
    ptrview2->show();
    ptrview2->setScene(ptrsc);
 //   diff = HARD;

    //aptr->exec();
}

//Graph attributes:
int INF = 9999;
int Graph[230][230];
//Difficulty diff = HARD;
void addEdge(int i, int j, int w)
{
    Graph[i][j] = w;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    aptr = &a;

    QGraphicsView view1;
    ptrview = &view1;
    QGraphicsScene Scene1;
    view1.setFixedSize(600,600);
    view1.setWindowTitle("Tom & Jerry");
    QBrush brush(Qt::black);
    view1.setBackgroundBrush(brush);
    QPixmap MazeGame("sources/MazeGame2.jpg");
    MazeGame=MazeGame.scaledToWidth(500);
    MazeGame=MazeGame.scaledToHeight(500);
    QGraphicsPixmapItem opening;
    opening.setPixmap(MazeGame);
    opening.setPos(300,300);
    Scene1.addItem(&opening);
    QPushButton* ptr;
    ptr = new QPushButton;

    ptr->setText("play");
    ptr->setGeometry(500,500,100,50);
    ptr->setEnabled(true);
    Scene1.addWidget(ptr);
    QObject::connect(ptr,&QPushButton::clicked,insert);

    view1.show();
    view1.setScene(&Scene1);
    QGraphicsView view;
    QGraphicsScene Scene;

    ptrview2 = &view;
    ptrsc = &Scene;

    view.setFixedSize(600,600);
    view.setWindowTitle("Tom & Jerry");
    //QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
    //QDir::setCurrent("E:/Fall 2021/CSCS II/Project");
    int** board;
    board = new int*[20];
    for(int i = 0; i < 20; i++)
       board[i] = new int[20];
    QFile file("sources/board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream (&file);

    QString temp;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            stream>>temp;
            board[i][j]=temp.toInt();

        }

    }
    for(int i = 0 ; i<230; i++){
        for(int j=0; j<230; j++){
            Graph[i][j] = -1;
        }
    }
// creating the graph:
    for (int i = 1; i < 19; i++)
      {
          for (int j = 1; j < 19; j++)
          {
              if (board[i][j] != -1)
              {
                  if (board[i][j - 1] != -1)
                      addEdge(board[i][j], board[i][j - 1], 1);
                  if (board[i + 1][j] != -1)
                      addEdge(board[i][j], board[i + 1][j], 1);
                  if (board[i - 1][j] != -1)
                      addEdge(board[i][j], board[i - 1][j], 1);
                  if (board[i][j + 1] != -1)
                      addEdge(board[i][j], board[i][j + 1], 1);
              }
          }
      }

//    QString debugStr;
//    for(int i=0;i<20;i++)
//    {
//        for(int j=0;j<20;j++)
//        {
//            debugStr += QString::number(Graph[i][j]) + " ";
//        }
//        debugStr += "\n";
//    }
//    qDebug() << debugStr;
    QPixmap bricksImage("sources/Bricks2.jpg");
    bricksImage=bricksImage.scaledToWidth(25);
    bricksImage=bricksImage.scaledToHeight(25);
    QPixmap grassImage("sources/Grass2.jpg");
    grassImage=grassImage.scaledToWidth(25);
    grassImage=grassImage.scaledToHeight(25);
//    QPixmap homeImage("sources/home.png");
//    homeImage=homeImage.scaledToWidth(50);
//    homeImage=homeImage.scaledToHeight(50);
    QPixmap homeLandImage("sources/homeland.png");
    homeLandImage=homeLandImage.scaledToWidth(25);
    homeLandImage=homeLandImage.scaledToHeight(25);



    QGraphicsPixmapItem boardItem[20][20];

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if (board[i][j]<0)

                boardItem[i][j].setPixmap(bricksImage);
          //  else if(board[i][j]==98)
           //     boardItem[i][j].setPixmap(homeImage);
            else if(board[i][j]==99){
                //qDebug() << i << " " << j;
                //boardItem[i][j].setPixmap(homeLandImage);
                boardItem[i][j].setPixmap(grassImage);
}
            else
                boardItem[i][j].setPixmap(grassImage);
            boardItem[i][j].setPos(25+(25*j),25+(25*i));
            Scene.addItem(&boardItem[i][j]);
        }

    }

    //health hearts;
    //Scene.addItem(&hearts);
    Jerry jerry(board);
    cheese cheese1(board,2,2);
    cheese cheese2(board,2,19);
    cheese cheese3(board,19,2);
    cheese cheese4(board,19,19);
    Scene.addItem(&jerry);
    jerry.addhealthtoscence();
    Scene.addItem(&cheese1);
    Scene.addItem(&cheese2);
    Scene.addItem(&cheese3);
    Scene.addItem(&cheese4);
    pellet ghost(board);
    Scene.addItem(&ghost);
    jerry.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    jerry.setFocus();

    home home;
    Scene.addItem(&home);

    defend tom(board);
    Scene.addItem(&tom);
    tom.Tomplay();

    //qDebug() << " here";
   // view.show();
    //view.setScene(&Scene);

    return a.exec();
}
