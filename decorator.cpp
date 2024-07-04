#include "decorator.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>

Decorator::Decorator(int width, int height, Position position, const QString& imagePath, QGraphicsPixmapItem *image)
    : BodyObject(width, height, position, image), imagePath(imagePath) {}

void Decorator::draw(QGraphicsScene &scene) {
    if (!image) {
        image = new QGraphicsPixmapItem(QPixmap(imagePath));
    }
    image->setPos(position.x, position.y);
    scene.addItem(image);
}
