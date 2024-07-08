
#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Hen.h"
#include "Score.h"
#include "tracker.h"
#include "Boss.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set bullet sound
//    bulletsound = new QMediaPlayer();
//    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));

    // set graphic
    QPixmap player(R"(C:\Users\Sahraee\CLionProjects\untitled2\resources\images\Spaceship1.png)");
    player = player.scaled(50,50);
    setPixmap(player);

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
        // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15, y());
        scene()->addItem(bullet);

        // play bulletsound
//        if (bulletsound->state() == QMediaPlayer::PlayingState){
//            bulletsound->setPosition(0);
//        }
//        else if (bulletsound->state() == QMediaPlayer::StoppedState){
//            bulletsound->play();
//        }

    }
}



void Player::spawn1(){
    // create an enemy
    for (int i = 0; i < 5;) {
        for (int j = 0; j < 4;) {
            Enemy * enemy = new Enemy();
            enemy->setPos(200+100*i,j*100-500);
            scene()->addItem(enemy);
            j++;
        }
        i++;
    }
}

void Player::spawn2(){
    // create a Hen
    for (int i = 0; i < 9;) {
        for (int j = 0; j < 4;) {
            Enemy* enemy = new Enemy();
            enemy->setPos(200+100*i,j*100-500);
            scene()->addItem(enemy);
            j++;
        }
        i++;
    }

}
void Player::spawn3() {
    // create a Hen
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; j++) {
            if (j % 2 == 0) {
                Enemy *enemy = new Enemy();
                enemy->setPos((j * 100 + 30), (i * 100 + 100));
                scene()->addItem(enemy);

            }
        }


        for (int j = 0; j < 8; ++j) {
            if (j%2==1) {
                for (int k = 0; k < 2; ++k) {

                    Hen *hen = new Hen();
                    hen->setPos(((j) * 100 + 30), (i * 100 + 100));
                    scene()->addItem(hen);

                }


            }
        }

    }
}

void Player::spawn4() {
    // create a Hen
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; j++) {
            if (j % 3 == 0 || j % 3 == 1) {
                Enemy *enemy = new Enemy();
                enemy->setPos(((j) * 100)-41, (i * 100 + 100));
                scene()->addItem(enemy);

            }
        }


        for (int j = 0; j < 10; ++j) {
            if (j % 3 == 0 || j % 3 == 1) {
                for (int k = 0; k < 2; ++k) {

                    Hen *hen = new Hen();
                    hen->setPos(((j) * 100 + 100), (i * 100 + 100));
                    scene()->addItem(hen);

                }


            }
        }

    }
}

void Player::spawn5() {
    // create a Hen
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; j++) {
            if (j % 2 == 0) {
                for (int k = 0; k < 2; ++k) {
                    Hen *hen = new Hen();
                    hen->setPos(((j+1) * 100 + 30), (i * 100 + 100));
                    scene()->addItem(hen);
                }


            }
        }


        for (int j = 0; j < 6; ++j) {
            if (j%2==1) {
                for (int k = 0; k < 4; ++k) {

                    Boss *boss = new Boss();
                    boss->setPos(((j+1) * 100 + 30), (i * 100 + 100));
                    scene()->addItem(boss);

                }


            }
        }

    }
}

void Player::spawn6() {
    // create a Hen
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 9; j++) {
            if (j % 2 == 0) {
                for (int k = 0; k < 2; ++k) {
                    Hen *hen = new Hen();
                    hen->setPos(((j+1) * 100 + 30), (i * 100 + 100));
                    scene()->addItem(hen);
                }


            }
        }


        for (int j = 0; j < 9; ++j) {
            if (j%2==1) {
                for (int k = 0; k < 4; ++k) {

                    Boss *boss = new Boss();
                    boss->setPos(((j+1) * 100 + 30), (i * 100 + 100));
                    scene()->addItem(boss);

                }


            }
        }

    }
}

