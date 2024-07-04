#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include <QGraphicsView>

#include "views/Score.h"
#include "views/Health.h"

class Game : public QGraphicsView {

public:
    Game();

    Score * score;
    Health * health;
};

#endif //MAIN_CPP_GAME_H
