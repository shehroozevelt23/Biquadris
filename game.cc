#include "game.h"
#include <iostream>


using namespace::std;
Game::Game(): 
    player1{new Player(1, new Level0(), nullptr, nullptr)},
    player2{new Player(2, new Level0(), nullptr, nullptr)} {
        player1->setcurrentblock(player1->getcurrentlevel()->createBlock(player1));
        player2->setcurrentblock(player2->getcurrentlevel()->createBlock(player2));
        player1->setnextblock(player1->getcurrentlevel()->createBlock(player1));
        player2->setnextblock(player2->getcurrentlevel()->createBlock(player2));
        player1->updategrid();
        player2->updategrid();
    }

Game::~Game(){
	delete player1;
	delete player2;
}

Player * Game::getPlayer1(){
    return player1;
}

Player * Game::getPlayer2(){
    return player2;
}

// void Game::setPlayer(Player *player, int level){
//     for (int row = 0; row < 15; row++) {
//         for (int col = 0; col < 11; col++) {
//             player->grid[row][col] = Cell();
//         }
//     }   
// }


void Game::printGame(Player *player1, Player * player2){
    cout << "Level:    " << player1->getlevel() << "     " << "Level:    " << player2->getlevel() << endl;
    cout << "Score:    " << player1->getscore() << "     " << "Score:    " << player2->getscore() << endl;
    cout << "High:     " << player1->gethigh()  << "     " << "High:     " << player2->gethigh() << endl;
    
    cout << "***********     ***********" << endl;
    for (int row = 0; row < 18; row++) {
        for (int col1 = 0; col1 < 11; col1++) {
            if (player1->getgrid()[row][col1].getisblind() == true) {
                cout << "?";
            }
            else {
                cout << player1->getgrid()[row][col1].get_display_value();
            }
        }
        cout << "     ";
        for (int col2 = 0; col2 < 11; col2++) {
            if (player2->getgrid()[row][col2].getisblind() == true) {
                cout << "?";
            }
            else {
                cout << player2->getgrid()[row][col2].get_display_value();
            }
        }
        cout << endl;
    }

    cout << "***********     ***********" << endl;
    cout << "Next:           Next:      " << endl;
    

    player1->getnextblock()->printRow1();
    cout << "            ";
    player2->getnextblock()->printRow1();
    cout << endl;
    player1->getnextblock()->printRow2();
    cout << "            ";
    player2->getnextblock()->printRow2();
    cout << endl;
}
