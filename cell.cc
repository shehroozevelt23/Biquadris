#include "cell.h"

using namespace std;

Cell::Cell(bool is_empty, string display_value, Coordinate coords, bool isblind): 
    is_empty{is_empty}, display_value{display_value}, coords{coords}, isblind{isblind} {}

bool Cell::getIsEmpty() {
    return is_empty;
}

string Cell::get_display_value() {
    return display_value;
}

Coordinate Cell::getcoords() {
    return coords;
}

void Cell::set_display(string c) {
    display_value = c;
}

void Cell::set_is_empty(bool b) {
    is_empty = b;
}

bool Cell::getisblind() {
    return isblind;
}

void Cell::setblind(bool blind) {
    isblind = blind;    
}