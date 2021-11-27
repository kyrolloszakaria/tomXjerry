#ifndef HOME_H
#define HOME_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class home : public QObject, public QGraphicsPixmapItem
{
private:
    int row;
    int column;
public:
    home();
};

#endif // HOME_H
