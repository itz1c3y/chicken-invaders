
#ifndef UNTITLED2_HEN_H
#define UNTITLED2_HEN_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Hen: public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Hen(QGraphicsItem * parent = nullptr);// Updated constructor declaration

public slots:
    void move();
    void lay();
};


#endif //UNTITLED2_HEN_H
