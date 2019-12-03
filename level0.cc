#include "level0.h"
#include "player.h"
#include <fstream>

Level0::Level0(): Level(){
	ifstream f1{"biquadris_sequence1.txt"};
	ifstream f2{"biquadris_sequence2.txt"};

	string s;
	while(f1 >> s){
		seq1.push_back(s);
	}
	while(f2 >> s){
		seq2.push_back(s);
	}
}

Block *Level0::createBlock(Player *p){
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

void Level0::changeSeq1(string seq){
	seq1.clear();
	counter1 = 0;
	ifstream file{seq};
	string s;
	while(file >> s){
		seq1.push_back(s);
	}
}

void Level0::changeSeq2(string seq){
	seq2.clear();
	counter2 = 0;
	ifstream file{seq};
	string s;
	while(file >> s){
		seq2.push_back(s);
	}
}

Level0::~Level0(){}
