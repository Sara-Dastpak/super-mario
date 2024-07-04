#include "MainWindow.h"
#include <QGraphicsPixmapItem>
#include <QVBoxLayout>
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this)), player(nullptr), game(new Game(this))
{
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *centralWidget = new QWidget(this);
    layout->addWidget(view);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setupScene();
    drawObjects();

    // Connect game signals to handle game over and victory
    connect(game, &Game::gameOver, this, &MainWindow::handleGameOver);
    connect(game, &Game::victory, this, &MainWindow::handleVictory);
}

MainWindow::~MainWindow()
{
    delete player;
    delete game;
    for (auto& platform : platforms) {
        delete platform.image;
    }
    for (auto& decoration : decorations) {
        delete decoration.image;
    }
}

void MainWindow::setupScene()
{
    scene->setSceneRect(0, 0, 800, 600);

    platforms = {
        Platform(200, 20, Position(0, 400), ":/platform/assets/platform.png"),
        Platform(100, 20, Position(300, 400), ":/platformSmallTall/assets/platformSmallTall.png")
    };

    decorations = {
        Decorator(800, 600, Position(0, 0), ":/background/assets/background.png"),
        Decorator(100, 100, Position(200, 300), ":/hills/assets/hills.png")
    };

    player = new Player(50, 50, Position(0, 350), new QGraphicsPixmapItem());
    player->setPlatforms(platforms);
    //view->setFocusItem(player->image);
    view->setFocusItem(player->getImage());

    // Set player in game
    game->setPlayer(player);
}

void MainWindow::drawObjects()
{
    for (auto& platform : platforms) {
        platform.draw(*scene);
    }

    for (auto& decoration : decorations) {
        decoration.draw(*scene);
    }

    if (player) {
        scene->addItem(player->getImage());
        player->getImage()->setPos(player->position.x, player->position.y);
        //if (player) {
        //scene->addItem(player->image);
        // player->image->setPos(player->position.x, player->position.y);

    }
}

void MainWindow::handleGameOver()
{
    QMessageBox::information(this, "Game Over", "You fell off the platforms!");
    // Reset game or show appropriate UI
}

void MainWindow::handleVictory()
{
    QMessageBox::information(this, "Victory", "You reached the destination!");
    // Reset game or show appropriate UI
}
