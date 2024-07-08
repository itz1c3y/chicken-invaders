
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn1();
    void spawn2();
    void spawn3();
    void spawn4();
    void spawn5();
    void spawn6();


private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H
