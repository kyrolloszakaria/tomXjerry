#include <QApplication>
#include<QGraphicsView>
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QDir>
#include<QFile>
#include<QTextStream>
#include <QDebug>
#include <QObject>
#include "cheese.h"
#include <jerry.h>
#include "pellet.h"
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

    QGraphicsPixmapItem boardItem[10][10];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if (board[i][j]<0)

                boardItem[i][j].setPixmap(bricksImage);
            else
                boardItem[i][j].setPixmap(grassImage);
            boardItem[i][j].setPos(50+(50*j),50+(50*i));
            Scene.addItem(&boardItem[i][j]);
        }

    }


    Jerry jerry(board);
    pellet cheesepellet(board);
    cheese pellet1(board);
    Scene.addItem(&jerry);
    Scene.addItem(&pellet1);
    Scene.addItem(&cheesepellet);

jerry.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
jerry.setFocus();

    view.show();
    view.setScene(&Scene);


    return a.exec();
}
