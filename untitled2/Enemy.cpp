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
    connect(winingTimer , &QTimer::timeout , this , &Enemy::wining);
    winingTimer->start();

    auto x = (sceneWidth - scaledPixmap.width()) / 2;
    auto y = 0;

    groundY = sceneHeight - 100;

    heightAnimator = new QPropertyAnimation(this, "height", this);
    heightAnimator->setStartValue(y);
    heightAnimator->setEndValue(y);
    heightAnimator->setDuration(5000);
    heightAnimator->start();
    connect(heightAnimator, &QPropertyAnimation::finished, this, &Enemy::gravity);

    // testing position(change it)
    setPos(x, y);

}

void Enemy::wining() {
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 2;
}

void Enemy::gravity() {
    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(groundY);
    heightAnimator->setDuration(10000);
    heightAnimator->setEasingCurve(QEasingCurve::Linear);
    heightAnimator->start();

}
