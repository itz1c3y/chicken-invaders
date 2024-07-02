#ifndef MAIN_CPP_BACKGROUND_H
#define MAIN_CPP_BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class Background : public QObject , public QGraphicsPixmapItem {
Q_OBJECT
private :
    int currentX;
    QPixmap* scaledImage;
    bool initialized{false};
    QTimer* moveTimer;
public :
    Background(int screenWidth , int screenHeight , QGraphicsItem* parent = nullptr);


public slots :
    void moveBackground();
};

#endif //MAIN_CPP_BACKGROUND_H
