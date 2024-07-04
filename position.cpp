#include "position.h"

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int x) {
    this->x = x;
}

void Position::setY(int y) {
    this->y = y;
}

void Position::moveBy(int dx, int dy) {
    x += dx;
    y += dy;
}

bool Position::isWithinBounds(int minX, int maxX, int minY, int maxY) const {
    return x >= minX && x <= maxX && y >= minY && y <= maxY;
}
