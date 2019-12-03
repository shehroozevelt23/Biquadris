#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include <vector>
#include "level.h"
class Player;
using namespace std;

class Level3 : public Level{
	vector<string> seq1;
	vector<string> seq2;
	time_t seed;
public:
	Level3(time_t seed);
	void changeSeq1(string seq) override;
	void changeSeq2(string seq) override;
	Block *createBlock(Player *p) override;
	~Level3();
};

#endif