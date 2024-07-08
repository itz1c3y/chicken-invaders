#include "Meat.h"
#include <QTimer>
#include <QGraphicsScene>
#include "Game.h"
#include "Player.h"

extern Game *game; // there is an external global object called game

Meat::Meat(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    // draw graphics
    QPixmap meat(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\meat.png)");
    meat = meat.scaled(30, 30);
    setPixmap(meat);

    // make/connect a timer to move() the meat every so often
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Meat::move);

    // start the timer
    timer->start(50);
}

void Meat::move() {
    // get a list of all the items currently colliding with this meat
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is a Player, destroy both the meat and the player
    for (QGraphicsItem *item : colliding_items) {
        if (typeid(*item) == typeid(Player)) {
            // decrease the health
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non-existent meat)
            return;
        }
    }

    // if there was no collision with a Player, move the meat forward
    setPos(x(), y() + 5);

    // if the meat is off the screen, destroy it
    if (pos().y() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}
