#include "SpaceShip.h"
#include <QKeyEvent>

SpaceShip::SpaceShip(int sceneHeight, int sceneWidth, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();

    auto pixmap = new QPixmap(":/images/spaceship");
    auto scaledPixmap = pixmap->scaled(70,70);
    setPixmap(scaledPixmap);

    frames.append(new QPixmap(scaledPixmap));
    pixmap = new QPixmap("");
    scaledPixmap = pixmap->scaled(70,50);
    frames.append(new QPixmap(scaledPixmap));

    auto x = sceneWidth/2 - scaledPixmap.width()/2;
    auto y = 9*sceneHeight/10 - 9*scaledPixmap.height()/10;

    weweTimer = new QTimer;
    weweTimer->setInterval(10);
    connect(weweTimer, &QTimer::timeout, this, &SpaceShip::wewe);
    weweTimer->start();

    moveAnimator = new QPropertyAnimation(this, "width", this);

    maxLeft = sceneWidth/2 + 4*scaledPixmap.width();
    maxRight = sceneWidth/2 - 4*scaledPixmap.width();

    setPos(x, y);
}

void SpaceShip::wewe(){
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 2;
}

void SpaceShip::moveLeft() {
    moveAnimator->stop();
    moveAnimator->setStartValue(x());
    moveAnimator->setEndValue(x() + 20);
    moveAnimator->setEasingCurve(QEasingCurve::Linear);
    moveAnimator->start();
}

void SpaceShip::moveRight() {
    moveAnimator->stop();
    moveAnimator->setStartValue(x());
    moveAnimator->setEndValue(x() - 20);
    moveAnimator->setEasingCurve(QEasingCurve::Linear);
    moveAnimator->start();
}

void SpaceShip::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);

    if(event->key() == Qt::Key::Key_Left){
        if (pos().x() > 480)
            moveLeft();
    }

    if(event->key() == Qt::Key::Key_Right){
        if (pos().x() + 20 < 1440)
            moveRight();
    }
}
