#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    // Constructors
    Position();
    Position(int x, int y);
    // Accessors
    int getX() const;
    int getY() const;
    // Mutators
    void setX(int x);
    void setY(int y);
private:
    int x;
    int y;
};

#endif // POSITION_H
