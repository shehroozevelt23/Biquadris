#ifndef LEVEL0_H
#define LEVEL0_H

#include <string>
#include <vector>
#include "level.h"
using namespace std;

class Player;

class Level0 : public Level{
	vector<string> seq1;
	vector<string> seq2;
public:
	Level0();
	void changeSeq1(string seq) override;
	void changeSeq2(string seq) override;
	Block *createBlock(Player *p) override;
	~Level0();
};

#endif