#include "Egg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"

extern Game * game; // there is an external global object called game

Egg::Egg(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    QPixmap egg(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\egg.png)");
    egg = egg.scaled(20, 20);
    setPixmap(egg);

    // make/connect a timer to move() the egg every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Egg::move(){
    // get a list of all the items currently colliding with this egg
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the egg and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            // increase the score
            game->health->decrease();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non-existent egg)
            return;
        }
    }


    // if there was no collision with an Enemy, move the egg forward
    setPos(x(), y() + 5);
    // if the egg is off the screen, destroy it
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
