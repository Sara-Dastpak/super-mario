#include "bodyobject.h"

BodyObject::BodyObject(int width, int height, Position position, QGraphicsPixmapItem *image)
    : width(width), height(height), position(position), image(image) {
    if (!image) {
        this->image = new QGraphicsPixmapItem();
    }
}
BodyObject::~BodyObject() {
    delete image;
}
