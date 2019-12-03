#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class IBlock : public Block {

    public:
    IBlock(std::string name = "I", Colour colour = Colour::Blue, int rotationpos=0, bool heavy = false);
    ~IBlock();

    // Properties
    std::string getname() override;
    int getrotationpos() override;
    Colour getColour() override;
    bool getheavy() override;
    std::vector<Coordinate> getposition() override;

    // Setters
    void setheavy(bool heavy) override;

    // Movement
    void move_left(int move) override;
    void move_right(int move) override;
    void move_down(int move) override;

    // Rotation
    void CW() override;
    void CCW() override;

    // Print

    void printRow1() override;
    void printRow2() override;
};

#endif