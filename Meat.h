#ifndef MEAT_H
#define MEAT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Meat : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Meat(QGraphicsItem *parent = nullptr);
public slots:
    void move();
};

#endif // MEAT_H
