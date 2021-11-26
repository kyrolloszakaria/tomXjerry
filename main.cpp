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

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QGraphicsView view;
    QGraphicsScene Scene;

    view.setFixedSize(600,600);
    view.setWindowTitle("Tom & Jerry");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
    //QDir::setCurrent("E:/Fall 2021/CSCS II/Project");

    int** board;
    board = new int*[10];
    for(int i = 0; i < 10; i++)
       board[i] = new int[10];
    QFile file("sources/board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream (&file);

    QString temp;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            stream>>temp;
            board[i][j]=temp.toInt();

        }

    }

//    QString debugStr;
//    for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<10;j++)
//        {
//            debugStr += QString::number(board[i][j]) + " ";
//        }
//        debugStr += "\n";
//    }
//    qDebug() << debugStr;
    QPixmap bricksImage("sources/Bricks.png");
    bricksImage=bricksImage.scaledToWidth(50);
    bricksImage=bricksImage.scaledToHeight(50);
    QPixmap grassImage("sources/Grass.png");
    grassImage=grassImage.scaledToWidth(50);
    grassImage=grassImage.scaledToHeight(50);
//    QPixmap homeImage("sources/home.png");
//    homeImage=homeImage.scaledToWidth(50);
//    homeImage=homeImage.scaledToHeight(50);
    QPixmap homeLandImage("sources/homeland.png");
    homeLandImage=homeLandImage.scaledToWidth(50);
    homeLandImage=homeLandImage.scaledToHeight(50);



    QGraphicsPixmapItem boardItem[10][10];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if (board[i][j]<0)

                boardItem[i][j].setPixmap(bricksImage);
          //  else if(board[i][j]==98)
           //     boardItem[i][j].setPixmap(homeImage);
            else if(board[i][j]==99)
                boardItem[i][j].setPixmap(homeLandImage);

            else
                boardItem[i][j].setPixmap(grassImage);
            boardItem[i][j].setPos(50+(50*j),50+(50*i));
            Scene.addItem(&boardItem[i][j]);
        }

    }

//   health hearts(3);
//   Scene.addItem(&hearts);
    Jerry jerry(board);
    cheese cheese1(board,2,2);
    cheese cheese2(board,2,9);
    cheese cheese3(board,9,2);
    cheese cheese4(board,9,9);
    Scene.addItem(&jerry);
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



view.show();
view.setScene(&Scene);


    return a.exec();
}
