#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <vector>
#include <QObject>
#include <QGraphicsScene>
#include "player.h"
#include "platform.h"
#include "decorator.h"

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = nullptr);
    ~Game();

    void setScene(QGraphicsScene* scene);
    void setPlayer(Player* player);
    void setPlatforms(const std::vector<Platform>& platforms);
    void setDistance(int distance);

signals:
    void gameOver();
    void victory();

public slots:
    void checkGameState();

private:
    QGraphicsScene* scene;
    Player* player;
    std::vector<Platform> platforms;
    int distance;
};

#endif // GAME_H
