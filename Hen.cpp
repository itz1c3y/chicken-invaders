#include "Hen.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Egg.h"


extern Game * game;
QTimer * timerh = new QTimer();


Hen::Hen(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    // Load and set the pixmap for the Hen
    QPixmap chicken(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\chicken2.png)");
    chicken = chicken.scaled(50, 50);
    setPixmap(chicken);

    // Create and connect a timer to move() the hen periodically
    QTimer * timer2 = new QTimer();

    connect(timerh, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(lay()));


    // Start the timer
    timerh->start(50);
    timer2->start(1000);



}

void Hen::move() {
    // Move the hen downward
    if (y() < 400) {
        setPos(x(), y() + 10);
    } else
        delete timerh;


}

void Hen::lay(){
    int random = rand()%20;
    if (random == 1){

         Egg * egg = new Egg();
        egg->setPos(x(), y());
        scene()->addItem(egg);

    }



}
