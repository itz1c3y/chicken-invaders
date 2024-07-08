#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Boss : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Boss(QGraphicsItem *parent = 0);
public slots:
    void move();
    void lay();
};

#endif // BOSS_H
