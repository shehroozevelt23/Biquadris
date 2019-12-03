#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "player.h"
#include "game.h"
#include "GraphicsDisplay.h"
#include "window.h"
#include <stdlib.h> 

using namespace std;


bool player1turn = true;

int main(int argc, char * argv[]) {
	Game * g = new Game;

	
	Player *player1 = g->getPlayer1();
	Player *player2 = g->getPlayer2();

	
	int player1high = 0;
	int player2high = 0;


	string cmd_seq1;
	string cmd_seq2;
	int counter = 1;
	string script1 = "-scriptfile1";
	string script2 = "-scriptfile2";
	string sLevel = "-startlevel";
	string seedFlag = "-seed";
	string textFlag = "-text";
	time_t seed = 1;
	bool istext = false;

	if(argc >= 2){
		while(counter < argc){
			string arg = argv[counter];
			if(script1 == arg){
				delete player1->getcurrentblock();
				delete player1->getnextblock();
				cmd_seq1 = argv[counter + 1];
				counter += 2;
				player1->getcurrentlevel()->changeSeq1(cmd_seq1);
				player1->setcurrentblock(player1->getcurrentlevel()->createBlock(player1));
				player1->setnextblock(player1->getcurrentlevel()->createBlock(player1));
			}else if(script2 == arg){
				delete player2->getcurrentblock();
				delete player2->getnextblock();
				cmd_seq2 = argv[counter + 1];
				counter += 2;
				player2->getcurrentlevel()->changeSeq2(cmd_seq2);
				player2->setcurrentblock(player2->getcurrentlevel()->createBlock(player2));
				player2->setnextblock(player2->getcurrentlevel()->createBlock(player2));
			}else if(arg == sLevel){
				int startLevel = stoi(argv[counter + 1]);
				while(startLevel > 0 ){
					player1->addLevel(seed);
					player2->addLevel(seed);
					startLevel--;
				}
				counter += 2;
			}else if(arg == seedFlag){
				seed = stoi(argv[counter + 1]);
				counter += 2;
			}
			else if (arg == textFlag) {
				istext = true;
				counter += 2;
			}
		}
	}
	GraphicsDisplay * gd;
	if (istext == false) {
		gd = new GraphicsDisplay();
		player1->attach(gd);
		player2->attach(gd);
	}

	player1->notifyObservers();
	player2->notifyObservers();

	player1->updategrid();
	player2->updategrid();
    g->printGame(player1, player2);

	string intepreter;
	vector<string> lst;
	while(cin >> intepreter){
		if(intepreter == "sequence"){
			string fileName;
			cin >> fileName;
			ifstream f{fileName};
			string s;
			while(f >> s){
				lst.push_back(s);
			}
		}else{
			lst.push_back(intepreter);
		}

		while(lst.size() != 0){
			string cmd = lst[lst.size() - 1];
			int step = 0;
			int i = 0;
			while(cmd[i] <= '9' && cmd[i] >= '0'){
				int digit = cmd[i] - '0';
				step += digit * pow(10, i);
				i++;
			}
			if(step == 0) step++;
			cmd = cmd.substr(i);

			if (cmd[0] == 'I') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new IBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new IBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}
			}
			else if (cmd[0] == 'J') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new JBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new JBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}

			}
			else if (cmd[0] == 'L') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new LBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new LBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}
			}
			else if (cmd[0] == 'O') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new OBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new OBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}

			}
			else if (cmd[0] == 'S') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new SBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new SBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}

			}
			else if (cmd[0] == 'Z') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new ZBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new ZBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}

			}
			else if (cmd[0] == 'T') {
				if (player1turn) {
					delete player1->getcurrentblock();
					player1->setcurrentblock(new TBlock());
					player1->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player1->notifyObservers();
				}
				else {
					delete player2->getcurrentblock();
					player2->setcurrentblock(new TBlock());
					player2->updategrid();
					lst.pop_back();
					g->printGame(player1, player2);
					player2->notifyObservers();
				}

			}
			else if(cmd[0] == 'l'){
				//left
				//leveldown
				//levelup

				if(cmd.length() > 3){
					if(cmd[2] == 'f'){
						if(player1turn){
							player1->move_left(step);
							lst.pop_back();
							g->printGame(player1, player2);
							player1->notifyObservers();
						}else{
							player2->move_left(step);
							lst.pop_back();
							g->printGame(player1, player2);
							player2->notifyObservers();
						}
					}

					if(cmd.length() >= 6){
						if(cmd[5] == 'd'){
							if(player1turn){
								for(int i = 0; i < step; i++){
									player1->decLevel(seed);
								}
								lst.pop_back();
								g->printGame(player1, player2);
								player1->notifyObservers();
							}else{
								for(int i = 0; i < step; i++) {
									player2->decLevel(seed);
								}
								lst.pop_back();
								g->printGame(player1, player2);
								player2->notifyObservers();
							}
						}
						if(cmd[5] == 'u'){
							if(player1turn){
								for(int i = 0; i < step; i++) player1->addLevel(seed);
								lst.pop_back();
								g->printGame(player1, player2);
								player1->notifyObservers();
							}else{
								for(int i = 0; i < step; i++) {
									player2->addLevel(seed);
								}
								lst.pop_back();
								g->printGame(player1, player2);
								player2->notifyObservers();
							}
						}
					}	
				}
			}
			else if(cmd[0] == 'r'){
				//right
				//restart
				//random

				if(cmd.length() >= 2){
					if(cmd[1] == 'i'){	//right
						if(player1turn){
							player1->move_right(step);
							lst.pop_back();
							g->printGame(player1, player2);
							player1->notifyObservers();
						}else{
							player2->move_right(step);
							lst.pop_back();
							g->printGame(player1, player2);
							player2->notifyObservers();
						}
					}
					if(cmd[1] == 'e'){	//restart
						player1high = g->getPlayer1()->gethigh();
						player2high = g->getPlayer2()->gethigh();

						delete g;
						g = new Game();
						player1 = g->getPlayer1();
						player2 = g->getPlayer2();

						player1->sethigh(player1high);
						player2->sethigh(player2high);

						if (istext == false) {
						player1->attach(gd);
						player2->attach(gd);
						}

						lst.pop_back();
						player1turn = true;
						g->printGame(player1, player2);
						player1->notifyObservers();
						player2->notifyObservers();
					}
					if(cmd[1] == 'a'){	//random
						if(player1turn && player1->getrand() == false){
							if(player1->getlevel() == 3 || player1->getlevel() == 4){
								player1->setrand(true);
								lst.pop_back();
								g->printGame(player1, player2);
								player1->notifyObservers();
							}
						}else{
							player2->setrand(true);
							lst.pop_back();
							g->printGame(player1, player2);
							player2->notifyObservers();
						}
					}
				}
				
				
			}else if(cmd[0] == 'n'){
					//norandom
					string file;
					cin >> file;
						if(player1turn && player1->getrand() == true){
							if(player1->getlevel() == 3 || player1->getlevel() == 4){
								player1->getcurrentlevel()->changeSeq1(file);
								lst.pop_back();
								player1->setrand(false);
								g->printGame(player1, player2);
								player1->notifyObservers();
							}
						}else if(player2->getrand() == true){
							if(player1->getlevel() == 3 || player1->getlevel() == 4){
								player2->getcurrentlevel()->changeSeq2(file);
								player2->setrand(false);
								lst.pop_back();
								g->printGame(player1, player2);
								player2->notifyObservers();
							}
						}
				}else if(cmd[0] == 'd'){
					//down
					//drop
					if(cmd.length() >= 2){
						if(cmd[1] == 'o'){
							if(player1turn){
								player1->move_down();
								lst.pop_back();
								g->printGame(player1, player2);
								player1->notifyObservers();
							}else{
								player2->move_down();
								lst.pop_back();
								g->printGame(player1, player2);
								player2->notifyObservers();
							}
						}
					
					if(cmd[1] == 'r'){
						if(player1turn){
							
							player1->drop();

							if (player1->getisgameover() == true) {
								string winmessage = "Game is over - Player 2 wins!";
								std::cout << winmessage << std::endl;

								player1high = g->getPlayer1()->gethigh();
								player2high = g->getPlayer2()->gethigh();

								delete g;
								g = new Game();
								player1 = g->getPlayer1();
								player2 = g->getPlayer2();

								player1->sethigh(player1high);
								player2->sethigh(player2high);

								if (istext == false) {
								player1->attach(gd);
								player2->attach(gd);
								}

								lst.pop_back();
								player1turn = true;
								g->printGame(player1, player2);
								player1->notifyObservers();
								player2->notifyObservers();
								break;
							}

							player1turn = false;
							lst.pop_back();
							g->printGame(player1, player2);
							player1->notifyObservers();
							if(player1->getrowsgreater2()){
								cout << "Would you like to use special actions?" << endl;
								string s;
								cin >> s;
								if(s[0] == 'b'){
									player2->blind();
								}
								else if (s[0] == 'h') {
									player2->dospecialheavy();
								}
								else if (s[0] == 'f') {
									string block;
									cin >> block;
									player2->force(block);
								}
								player1->setrowsgreater2(false);
								player1->notifyObservers();
								g->printGame(player1, player2);
							}
						}else{
							
							player2->drop();

							if (player2->getisgameover() == true) {
								string winmessage = "Game is over - Player 1 wins!";
								std::cout << winmessage << std::endl;
								player1high = g->getPlayer1()->gethigh();
								player2high = g->getPlayer2()->gethigh();

								delete g;
								g = new Game();
								player1 = g->getPlayer1();
								player2 = g->getPlayer2();

								player1->sethigh(player1high);
								player2->sethigh(player2high);

								player1->attach(gd);
								player2->attach(gd);


								lst.pop_back();
								player1turn = true;
								g->printGame(player1, player2);
								player1->notifyObservers();
								player2->notifyObservers();
								break;
							}

							player1turn = true;
							lst.pop_back();
							g->printGame(player1, player2);
							player2->notifyObservers();
							
							if(player2->getrowsgreater2()){
								cout << "Would you like to use special actions?" << endl;
								string s;
								cin >> s;
								if(s[0] == 'b'){
									player1->blind();
								}
								else if (s[0] == 'h') {
									player1->dospecialheavy();
								}
								else if (s[0] == 'f') {
									string block;
									cin >> block;
									player1->force(block);
								}
								player2->setrowsgreater2(false);
							
								g->printGame(player1, player2);
								player2->notifyObservers();
							}
						}

					}
				}
			}else if(cmd[0] == 'c'){
				//clockwise
				//counterclockwise
				if(cmd.length() >= 2){
					if(cmd[1] == 'l' || cmd[1] == 'w') {
						if(player1turn){
							player1->rotateCW();
							lst.pop_back();
							g->printGame(player1, player2);
							player1->notifyObservers();
						}else{
							player2->rotateCW();
							lst.pop_back();
							g->printGame(player1, player2);
							player2->notifyObservers();
						}
					}
					if(cmd[1] == 'o' || cmd[1] == 'c'){
						if(player1turn){
							player1->rotateCCW();
							lst.pop_back();
							g->printGame(player1, player2);
							player1->notifyObservers();
						}else{
							player2->rotateCCW();
							lst.pop_back();
							g->printGame(player1, player2);
							player2->notifyObservers();
						}
					}
				}
			}
			else {
				lst.pop_back();
			}
		}
	}
	if (istext == false) {
		delete gd;
	}
	delete g;
}
