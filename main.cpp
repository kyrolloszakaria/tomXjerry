#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include <QCheckBox>
#include <QList>
#include <QPushButton>
#include <QAbstractButton>
#include <QLineEdit>
#include<QMessageBox>
#include <QLabel>
#include "health.h"
#include "accounts.h"
#include "graph.h"
#include "cheese.h"
#include "jerry.h"
#include "pellet.h"
#include "home.h"
#include "defend.h"

// Login pointers
QGraphicsView *ptrview; // login view
QGraphicsView *ptrview2; // game view
QGraphicsScene *ptrsc; // game scene
QGraphicsScene *ptrleader; //Leader scene
QLineEdit *Textptr; //user name :: login
QLineEdit *Textptr2; // user name :: password
QLabel* labelLB; // Leadeboard label
accounts *ptraccounts;

// First Scene slots:

bool freezing = true;
void showLeaderBoard()
{
ptrview2->setScene(ptrleader);
labelLB->setText(ptraccounts->showAccounts());
}
void insert() // play button
{
    //                     username                password
    if (ptraccounts->Login(Textptr->displayText(), Textptr2->displayText()))
    {
        ptraccounts->currentaccount = Textptr->displayText();
        ptrview->hide();
        ptrview2->show();
        ptrview2->setScene(ptrsc);
        freezing = false; // tom starts to move
        // tomptr->Tomplay();
    }
    else
        Textptr->setText("Error");
        Textptr2->setText("Error");
}


void login() // sign-up
{
    ptraccounts->AddAccount(Textptr->displayText(), Textptr2->displayText(), 0);
    Textptr->setText("");
    Textptr2->setText("");
}

// default difficulty:
int difficulty = 900;
void easy()
{
    difficulty = 1500;
}
void Normal()
{
    difficulty = 900;
}
void hard()
{
    difficulty = 300;
}

// making Graph:
int INF = 9999;
int Graph[230][230];

