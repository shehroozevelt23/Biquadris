#include "oblock.h"

OBlock::OBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(4,3));
    position.emplace_back(Coordinate(5,3));
    position.emplace_back(Coordinate(4,4));
    position.emplace_back(Coordinate(5,4));

    pivot = Coordinate(4,3);
}


OBlock::~OBlock() {}


string OBlock::getname() {
    return name;
}


int OBlock::getrotationpos() {
    return rotationpos;
}

bool OBlock::getheavy() {
    return heavy;
}


Colour OBlock::getColour() {
    return colour;
}

vector<Coordinate> OBlock::getposition() {
    return position;
}

void OBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void OBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void OBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() + move, pivot.getY());
}


void OBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void OBlock::CW() {}

void OBlock::CCW() {}

void OBlock::printRow1() {
    std::cout << " OO ";
}

void OBlock::printRow2() {
    std::cout << " OO ";
}