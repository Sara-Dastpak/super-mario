#ifndef DECORATOR_H
#define DECORATOR_H

#include "bodyobject.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Decorator : public BodyObject {
public:
    Decorator(int width, int height, Position position, const QString& imagePath, QGraphicsPixmapItem *image = nullptr);

    void draw(QGraphicsScene &scene) override;

private:
    QString imagePath;
};

#endif // DECORATOR_H
