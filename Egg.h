//
// Created by Sahraee on 07/07/2024.
//


#ifndef EGG_H
#define EGG_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Egg : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Egg(QGraphicsItem *parent = nullptr);
public slots:
    void move();
};

#endif // EGG_H

