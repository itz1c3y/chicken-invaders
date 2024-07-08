
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include "tracker.h"
#include <QGraphicsScene>
#include "Player.h"




Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\background)")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

     //spawn enemies


    auto * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()) , this , SLOT(spawner()));
    timer->start(1);





    // play background music
//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
//    music->play();

    show();



}


int level =1;

void Game::spawner() {

    if (level==1){
        player->spawn5();
        level++;
    }

}
