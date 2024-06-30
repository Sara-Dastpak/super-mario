#include "Position.h"

// Default constructor
Position::Position() : x(0), y(0) {}

// Parameterized constructor
Position::Position(int x, int y) : x(x), y(y) {}

// Accessor for x
int Position::getX() const {
    return x;
}

// Accessor for y
int Position::getY() const {
    return y;
}

// Mutator for x
void Position::setX(int x) {
    this->x = x;
}

// Mutator for y
void Position::setY(int y) {
    this->y = y;
}

// Move the position by deltaX and deltaY
void Position::move(int deltaX, int deltaY) {
    x += deltaX;
    y += deltaY;
}
