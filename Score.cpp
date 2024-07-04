#include "Score.h"
#include <QFont>
#include <QGraphicsTextItem>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    // initialized the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score : ") + QString::number(score)); // score : 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times" , 16));
}

void Score::Increase() {
    score += 5;
    setPlainText(QString("Score : ") + QString::number(score)); // score : 5
}

int Score::getScore() {
    return score;
};
