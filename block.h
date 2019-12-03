#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <iostream>
#include "coordinate.h"
#include <string>

enum class Colour { Red, Orange, Yellow, Green, Blue, Purple, Pink, NoColour };

class Block {
    
    protected:
    std::string name;
    Colour colour;
    int rotationpos;
    bool heavy;
    std::vector<Coordinate> position;
    Coordinate pivot;

    public:
    Block(std::string name, Colour colour, int rotationpos, bool heavy);
    virtual ~Block();

    // Properties
    virtual std::string getname() = 0;
    virtual bool getheavy() = 0;
    virtual int getrotationpos() = 0;
    virtual Colour getColour() = 0;
    virtual std::vector<Coordinate> getposition() = 0;

    // Setters
    virtual void setheavy(bool heavy) = 0;

    // Movement
    virtual void move_left(int move) = 0;
    virtual void move_right(int move) = 0;
    virtual void move_down(int move) = 0;

    // Rotation
    virtual void CW() = 0;
    virtual void CCW() = 0;

    // Print
    virtual void printRow1() = 0;
    virtual void printRow2() = 0;

};

#endif