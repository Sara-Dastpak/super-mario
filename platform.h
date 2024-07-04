#ifndef PLATFORM_H
#define PLATFORM_H
#include "position.h"
#include "bodyobject.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Platform : public BodyObject {
public:
    Platform(int width, int height, Position position, const QString& imagePath, QGraphicsPixmapItem *image = nullptr);
    int getWidth();
    int getHeight();
    void draw(QGraphicsScene &scene) override;
    Position getPosition();
private:
    QString imagePath;
};

#endif // PLATFORM_H
