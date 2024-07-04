#include "Game.h"
#include "views/Background.h"
#include "views/Enemy.h"

Game::Game() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());

    auto background = new Background(width() , height());
    scene->addItem(background);

    auto enemy = new Enemy(scene->sceneRect().width(), scene->sceneRect().height());
    scene->addItem(enemy);

    //create score
    score = new Score();
    scene->addItem(score);

    //create health
    health = new Health();
    health->setPos(health->x() , health->y()+100);

    setScene(scene);
}