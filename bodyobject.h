#ifndef BODYOBJECT_H
#define BODYOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include "position.h"

class BodyObject:public QObject {
    Q_OBJECT
public:
    int width;
    int height;
    Position position;
    QGraphicsPixmapItem* image;

    BodyObject(int width, int height, Position position, QGraphicsPixmapItem* image = nullptr);
    ~BodyObject();
    BodyObject(const BodyObject& other);

    virtual void draw(QGraphicsScene& scene) const = 0;
};

#endif // BODYOBJECT_H
