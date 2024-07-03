#include "Enemy.h"

Enemy::Enemy(int sceneWidth, int sceneHeight, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {

    auto pixmap = new QPixmap(":/images/chicken");
    auto scaledPixmap = pixmap->scaled(64 , 61);
    setPixmap(scaledPixmap);
    frames.append(new QPixmap(scaledPixmap));

    pixmap = new QPixmap(":/images/chicken2");
    scaledPixmap = pixmap->scaled(64 , 61);
    frames.append(new QPixmap(scaledPixmap));

    winingTimer = new QTimer();
    winingTimer->setInterval(150);
    connect(winingTimer , &QTimer::timeout , this , Enemy::wining);
    winingTimer->start();

    // testing position(change it)
    setPos((sceneWidth - scaledPixmap.width()) / 2 , 0);

}

void Enemy::wining() {
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 2;
}
