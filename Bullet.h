#ifndef MAIN_CPP_BULLET_H
#define MAIN_CPP_BULLET_H


#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsRectItem{
Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif //MAIN_CPP_BULLET_H
