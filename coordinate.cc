#include "coordinate.h"

Coordinate::Coordinate(int x, int y):
    x{x}, y{y} {}

int Coordinate::getX() {
    return x;
}

int Coordinate::getY() {
    return y;
}

