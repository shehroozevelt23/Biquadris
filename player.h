#ifndef PLAYER_H
#define PLAYER_H

#include "cell.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "block.h"
#include <vector>
#include "observer.h"

class Player {
    int id;
    Level* currlevel;
    Block* currentblock;
    Block* nextblock;
    int score;
    int high;
    int height;
    int width;
    int levelnum;
    std::vector<std::vector<Cell>> grid;
    bool rowsgreater2;
    bool specialheavy;
    bool forced;
    int numdropped;
    bool isgameover;
    bool random;
    std::vector<Observer *> observers;

    public:
    Player(int id, Level* currlevel, Block* currentblock, Block* nextblock, 
           int score = 0, int high = 0, int height = 18, int width = 11, 
           int levelnum = 0, bool rowsgreater2 = false, bool specialheavy = false, 
           bool forced = false, int numdropped = 0, bool isgameover = false, bool random = true);
    

    ~Player();
    void attach(Observer * ob);
    void notifyObservers();
    int getHeight();
    int getWidth();
    int getId();
    Level *getcurrentlevel();
    std::vector<std::vector<Cell>> getgrid();
    
    bool getrowsgreater2();
    void setrowsgreater2(bool val);

    // Moving left
    void move_left(int move);
    bool leftpossible(int move);

    // Moving right
    void move_right(int move);
    bool rightpossible(int move);

    // Moving down
    void move_down();
    void drop();
    bool downpossible(int move);

    // Rotating
    void rotateCW();
    void rotateCCW();

    void updategrid();
    
    Block* getcurrentblock();
    Block* getnextblock();
    void setcurrentblock(Block *b);
    void setnextblock(Block *b);

    int getlevel();
    void addLevel(int seed);
    void decLevel(int seed);
    
    int getscore();
    void addscore(int inc);

    int gethigh();
    void sethigh(int high);
    
    void checkFull();

    bool getisgameover();
    bool getrand();
    void setrand(bool rand);

    // Special action
    void blind();
    void unblind();

    void dospecialheavy();
    void undospecialheavy();

    void force(string block);

    void dropsmall();

};

#endif