#include "zblock.h"

ZBlock::ZBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(4,3));
    position.emplace_back(Coordinate(5,3));
    position.emplace_back(Coordinate(5,4));
    position.emplace_back(Coordinate(6,4));

    pivot = Coordinate(5,4);
}


ZBlock::~ZBlock() {}


string ZBlock::getname() {
    return name;
}


int ZBlock::getrotationpos() {
    return rotationpos;
}

bool ZBlock::getheavy() {
    return heavy;
}


Colour ZBlock::getColour() {
    return colour;
}

vector<Coordinate> ZBlock::getposition() {
    return position;
}

void ZBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void ZBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void ZBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() + move, pivot.getY());
}


void ZBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void ZBlock::CW() {
    for (unsigned int i = 0; i < position.size(); i++) {
        int newx_temp = (pivot.getY() - position[i].getY() + pivot.getX());
        int newy_temp = (position[i].getX() - pivot.getX() + pivot.getY());

        Coordinate new_coord(newx_temp, newy_temp);

        position[i] = new_coord;
    }
}


void ZBlock::CCW() {
    CW();
    CW();
    CW();
}

void ZBlock::printRow1() {
    std::cout << " ZZ ";
}

void ZBlock::printRow2() {
    std::cout << "  ZZ";
}