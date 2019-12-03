#include "level4.h"
#include "player.h"
#include <fstream>

Level4::Level4(time_t seed): 
    Level(), seed{seed} {}

Block *Level4::createBlock(Player *p){ 
	if(p->getrand() == true){
	srand(time(&seed)); 
	int i = rand()%9 + 1;
	if(i == 1) return new IBlock();
	if(i == 2) return new LBlock();
	if(i == 3) return new OBlock();
	if(i == 4) return new TBlock();
	if(i == 5) return new JBlock();
	if(i >= 6 && i <= 7) return new SBlock();
	if(i >= 8 && i <= 9) return new ZBlock();
	return new IBlock();
	}else{
		string nextB;
	if(p->getId() == 1){
		if(counter1 == seq1.size()){
			counter1 = 0;
		}
		nextB = seq1[counter1];
		counter1++;
	}
	if(p->getId() == 2){
		if(counter2 == seq2.size()){
			counter2 = 0;
		}
		nextB = seq2[counter2];
		counter2++;
	}
	if(nextB == "I") return new IBlock();
	if(nextB == "L") return new LBlock();
	if(nextB == "O") return new OBlock();
	if(nextB == "T") return new TBlock();
	if(nextB == "J") return new JBlock();
	if(nextB == "S") return new SBlock();
	if(nextB == "Z") return new ZBlock();

	return new IBlock();
	}
}


void Level4::changeSeq1(string seq){
	seq1.clear();
	counter1 = 0;
	ifstream file{seq};
	string s;
	while(file >> s){
		seq1.push_back(s);
	}
}

void Level4::changeSeq2(string seq){
	seq2.clear();
	counter2 = 0;
	ifstream file{seq};
	string s;
	while(file >> s){
		seq2.push_back(s);
	}
}

Level4::~Level4(){}