#ifndef ZBlock_H
#define ZBlock_H

#include "block.h"
using namespace std;
class ZBlock : public Block {

    public:
    ZBlock(string name = "Z", Colour colour = Colour::Pink, int rotationpos=0, bool heavy = false);
    ~ZBlock();

    // Properties
    string getname() override;
    int getrotationpos() override;
    bool getheavy() override;
    Colour getColour() override;
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