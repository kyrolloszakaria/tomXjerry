#ifndef JERRY_H
#define JERRY_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>
#include <QList>
#include <QObject>
#include <QTimer>
#include "pellet.h"
#include "cheese.h"
#include "defend.h"
#include "health.h"
#include "home.h"



class Jerry : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

    QGraphicsPixmapItem land1;
    QGraphicsPixmapItem land2;
    QGraphicsPixmapItem land3;
    QGraphicsPixmapItem land4;

    //QGraphicsPixmapItem heart;


    QMessageBox* msgPtr;
    QMessageBox msgBox;
    int data[20][20];
    bool cheesey=false;
    bool ghosted=false;
    QString x = "sources/JerryRight.png";
    int lives;
    int cheeseNumber;
    bool keyPressEnable;
    QList<QGraphicsItem*> removed;

    public:
    QMessageBox* SetTheScores();
    int getJrow();
    int getJcolumn();
    Jerry(int** board);
    health jerryHealth;
    void setImage(bool cheesey, int UDRL);
    friend class defend;
    void addhealthtoscence();
public slots:
    void keyPressEvent(QKeyEvent* event);
    void disableGhosted();
};

#endif // JERRY_H
