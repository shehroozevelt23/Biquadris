#include "tblock.h"

TBlock::TBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(4,3));
    position.emplace_back(Coordinate(5,3));
    position.emplace_back(Coordinate(6,3));
    position.emplace_back(Coordinate(5,4));

    pivot = Coordinate(5,3);
}


TBlock::~TBlock() {}


string TBlock::getname() {
    return name;
}


int TBlock::getrotationpos() {
    return rotationpos;
}

bool TBlock::getheavy() {
    return heavy;
}

Colour TBlock::getColour() {
    return colour;
}

vector<Coordinate> TBlock::getposition() {
    return position;
}

void TBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void TBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void TBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() -+ move, pivot.getY());
}


void TBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void TBlock::CW() {
    for (unsigned int i = 0; i < position.size(); i++) {
        int newx_temp = (pivot.getY() - position[i].getY() + pivot.getX());
        int newy_temp = (position[i].getX() - pivot.getX() + pivot.getY());

        Coordinate new_coord(newx_temp, newy_temp);

        position[i] = new_coord;
    }
}


void TBlock::CCW() {
    CW();
    CW();
    CW();
}

void TBlock::printRow1() {
    std::cout << " TTT";
}

void TBlock::printRow2() {
    std::cout << "  T ";
}