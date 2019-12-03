#include "jblock.h"

using namespace::std;

JBlock::JBlock(string name, Colour colour, int rotationpos, bool heavy):
    Block{name, colour, rotationpos, heavy} {
    position.emplace_back(Coordinate(4,3));
    position.emplace_back(Coordinate(4,4));
    position.emplace_back(Coordinate(5,4));
    position.emplace_back(Coordinate(6,4));

    pivot = Coordinate(5,4);
}


JBlock::~JBlock() {}


string JBlock::getname() {
    return name;
}


int JBlock::getrotationpos() {
    return rotationpos;
}

bool JBlock::getheavy() {
    return heavy;
}


Colour JBlock::getColour() {
    return colour;
}

vector<Coordinate> JBlock::getposition() {
    return position;
}

void JBlock::setheavy(bool heavy) {
    this->heavy = heavy;
}

void JBlock::move_left(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() - move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() - move, pivot.getY());
}

void JBlock::move_right(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX() + move, position[i].getY());
    }

    pivot = Coordinate(pivot.getX() + move, pivot.getY());
}



void JBlock::move_down(int move) {
    for (unsigned int i = 0; i < position.size(); i++) {
        position[i] = Coordinate(position[i].getX(), position[i].getY() + move);
    }

    pivot = Coordinate(pivot.getX(), pivot.getY() + move);
}


void JBlock::CW() {
    for (unsigned int i = 0; i < position.size(); i++) {
        int newx_temp = (pivot.getY() - position[i].getY() + pivot.getX());
        int newy_temp = (position[i].getX() - pivot.getX() + pivot.getY());

        Coordinate new_coord(newx_temp, newy_temp);

        position[i] = new_coord;
    }
}


void JBlock::CCW() {
    CW();
    CW();
    CW();
}

void JBlock::printRow1() {
    std::cout << " J  ";
}

void JBlock::printRow2() {
    std::cout << " JJJ";
}