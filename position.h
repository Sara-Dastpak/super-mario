#ifndef POSITION_H
#define POSITION_H

#include <QDebug>

class Position {
public:
    Position(int x = 0, int y = 0);

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    void moveBy(int dx, int dy);
    bool isWithinBounds(int minX, int maxX, int minY, int maxY) const;
    int x;
    int y;
};

#endif // POSITION_H