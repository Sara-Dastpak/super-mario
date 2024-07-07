#ifndef PLATFORM_H
#define PLATFORM_H
#include "position.h"
#include "bodyobject.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Platform : public BodyObject {
public:
    Platform(int width, int height, const Position& position, const QString& imagePath);
    //int getWidth();
    //int getHeight();
    void draw(QGraphicsScene &scene) const override;
    Platform(const Platform& other);
    ~Platform();
    //Position getPosition();
private:
    QString imagePath;
    mutable QGraphicsPixmapItem* image;
};

#endif // PLATFORM_H
