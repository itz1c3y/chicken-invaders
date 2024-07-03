#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include <QObject>

class Enemy : public QObject , public QGraphicsPixmapItem {
    Q_OBJECT

private :
    int frame{};
    QTimer* winingTimer;
    QList<QPixmap*> frames{};


public :
    Enemy(int sceneWidth , int sceneHeight , QGraphicsItem* parent = nullptr);

public slots :
    void wining();

};


#endif //MAIN_CPP_ENEMY_H
