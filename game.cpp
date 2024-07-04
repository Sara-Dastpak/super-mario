#include "Game.h"

Game::Game(QObject *parent) : QObject(parent), scene(nullptr), player(nullptr), distance(700)
{
}

Game::~Game()
{
    // No need to delete scene or player here; ownership remains with MainWindow
}

void Game::setScene(QGraphicsScene* scene)
{
    this->scene = scene;
}

void Game::setPlayer(Player* player)
{
    this->player = player;
}

void Game::setPlatforms(const std::vector<Platform>& platforms)
{
    this->platforms = platforms;
}
void Game::setDistance(int distance)
{
    this->distance = distance;
}

void Game::checkGameState()
{
    if (!player) return;

    // Check if player fell off platform
    bool onPlatform = false;
    for (const auto& platform : player->getPlatforms()) {
        if (player->isCollidingWithPlatform(platform)) {
            onPlatform = true;
            break;
        }
    }
    if (!onPlatform) {
        emit gameOver();
        return;
    }

    // Check if player reached victory distance
    if (player->getPosition().x > distance) {
        emit victory();
    }
}

