#include "Health.h"
#include <QFont>
#include <QGraphicsTextItem>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    // initialized the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Score : ") + QString::number(health)); // Health : 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times" , 16));
}

void Health::Decrease() {
    health--;
    setPlainText(QString("Health : ") + QString::number(health)); // Health : 2
}

int Health::getHealth() {
    return health;
};
