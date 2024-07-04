#include "platform.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>

Platform::Platform(int width, int height, Position position, const QString& imagePath, QGraphicsPixmapItem *image)
    : BodyObject(width, height, position, image), imagePath(imagePath) {}
int Platform::getHeight(){
    return height;
}
int Platform::getWidth(){
    return width;
}
void Platform::draw(QGraphicsScene &scene) {
    if (!image) {
        image = new QGraphicsPixmapItem(QPixmap(imagePath));
    }
    image->setPos(position.x, position.y);
    scene.addItem(image);
}
Position Platform::getPosition(){
    return position;
}

