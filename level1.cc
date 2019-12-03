#include "level1.h"
#include "player.h"
#include <fstream>

Level1::Level1(): Level(){
	// m
}

Block *Level1::createBlock(Player *p){
	// string nextB;
	// if(p->getId() == 1){
	// 	if(counter1 == seq1.size()){
	// 		counter1 = 0;
	// 	}
	// 	nextB = seq1[counter1];
	// 	counter1++;
	// }
	// if(p->getId() == 2){
	// 	if(counter2 == seq2.size()){
	// 		counter2 = 0;
	// 	}
	// 	nextB = seq2[counter2];
	// 	counter2++;
	// }
	srand(time(0)); 
	int i = rand()%12 + 1;
	if(i >= 1 && i <= 2) return new IBlock();
	if(i >= 3 && i <= 4) return new LBlock();
	if(i >= 5 && i <= 6) return new OBlock();
	if(i >= 7 && i <= 8) return new TBlock();
	if(i >= 9 && i <= 10)return new JBlock();
	if(i == 11) return new SBlock();
	if(i == 12) return new ZBlock();

	return new IBlock();
}

Level1::~Level1(){}