#ifndef LEVEL2_H
#define LEVEL2_H

#include <string>
#include <vector>
#include "level.h"
class Player;
using namespace std;

class Level2 : public Level{
	time_t seed;
public:
	Level2(time_t seed);
	Block *createBlock(Player *p) override;
	~Level2();
};

#endif