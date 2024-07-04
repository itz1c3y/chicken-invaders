#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include <QObject>
#include <QPropertyAnimation>

class Enemy : public QObject , public QGraphicsPixmapItem {
Q_OBJECT

    Q_PROPERTY(qreal height READ y WRITE setY)

private :
    int frame{};
    int groundY{};
    QTimer* winingTimer;
    QList<QPixmap*> frames{};
    QPropertyAnimation *heightAnimator;

public :
    Enemy(int sceneWidth , int sceneHeight , QGraphicsItem* parent = nullptr);

public slots :
    void wining();
    void gravity();

};

#endif // ENEMY_H