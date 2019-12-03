#include "level2.h"
#include "player.h"
#include <fstream>

Level2::Level2(time_t seed): Level(), seed{seed}{}

Block *Level2::createBlock(Player *p){
	srand(time(&seed)); 
	int i = rand()%7 + 1;
	if(i == 1) return new IBlock();
	if(i == 2) return new LBlock();
	if(i == 3) return new OBlock();
	if(i == 4) return new TBlock();
	if(i == 5) return new JBlock();
	if(i == 6) return new SBlock();
	if(i == 7) return new ZBlock();

	return new IBlock();
}

Level2::~Level2(){}