#ifndef PLAYER_H
#define PLAYER_H

#include "bodyobject.h"
#include "position.h"
#include "platform.h"
#include "decorator.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <vector>

class Player : public BodyObject {
    Q_OBJECT

public:
    enum State { StandLeft, StandRight, RunLeft, RunRight, JumpingLeft, JumpingRight };

    Player(int width, int height, Position position, QGraphicsPixmapItem *image = nullptr, int speed = 5);

    void setState(State state);
    void handleGravity(const std::vector<Platform>& );
    void handleMovement();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void updateImage();
    bool isCollidingWithPlatform(const std::vector<Platform>& platforms);

private slots:
    void updatePosition();

private:
    int speed;
    Position velocity;
    State currentState;
    QTimer *movementTimer;

    QPixmap standLeftImage;
    QPixmap standRightImage;
    QPixmap runLeftImage;
    QPixmap runRightImage;
    QPixmap jumpLeftImage;
    QPixmap jumpRightImage;


};

#endif // PLAYER_H
