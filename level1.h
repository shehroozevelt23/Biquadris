#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include <vector>
#include "level.h"
class Player;
using namespace std;

class Level1 : public Level{
	// vector<string> seq1;
	// vector<string> seq2;
public:
	Level1();
	Block *createBlock(Player *p) override;
	~Level1();
};

#endif