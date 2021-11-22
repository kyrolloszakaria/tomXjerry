#ifndef JERRY_H
#define JERRY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
class Jerry : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
    int data[10][10];
    int row;
    int column;
    bool cheesey=false;
    QString x = "sources/JerryRight.png";
public:
    Jerry(int** board);
    void setjerrydata(int board[10][10]);
//public slots:
    void setImage(bool cheesey, int UDRL);
    void keyPressEvent(QKeyEvent* event);
};

#endif // JERRY_H
