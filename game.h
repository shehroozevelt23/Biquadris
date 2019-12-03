#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

#include "player.h"


class Game{
    Player * player1;
    Player * player2;
    public:
    Game();
    ~Game();
    Player *getPlayer1();
    Player *getPlayer2();
    void printGame(Player *player1, Player *player2);
};

#endif