void addEdge(int i, int j, int w)
{
    Graph[i][j] = w;
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    // aptr = &a;
    accounts Leaderboard;
    ptraccounts = &Leaderboard;


    QGraphicsView view1; // login view
    ptrview = &view1;

    // adjusting login scene:
    QGraphicsScene Scene1; // login scene
    view1.setFixedSize(728, 546);
    view1.setWindowTitle("Tom & Jerry");
    QBrush brush(Qt::black);
    view1.setBackgroundBrush(brush);

    //adjsting the leaderBoard

    QGraphicsScene Sceneleader; // leaderBoard scene
     ptrleader= &Sceneleader;


     // leaderboard background image
     QPixmap LB("sources/LeaderBoard.jpg");
     LB = LB.scaledToWidth(650);
     LB = LB.scaledToHeight(650);
     QGraphicsPixmapItem LBitem;
     LBitem.setPixmap(LB);
     LBitem.setPos(300, 300);
     Sceneleader.addItem(&LBitem);

     // QlineEdit

     QLabel labelLeaderBoard;
     labelLB = &labelLeaderBoard;
     labelLeaderBoard.setGeometry(600, 500, 300, 150);
     labelLB->setStyleSheet("QLabel { background-color: transparent }");
     QFont font6 = labelLB->font();
     font6.setBold(true);
     font6.setPointSize(15);
     labelLB->setFont(font6);
     Sceneleader.addWidget(&labelLeaderBoard);


    // sign-up and log-in background image
    QPixmap MazeGame("sources/Background2.png");
    MazeGame = MazeGame.scaledToWidth(728);
    MazeGame = MazeGame.scaledToHeight(546);
    QGraphicsPixmapItem opening;
    opening.setPixmap(MazeGame);
    opening.setPos(300, 300);
    Scene1.addItem(&opening);

    // adjust push buttons: (play)
    QPushButton *ptr; // play button
    ptr = new QPushButton;
    ptr->setText("play");
    ptr->setGeometry(820, 475, 100, 50);
    ptr->setEnabled(true);
    ptr->setStyleSheet("QPushButton { background-color: transparent }");
    QFont font = ptr->font();
    font.setBold(true);
    font.setPointSize(15);
    ptr->setFont(font);
    Scene1.addWidget(ptr);


    // adjust push buttons: (sign up)
    QPushButton *ptr2;
    ptr2 = new QPushButton;
    ptr2->setText("Sign up");
    ptr2->setGeometry(810, 545, 100, 50);
    ptr2->setEnabled(true);
    ptr2->setStyleSheet("QPushButton { background-color: transparent }");
    QFont font2 = ptr->font();
    font2.setBold(true);
    font2.setPointSize(15);
    ptr2->setFont(font);
    Scene1.addWidget(ptr2);

    // user name line edit:
    QLineEdit Text1;
    Textptr = &Text1;
    Text1.setGeometry(455, 520, 150, 30);
    Scene1.addWidget(&Text1);
    QLineEdit Text2;

    // password line edit:
    Textptr2 = &Text2;
    Text2.setGeometry(455, 580, 150, 30);
    Scene1.addWidget(&Text2);

    // Check boxes:

    // CheckBox 1: easy
    QCheckBox *ptr3;
    ptr3 = new QCheckBox;
    ptr3->setText("Easy");
    ptr3->setGeometry(350, 650, 75, 75); // easy
    ptr3->setStyleSheet("QCheckBox { background-color: transparent }");
    QFont font3 = ptr3->font();
    font3.setBold(true);
    font3.setPointSize(10);
    ptr3->setFont(font3);
    Scene1.addWidget(ptr3);

    // CheckBox 2
    QCheckBox *ptr4;
    ptr4 = new QCheckBox;
    ptr4->setText("Normal");
    ptr4->setGeometry(425, 650, 75, 75); // Normal
    ptr4->setStyleSheet("QCheckBox { background-color: transparent }");
    QFont font4 = ptr4->font();
    font4.setBold(true);
    font4.setPointSize(10);
    ptr4->setFont(font4);
    Scene1.addWidget(ptr4);

    // CheckBox 3
    QCheckBox *ptr5;
    ptr5 = new QCheckBox;
    ptr5->setText("Hard");
    ptr5->setGeometry(500, 650, 75, 75); // Hard
    ptr5->setStyleSheet("QCheckBox { background-color: transparent }");
    QFont font5 = ptr5->font();
    font5.setBold(true);
    font5.setPointSize(10);
    ptr5->setFont(font5);
    Scene1.addWidget(ptr5);

    // create signal(buttonPtr,event, slot name)
    QObject::connect(ptr, &QPushButton::clicked,insert);
    QObject::connect(ptr2, &QPushButton::clicked, login);
    QObject::connect(ptr3, &QCheckBox::clicked, easy);
    QObject::connect(ptr3, &QCheckBox::clicked, Normal);
    QObject::connect(ptr5, &QCheckBox::clicked, hard);


    view1.show(); // login view
    view1.setScene(&Scene1);
    QGraphicsView view; // game view
    QGraphicsScene Scene; // game scene

    ptrview2 = &view;
    ptrsc = &Scene;

    // adjust game view:
    view.setFixedSize(600, 600);
    view.setWindowTitle("Tom & Jerry");
    view.setBackgroundBrush(brush); // same brush for both scenes

    //creating the board:

    int **board;
    board = new int *[20];
    for (int i = 0; i < 20; i++)
        board[i] = new int[20];
    QFile file("sources/board.txt");
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    QString temp;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            stream >> temp;
            board[i][j] = temp.toInt();
        }
    }
  // initialize the matrix with -1
    for (int i = 0; i < 230; i++)
    {
        for (int j = 0; j < 230; j++)
        {
            Graph[i][j] = -1;
        }
    }

    // creating the graph (Adjacency Matrix)
    for (int i = 1; i < 19; i++)
    {
        for (int j = 1; j < 19; j++)
        {
            if (board[i][j] != -1 && board[i][j] != 107) // 107: home vertex
            {
                // checks for the four neighbours:
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

    // creating game graphics:
    QPixmap bricksImage("sources/Bricks2.jpg");
    bricksImage = bricksImage.scaledToWidth(25);
    bricksImage = bricksImage.scaledToHeight(25);

    QPixmap grassImage("sources/Grass2.jpg");
    grassImage = grassImage.scaledToWidth(25);
    grassImage = grassImage.scaledToHeight(25);

    QPixmap homeLandImage("sources/homeland.png");
    homeLandImage = homeLandImage.scaledToWidth(25);
    homeLandImage = homeLandImage.scaledToHeight(25);

    QGraphicsPixmapItem boardItem[20][20];

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (board[i][j] < 0)

                boardItem[i][j].setPixmap(bricksImage);

            else if (board[i][j] == 99)
            {
                // qDebug() << i << " " << j;
                // boardItem[i][j].setPixmap(homeLandImage);
                boardItem[i][j].setPixmap(grassImage);
            }
            else
                boardItem[i][j].setPixmap(grassImage);
            boardItem[i][j].setPos(25 + (25 * j), 25 + (25 * i));
            Scene.addItem(&boardItem[i][j]);
        }
    }


    Jerry jerry(board);
    Scene.addItem(&jerry);

    cheese cheese1(board, 2, 2);
    cheese cheese2(board, 2, 19);
    cheese cheese3(board, 19, 2);
    cheese cheese4(board, 19, 19);
    Scene.addItem(&cheese1);
    Scene.addItem(&cheese2);
    Scene.addItem(&cheese3);
    Scene.addItem(&cheese4);

    jerry.addhealthtoscence(); // Compostion Relationship.
// function to add health object to scene.
// health object is created in Jerry constructor with numberOfLives =3;
// health object has numberOfLives = 3;
// health class has changeImage(int x) function that change hearts according to number of lives.



    pellet ghost(board, 3, 9);
    pellet ghost2(board, 7, 4);
    Scene.addItem(&ghost);
    Scene.addItem(&ghost2);

    // set focus to jerry.
    jerry.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    jerry.setFocus();
    QMessageBox* ptr6 =jerry.SetTheScores();
    QObject::connect( ptr6,&QMessageBox::accepted,showLeaderBoard);
    home home;
    Scene.addItem(&home);

    defend tom(board);
    Scene.addItem(&tom);

    tom.Tomplay();
    Leaderboard.showAccounts(); // update files with new accounts

    return a.exec();
}
