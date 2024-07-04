#ifndef MAIN_CPP_HEALTH_H
#define MAIN_CPP_HEALTH_H


#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem {
public:
    Health(QGraphicsItem * parent=0);
    void Decrease();
    int getHealth();
private:
    int health;
};


#endif //MAIN_CPP_HEALTH_H
