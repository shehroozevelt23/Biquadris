#include "sblock.h"

SBlock::SBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(5,3));
    position.emplace_back(Coordinate(6,3));
    position.emplace_back(Coordinate(4,4));
    position.emplace_back(Coordinate(5,4));

    pivot = Coordinate(5,4);
}


SBlock::~SBlock() {}


string SBlock::getname() {
    return name;
}


int SBlock::getrotationpos() {
    return rotationpos;
}


Colour SBlock::getColour() {
    return colour;
}

bool SBlock::getheavy() {
    return heavy;
}

vector<Coordinate> SBlock::getposition() {
    return position;
}

void SBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void SBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void SBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() + move, pivot.getY());
}


void SBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void SBlock::CW() {
    for (unsigned int i = 0; i < position.size(); i++) {
        int newx_temp = (pivot.getY() - position[i].getY() + pivot.getX());
        int newy_temp = (position[i].getX() - pivot.getX() + pivot.getY());

        Coordinate new_coord(newx_temp, newy_temp);

        position[i] = new_coord;
    }
}


void SBlock::CCW() {
    CW();
    CW();
    CW();
}

void SBlock::printRow1() {
    std::cout << " SS ";
}

void SBlock::printRow2() {
    std::cout << "SS  ";
}