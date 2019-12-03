#ifndef LEVEL_H
#define LEVEL_H

#include "iblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include "jblock.h"
#include "zblock.h"
#include "sblock.h"


class Player;
class Block;

class Level{
    protected:
    int counter1;
    int counter2;
public:
	Level();
	virtual Block *createBlock(Player *p)=0;
	virtual void changeSeq1(string seq);
	virtual void changeSeq2(string seq);
	void print(){ cout << "hi " << endl;}
	virtual ~Level();
};

#endif