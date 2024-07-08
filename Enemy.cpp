#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

QTimer * timerc = new QTimer();


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    health = 2;
    // drew the rect
    QPixmap chick(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\chicken.png)");
    chick = chick.scaled(40,40);
    setPixmap(chick);

    connect(timerc, SIGNAL(timeout()), this, SLOT(move()));

    // start the timer
    timerc->start(50);


}


void Enemy::move() {
    // if the enemy reaches y = 400, stop moving it
    if (y() < 400) {
        setPos(x(), y() + 10);
    } else
        delete timerc;
}

void Enemy::movehorizontal(){

    setPos(x() + 5 ,y());


}
