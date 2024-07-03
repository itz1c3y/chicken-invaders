
#ifndef UNTITLED2_SPACESHIP_H
#define UNTITLED2_SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include <QObject>
#include <QPropertyAnimation>

class SpaceShip :public QObject, public QGraphicsPixmapItem{
Q_OBJECT
    Q_PROPERTY(qreal width READ x WRITE setX)

private:
    int frame{};
    int maxLeft{};
    int maxRight{};
    QTimer* weweTimer;
    QList<QPixmap*> frames{};
    QPropertyAnimation *moveAnimator;

public:
    SpaceShip(int sceneHeight, int sceneWidth, QGraphicsItem *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:

    void moveLeft();
    void moveRight();

public slots:
    void wewe();
};


#endif //UNTITLED2_SPACESHIP_H
