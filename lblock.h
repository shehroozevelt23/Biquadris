#ifndef LBlock_H
#define LBlock_H

#include "block.h"
using namespace std;
class LBlock : public Block {

    public:
    LBlock(string name = "L", Colour colour = Colour::Orange, int rotationpos=0, bool heavy = false);
    ~LBlock();

    // Properties
    string getname() override;
    int getrotationpos() override;
    Colour getColour() override;
    bool getheavy() override;
    vector<Coordinate> getposition() override;
    
    // Setters
    void setheavy(bool heavy) override;

    // Movement
    void move_left(int move) override;
    void move_right(int move) override;
    void move_down(int move) override;

    // Rotation
    void CW() override;
    void CCW() override;

    void printRow1() override;
    void printRow2() override;
};

#endif