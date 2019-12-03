#ifndef JBlock_H
#define JBlock_H

#include "block.h"

using namespace std;

class JBlock : public Block {

    public:
    JBlock(string name = "J", Colour colour = Colour::Purple, int rotationpos=0, bool heavy = false);
    ~JBlock();

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