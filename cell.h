#ifndef CELL_H
#define CELL_H
#include "coordinate.h"
#include <string>

class Cell {
    bool is_empty;
    std::string display_value;
    Coordinate coords;
    bool isblind;

    public:
    Cell(bool is_empty = true, std::string display_value = " ", Coordinate coords = Coordinate(0,0), bool isblind = false);
    bool getIsEmpty();
    std::string get_display_value();
    Coordinate getcoords();
    bool getisblind();

    void setblind(bool blind);
    void set_display(std::string c);
    void set_is_empty(bool b);
};



#endif
