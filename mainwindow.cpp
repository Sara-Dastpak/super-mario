#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <vector>
#include <QString>
#include <QVBoxLayout>
#include "platform.h"
#include "decorator.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene)), player(nullptr), game(nullptr)
{
    setupScene();
    setupGame();
}

MainWindow::~MainWindow()
{
    delete view;
    delete scene;
    delete player;
    delete game;
}

void MainWindow::setupScene()
{
    // Set up the scene parameters (if needed)
    if (!scene || !view) {
        std::cerr << "Scene or View initialization failed." << std::endl;
        return;
    }
    scene->setSceneRect(0, 0, 1000, 800); // Adjust as necessary

    // Set up the view parameters (if needed)
    view->setFixedSize(1000, 800); // Adjust as necessary

    // Add the view to the main window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::drawObjects()
{
    // Draw platforms
    if (!scene) {
        std::cerr << "Scene is not properly initialized." << std::endl;
        return;
    }
    for (const auto &decorator : decorators)
    {
        decorator.draw(*scene);
    }
    for (const auto &platform : platforms)
    {
        platform.draw(*scene);
    }

    // Draw player (assuming player is set elsewhere)
    if (player)
    {
        player->draw(*scene); // Pass the actual scene object to the draw function
    }

}

void MainWindow::setupGame()
{
    // Example initialization of platforms, decorators, player, and game
    // Initialize platforms
    //std::vector <Platform> platforms;
    Platform platform1(200, 20, Position(0, 600), ":/platform/assets/platform.png");
    Platform platform2(100, 10, Position(600, 400), ":/platformSmallTall/assets/platformSmallTall.png");
    //platforms.emplace_back(200, 20, Position(0, 400), ":/platform/assets/platform.png");
    //platforms.emplace_back(100, 20, Position(300, 400), ":/platformSmallTall/assets/platformSmallTall.png");
    platforms.push_back(platform1);
    platforms.push_back(platform2);
    //std::vector <Decorator> decorators;
    // Initialize decorators
    Decorator decorator1(1000, 800, Position(0, 0), ":/background/assets/background.png");
    Decorator decorator2(100, 100, Position(600, 230), ":/hills/assets/hills.png");
    decorators.push_back(decorator1);
    decorators.push_back(decorator2);
    //decorators.emplace_back(800, 600, Position(0, 0), ":/background/assets/background.png");
    //decorators.emplace_back(100, 100, Position(200, 300), ":/hills/assets/hills.png");
    player = new Player(50, 50, Position(100, 400), 5); // Adjust as necessary
    game = new Game(*view, *scene, platforms, decorators, *player, 1000); // Adjust as necessary

    // Connect signals and slots
    //connect(game, &Game::gameOver, this, &MainWindow::handleGameOver);
    //connect(game, &Game::victory, this, &MainWindow::handleVictory);

    // Start drawing objects
    drawObjects();
}

void MainWindow::handleGameOver()
{
    std::cout << "Game Over: Player fell off the platform!" << std::endl;
    QMessageBox::information(nullptr, "Game Over", "Game Over: Player fell off the platform!");
    // Optionally, reset the game state or perform other actions upon game over
}

void MainWindow::handleVictory()
{
    std::cout << "Congratulations! You won the game!" << std::endl;
    QMessageBox::information(nullptr, "Victory", "Congratulations! You won the game!");
    // Optionally, reset the game state or perform other actions upon victory
}

//Game game(view, scene, platforms, decorators, player, distance);
//QObject::connect(&game, &Game::victory, [&]() {
    // Perform actions upon victory
    //QMessageBox::information(nullptr, "Victory", "Congratulations! You won the game!");
//});
