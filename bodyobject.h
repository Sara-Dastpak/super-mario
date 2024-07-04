#ifndef BODYOBJECT_H
#define BODYOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "position.h"

class BodyObject {
public:
    int width;
    int height;
    Position position;
    QGraphicsPixmapItem* image;

    BodyObject(int width, int height, Position position, QGraphicsPixmapItem* image = nullptr)
        : width(width), height(height), position(position), image(image) {}

    virtual void draw(QGraphicsScene& scene) = 0;
};

#endif // BODYOBJECT_H
