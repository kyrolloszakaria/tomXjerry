#include "defend.h"
#include "jerry.h"
//#include "graph.h"
#include<QTimer>
#include<QtGlobal>


defend::defend(int** board)
{
        QPixmap tomimage("sources/Tom.png");
        tomimage = tomimage.scaledToWidth(25);
        tomimage = tomimage.scaledToWidth(25);
        setPixmap(tomimage);
        row=8;
        column=8;
        setPos(25+(25*row),25+(25*column));

        for(int i=0;i<20;i++)
        {
            for(int j=0; j<20;j++)
            {
                data[i][j]=board[i][j];

            }
        }

}
QVector<QVector<int>> defend:: Dijkstra(int Graph[][N], int startVertex)
{

    //passed as parametar.
   //startVertex = data[row][column];
    bool done[N];
        int previous[N];
        int cost[N];

        int temp[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (Graph[i][j] == -1)
                    temp[i][j] = INF;
                else
                    temp[i][j] = Graph[i][j];

        // 1st Row:
        for (int i = 0; i < N; i++)
        {
            if (i == startVertex)
            {
                done[i] = true;
                previous[i] = -1;
                cost[i] = 0;
            }
            else
            {
                done[i] = false;
                previous[i] = startVertex;
                cost[i] = temp[startVertex][i];
            }
        }

        int count = 1;
        while (count < N)
        {
            // Which vertex is done?
            // Vertex with the lowest cost.
            int minimum = INF;
            int currentVertex;
            for (int i = 0; i < N; i++)
            {
                if (done[i] == false && cost[i] < minimum)
                {
                    minimum = cost[i];
                    currentVertex = i;
                }
            }
            done[currentVertex] = true;
            //
            for (int i = 0; i < N; i++)
            {
                if (done[i] == false)
                {
                    int value = cost[currentVertex] + temp[currentVertex][i];
                    if (value < cost[i])
                    {
                        cost[i] = value;
                        previous[i] = currentVertex;
                    }
                }
            }
            count++;
        }
        QVector<QVector<int>> paths;
        paths.resize(N);
        int j;
        for (int i = 0; i < N; i++)
        {
            paths[i].push_back(i);
            j = i;
            while (j != startVertex)
            {
                paths[i].insert(paths[i].begin(), previous[j]);
                j = previous[j];
            }
        }
//        for (int i = 0; i < paths[96].size(); i++)
//           { qDebug() << paths[96][i] << " ";}
        return paths;
}


void defend::Tomplay()
{
    srand(time(NULL));
    qDebug() << "run";
    //to make sure it reads a correct board.

//    for(int i =0; i< 20; i++){
//        for (int j=0; j<20; j++){
//            qDebug() << data[i][j] << " ";
//        }
//      qDebug() << " ";
//    }
QVector<QVector<int>> results = Dijkstra(Graph,data[row][column]);
//qDebug() << data[row][column] << "\n";

QVector<int>& path = results[data[Jrow][Jcolumn]];
if(path.size() >= 2 && path[1] != 107){
int step = path[1];
//qDebug()  << "Size: "<< results[data[Jrow][Jcolumn]].size();
//for (int i = 0; i < results[data[Jrow][Jcolumn]].size(); i++){


     qDebug() << "start vertex: " << data[row][column] <<
                 "final vertex: " <<data[Jrow][Jcolumn] <<
                "path:" << step;
   //  qDebug() <<step;
     if (step == data[row+1][column])//down
     {
         row++;
     }
     else if (step == data[row-1][column]) //up
     {
       row--;
     }
     else if (step == data[row][column-1])//right
     {
        column--;

     } else if (step == data[row][column+1])//left
     {
      column++;
     }
// }
setPos(25+(25*column),25+(25*row));
}
QTimer::singleShot(300, this, SLOT(Tomplay()));
}

//void defend::TomCollision(Jerry &j){
//    qDebug() << "A\n";
//    QList<QGraphicsItem*> colliding= collidingItems();
//     qDebug() << "B\n";
//    for(int i=0;i<colliding.size();i++){
//        if(typeid((*colliding[i]))== typeid(Jerry)){
//             qDebug() << "C\n";
//            j.takeLife();
//           // qDebug() << "jerry lives: " << j->lives << "\n";
//}
//    }
//}

