#ifndef MAIN_CPP_SCORE_H
#define MAIN_CPP_SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem * parent=0);
    void Increase();
    int getScore();
private:
    int score;
};


#endif //MAIN_CPP_SCORE_H
