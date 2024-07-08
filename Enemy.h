
#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    int health;
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();
    void movehorizontal();
};

#endif // ENEMY_H
