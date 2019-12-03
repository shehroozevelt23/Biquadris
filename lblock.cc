#include "lblock.h"

LBlock::LBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(6,3));
    position.emplace_back(Coordinate(4,4));
    position.emplace_back(Coordinate(5,4));
    position.emplace_back(Coordinate(6,4));

    pivot = Coordinate(5,4);
}

LBlock::~LBlock() {}

string LBlock::getname() {
    return name;
}

int LBlock::getrotationpos() {
    return rotationpos;
}

Colour LBlock::getColour() {
    return colour;
}

bool LBlock::getheavy() {
    return heavy;
}

vector<Coordinate> LBlock::getposition() {
    return position;
}

void LBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void LBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void LBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() + move, pivot.getY());
}


void LBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void LBlock::CW() {
    for (unsigned int i = 0; i < position.size(); i++) {
        int newx_temp = (pivot.getY() - position[i].getY() + pivot.getX());
        int newy_temp = (position[i].getX() - pivot.getX() + pivot.getY());

        Coordinate new_coord(newx_temp, newy_temp);

        position[i] = new_coord;
    }
}

void LBlock::CCW() {
    CW();
    CW();
    CW();
}

void LBlock::printRow1() {
    std::cout << "   L";
}

void LBlock::printRow2() {
    std::cout << " LLL";
}