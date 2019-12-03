#include "iblock.h"


using namespace::std;

IBlock::IBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(3,3));
    position.emplace_back(Coordinate(4,3));
    position.emplace_back(Coordinate(5,3));
    position.emplace_back(Coordinate(6,3));

    pivot = Coordinate(4,3);
}


IBlock::~IBlock() {}


string IBlock::getname() {
    return name;
}

bool IBlock::getheavy() {
    return heavy;
}


int IBlock::getrotationpos() {
    return rotationpos;
}


Colour IBlock::getColour() {
    return colour;
}

vector<Coordinate> IBlock::getposition() {
    return position;
}

void IBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void IBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void IBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }
    pivot = Coordinate(pivot.getX() + move, pivot.getY());
}


void IBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void IBlock::CW() {

    // If we are currently in rotationpos 0, we need to switch
    // to rotationpos 1
    if (rotationpos == 0) {
        rotationpos = 1;

        position[0] = Coordinate(position[0].getX() + 2, position[0].getY() - 1);
        position[1] = Coordinate(position[1].getX() + 1, position[1].getY());
        position[2] = Coordinate(position[2].getX(), position[2].getY() + 1);
        position[3] = Coordinate(position[3].getX() - 1, position[3].getY() + 2);
    }

    // Otherwise switch to rotationpos 0
    else {
        rotationpos = 0;

        position[0] = Coordinate(position[0].getX() - 2, position[0].getY() + 1);
        position[1] = Coordinate(position[1].getX() - 1, position[1].getY());
        position[2] = Coordinate(position[2].getX(), position[2].getY() - 1);
        position[3] = Coordinate(position[3].getX() + 1, position[3].getY() - 2);
    }
}


void IBlock::CCW() {
    CW();
}

void IBlock::printRow1() {
    std::cout << "IIII";
}


void IBlock::printRow2() {
    std::cout << "    ";
}