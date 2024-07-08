#include "Boss.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Egg.h"


extern Game * game;
QTimer * timerb = new QTimer();


Boss::Boss(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    // Load and set the pixmap for the Boss
    QPixmap boss(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\boss.png)");
    boss = boss.scaled(50, 50);
    setPixmap(boss);

    // Create and connect a timer to move() the boss periodically
    QTimer * timer2 = new QTimer();

    connect(timerb, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(lay()));


    // Start the timer
    timerb->start(50);
    timer2->start(1000);
}

void Boss::move() {
    // Move the boss downward
    if (y() < 400) {
        setPos(x(), y() + 10);
    } else
        delete timerb;
}

void Boss::lay(){
    int random = rand() % 40;
    if (random == 1) {
        Egg * egg = new Egg();
        egg->setPos(x(), y());
        scene()->addItem(egg);
    }
}
