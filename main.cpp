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
#include<QLineEdit>
#include"accounts.h"
#include "graph.h"

QApplication* aptr;
QGraphicsView* ptrview;
QGraphicsView* ptrview2;
QGraphicsScene* ptrsc;
QLineEdit* Textptr;
QLineEdit* Textptr2;
accounts* ptraccounts;


void insert()
{

    if ( ptraccounts->Login(Textptr->displayText(),Textptr2->displayText()))
    {
    ptraccounts->currentaccount=Textptr->displayText();
    ptrview->hide();
    ptrview2->show();
    ptrview2->setScene(ptrsc);
    }
    else
        Textptr->setText("Error");

}

//Graph attributes:
int INF = 9999;
int Graph[230][230];
//Difficulty diff = HARD;
void addEdge(int i, int j, int w)
{
    Graph[i][j] = w;
}

void login()
{
   ptraccounts->AddAccount(Textptr->displayText(),Textptr2->displayText() , 0);
   Textptr->setText("");
   Textptr2->setText("");

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //aptr = &a;
    accounts Leaderboard;
    ptraccounts = & Leaderboard;

    //Leaderboard.AddAccount("amr","1234",0);
    //Leaderboard.AddAccount("khaled","4567",0);
    QGraphicsView view1;
    ptrview = &view1;
    QGraphicsScene Scene1;
    view1.setFixedSize(728,546);
    view1.setWindowTitle("Tom & Jerry");
    QBrush brush(Qt::black);
    view1.setBackgroundBrush(brush);
    QPixmap MazeGame("sources/Background2.png");
    MazeGame=MazeGame.scaledToWidth(728);
    MazeGame=MazeGame.scaledToHeight(546);
    QGraphicsPixmapItem opening;
    opening.setPixmap(MazeGame);
    opening.setPos(300,300);
    Scene1.addItem(&opening);
    QPushButton* ptr;
    ptr = new QPushButton;
    ptr->setText("play");
    ptr->setGeometry(820,475,100,50);
    ptr->setEnabled(true);
    ptr->setStyleSheet("QPushButton { background-color: transparent }");
    QFont font = ptr->font();
    font.setBold(true);
    font.setPointSize(15);
    ptr->setFont(font);
    Scene1.addWidget(ptr);
    QObject::connect(ptr,&QPushButton::clicked,insert);
    QPushButton*ptr2;
    ptr2 = new QPushButton;
    ptr2->setText("Sign up");
    ptr2->setGeometry(810,545,100,50);
    ptr2->setEnabled(true);
    ptr2->setStyleSheet("QPushButton { background-color: transparent }");
    QFont font2 = ptr->font();
    font2.setBold(true);
    font2.setPointSize(15);
    ptr2->setFont(font);
    Scene1.addWidget(ptr2);
    QLineEdit Text1;
    Textptr = &Text1;
    Text1.setGeometry(455,520,150,30);
    Scene1.addWidget(&Text1);
    QLineEdit Text2;
    Textptr2 = &Text2;
    Text2.setGeometry(455,580,150,30);
    Scene1.addWidget(&Text2);


    QObject::connect(ptr,&QPushButton::clicked,insert);
    QObject::connect(ptr2,&QPushButton::clicked,login);
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
              if (board[i][j] != -1 && board[i][j]!= 107)
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
    Leaderboard.showAccounts();//copies changews to file

    return a.exec();
}
