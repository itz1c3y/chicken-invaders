#include "Background.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QPainter>

Background::Background(int screenWidth , int screenHeight , QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {

    QPixmap pixmap(":/images/background");
    pixmap = pixmap.scaled(screenWidth , screenHeight , Qt::KeepAspectRatioByExpanding);
    pixmap = pixmap.copy(0 , 0 , screenWidth , pixmap.height());
    scaledImage = new QPixmap(pixmap);
    //setPixmap(pixmap);
    setPos(0 , 0);

    moveTimer = new QTimer();
    moveTimer->setInterval(50);
    connect(moveTimer , &QTimer::timeout , this , &Background::moveBackground);
    moveTimer->start();

}

void  Background::moveBackground() {
    currentX = (currentX + 2) % scaledImage->height();
    QPixmap croppedImage;
    int remindingHeight = scaledImage->height() - currentX;
    if (currentX < 0)
        croppedImage = scaledImage->copy(0 , currentX , scaledImage->width() , scaledImage->height());
    else
        croppedImage = scaledImage->copy(0 , currentX , scaledImage->width() , remindingHeight);

    QPixmap result(QSize(scaledImage->width() , scaledImage->height()));
    QPainter p(&result);
    p.drawPixmap(0 , 0 , croppedImage);

    if (currentX >= 0) {
        auto imageHeight = scaledImage->height() - remindingHeight;
        auto image = scaledImage->copy(0 , 0 , scaledImage->width() , imageHeight);
        p.drawPixmap(0 , remindingHeight , image);
    }

    setPixmap(result);
}