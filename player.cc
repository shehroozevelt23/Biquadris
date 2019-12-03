#include "player.h"
#include <vector>

using namespace::std;

Player::Player(int id, Level* currlevel, Block* currentblock, Block* nextblock, int score, int high,
int height, int width, int levelnum, bool rowsgreater2, bool specialheavy, bool forced, int numdropped, bool isgameover, bool random): 
id{id}, currlevel{currlevel}, currentblock{currentblock}, nextblock{nextblock}, score{score}, high{high},
height{height}, width{width}, levelnum{levelnum}, rowsgreater2{rowsgreater2}, specialheavy{specialheavy}, 
forced{forced}, numdropped{numdropped}, isgameover{isgameover}, random{random}{
    for (int i = 0; i < height; ++i){
        vector <Cell> row;
        for (int j = 0; j < width; ++j){
            row.emplace_back(Cell(true, " ", Coordinate(i,j)));   
        }
        grid.emplace_back(row);
    }
}

void Player::attach(Observer *ob) {
    this->observers.emplace_back(ob);
}


void Player::notifyObservers() {
    for (unsigned int i = 0; i < observers.size(); i++) {
        observers[i]->notify(*this);
    }
}

Player::~Player() {
    delete currentblock;
    delete nextblock;
    delete currlevel;
}

int Player::getHeight() { return height; }

int Player::getWidth() { return width; }

int Player::getId(){ return id; }

bool Player::getrowsgreater2() {
    return rowsgreater2;
}

void Player::setrowsgreater2(bool val) {
    rowsgreater2 = val;
}

Level *Player::getcurrentlevel(){
	return currlevel;
}


vector<vector<Cell>> Player::getgrid() {
    return grid;
}

// leftpossible returns whether moving by the number of cells
// to the left is valid (Doesn't hit existing non-empty blocks)
// and doesn't collide with the wall
bool Player::leftpossible(int move) {

    for (int j = 1; j <= move; j++) {
        for (unsigned int i = 0; i < currentblock->getposition().size(); ++i){
        
            int curr_x = currentblock->getposition()[i].getX();
            int curr_y = currentblock->getposition()[i].getY();

            // Check to ensure the move corresponds to an empty block
            if ((curr_x - j < 0) || (grid[curr_y][curr_x - j].getIsEmpty() == false)) {
                return false;
            }

        }
    }

    return true;
}

void Player::move_left(int move) {
    // Only 
    if (leftpossible(move)) {
        currentblock->move_left(move);
        if (currentblock->getheavy() == true) {
            if (downpossible(1)) {
                currentblock->move_down(1);
            }
        }
        if (specialheavy == true) {
            if (downpossible(2)) {
                currentblock->move_down(2);
            }
            else {
                drop();
            }
        }
        updategrid();
    }
}


// rightpossible returns whether moving by the number of cells
// to the right is valid (Doesn't hit existing non-empty blocks)
// and doesn't collide with the wall
bool Player::rightpossible(int move) {
    // Iterate from 0 to move
    for (int j = 1; j <= move; j++) {
        
        // Iterate through all coordinates in the currentblock
        for (unsigned int i = 0; i < currentblock->getposition().size(); ++i){
        
            int curr_x = currentblock->getposition()[i].getX();
            int curr_y = currentblock->getposition()[i].getY();

            // Check to ensure the move corresponds to an empty block
            if ((curr_x + j > 10) || (grid[curr_y][curr_x + j].getIsEmpty() == false)) {
                return false;
            }

        }
    }

    return true;
}


// move_right will move the currentblock by the specified
// number of cells to the right if the move is valid
void Player::move_right(int move) {
    // Only move if possible
    if (rightpossible(move)) {
        currentblock->move_right(move);
        if (currentblock->getheavy() == true) {
            if (downpossible(1)) {
                currentblock->move_down(1);
            }
        }
        if (specialheavy == true) {
            if (downpossible(2)) {
                currentblock->move_down(2);
            }
            else {
                drop();
            }
        }
        updategrid();
    }
}


// downpossible returns whether moving by the number of cells
// down is valid (Doesn't hit existing non-empty blocks)
// and doesn't collide with the wall
bool Player::downpossible(int move) {

    for (unsigned int i = 0; i < currentblock->getposition().size(); ++i){
    
        int curr_x = currentblock->getposition()[i].getX();
        int curr_y = currentblock->getposition()[i].getY();

        // Check to ensure the move corresponds to an empty block
        if ((curr_y + move > 17) || (grid[curr_y + move][curr_x].getIsEmpty() == false)) {
            return false;
        }

    }
    return true;
  
}


// move_down moves the block exactly one cell downwards
void Player::move_down() {
    if (downpossible(1)) {
        currentblock->move_down(1);
        updategrid();
    }
    if (specialheavy == true) {
        if (downpossible(2)) {
            currentblock->move_down(2);
        }
        else {
            drop();
        }
    }
}


// drop moves the block down until it hits the grid bottom
// or an already placed block
void Player::drop() {
    while(downpossible(1)) {
        currentblock->move_down(1);
    }

    // Once we can't go down any further, consider
    // the block fallen
    for (unsigned int i = 0; i < currentblock->getposition().size(); i++) {
        int x_val = currentblock->getposition()[i].getX();
        int y_val = currentblock->getposition()[i].getY();

        grid[y_val][x_val].set_is_empty(false);
        grid[y_val][x_val].set_display(currentblock->getname());   
    }

    checkFull();

    delete currentblock;
    currentblock = nextblock;
    nextblock = currlevel->createBlock(this);
    if(levelnum == 3 || levelnum == 4){
        nextblock->setheavy(true);
    }
    unblind();
    undospecialheavy();
    updategrid();

}


// Rotates current block clockwise, if possible
void Player::rotateCW() {
    currentblock->CW();

    for (unsigned int i = 0; i < currentblock->getposition().size(); ++i){
    
        int curr_x = currentblock->getposition()[i].getX();
        int curr_y = currentblock->getposition()[i].getY();

        // Check to ensure the move corresponds to an empty block
        if ((curr_y >= 18) || (curr_y < 0) || (curr_x >= 11) || (curr_x < 0) ||
            (grid[curr_x][curr_y].getIsEmpty() == false)) {
            currentblock->CCW();
            break;
        }
    }
    if (currentblock->getheavy() == true) {
        currentblock->move_down(1);
    }
    updategrid();
}


// Rotates current block counterclockwise
void Player::rotateCCW() {
    currentblock->CCW();

    for (unsigned int i = 0; i < currentblock->getposition().size(); ++i){
    
        int curr_x = currentblock->getposition()[i].getX();
        int curr_y = currentblock->getposition()[i].getY();

        // Check to ensure the move corresponds to an empty block
        if ((curr_y >= 18) || (curr_y < 0) || (curr_x >= 11) || (curr_x < 0) ||
            (grid[curr_x][curr_y].getIsEmpty() == false)) {
            currentblock->CW();
            break;
        }
    }
    if (currentblock->getheavy() == true) {
        currentblock->move_down(1);
    }
    updategrid();
}


// updategrid updates the grid after a move has been made
void Player::updategrid() {
    // Remove colour from all empty cells
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].getIsEmpty() == true) {
                grid[i][j].set_display(" ");
            }
        }
    }

    // Change the display of the coordinates corresponding
    // to the current block
    for (unsigned int i = 0; i < currentblock->getposition().size(); i++) {
        grid[currentblock->getposition()[i].getY()][currentblock->getposition()[i].getX()].set_display(currentblock->getname());
    }
}

int Player::getlevel() { return levelnum; }

Block* Player::getcurrentblock() { return currentblock; }


Block* Player::getnextblock(){ return nextblock; }

void Player::setcurrentblock(Block *b){
	currentblock = b;
}

void Player::setnextblock(Block *b){
	nextblock = b;
}

int Player::getscore() { return score; }

void Player::addLevel(int seed){
    if (levelnum < 4) {
        levelnum++;
        delete currlevel;
        if(levelnum == 1){
            currlevel = new Level1(); 
        }else if (levelnum == 2){
            currlevel = new Level2(seed); 
        }
        else if (levelnum == 3) {
            currlevel = new Level3(seed);
        }
        else if (levelnum == 4) {
            currlevel = new Level4(seed);
        }
        else {

        }
    }
}

void Player::decLevel(int seed){ 
    if (levelnum > 0) {
        levelnum--; 
        delete currlevel;
        if(levelnum == 0) {
            currlevel = new Level0();
        }else if(levelnum == 1){
            currlevel = new Level1(); 
        }else if (levelnum == 2){
            currlevel = new Level2(seed);
        }
        else if (levelnum == 3) {
            currlevel = new Level3(seed);
        }
        else {
        }
    }
}

void Player::addscore(int inc){ score += inc; }

void Player::checkFull() {
    
    int rows_cleared = 0;

    for (int i = 0; i < height; ++i){
        // Check if entire row is full
        bool isfull = true;
        for (int j = 0; j < width; ++j){
            if (grid[i][j].getIsEmpty() == true) {
                isfull = false;
                break;
            }
        }

        // Check to ensure that the game hasn't ended yet
        if (i == 5) {
            for (int j = 0; j < width; ++j){
                if (grid[i][j].getIsEmpty() == false) {
                    isgameover = true;
                }
            }
        }

        // If the row is full- delete the row and shift entire row downwards
        if (isfull == true) {
            for (int k = i; k > 0; k--) {
                for (int l = 0; l < width; l++) {
                    // Calculate score

                    // Set the isempty() and colour fields to be whatever previous row's is
                    grid[k][l].set_is_empty(grid[k-1][l].getIsEmpty());
                    grid[k][l].set_display(grid[k-1][l].get_display_value());
                }
            }
            rows_cleared++;
        }
    }

    if (rows_cleared > 0) {
        numdropped = 0;
        score += ((rows_cleared + levelnum) * (rows_cleared + levelnum));
        if (score > high) {
            high = score;
        }

        if (rows_cleared >= 2) {
            rowsgreater2 = true;
        }

    }
    else {
        if (levelnum == 4) {
            numdropped++;
            if (numdropped == 5) {
                dropsmall();
                numdropped = 0;
            }
        }
    }
}

bool Player::getisgameover() {
    return isgameover;
}

bool Player::getrand(){
    return random;
}

void Player::setrand(bool rand){
    random = rand;
}

void Player::dropsmall() {
    
    for (int i = 17; i >= 0; i--) {
        if (grid[i][5].getIsEmpty() == true) {
            grid[i][5].set_is_empty(false);
            grid[i][5].set_display("*");
            break;
        }
    }
}


int Player::gethigh() {
    return high;
}

void Player::sethigh(int high) {
    this->high = high;
}

// blinds the player from columns 3-9 and rows 3-12

void Player::blind() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i >= 3) && (i <= 12) && (j >= 3) && (j <= 9)) {
                grid[i][j].setblind(true);
            }
        }
    }
}

void Player::unblind() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j].setblind(false);
        }
    }
}


void Player::dospecialheavy() {
    specialheavy = true;
}

void Player::undospecialheavy() {
    specialheavy = false;
}

void Player::force(string block) {
    if (block == "I") {
        delete nextblock;
        nextblock = new IBlock();
    }
    else if (block == "J") {
        delete nextblock;
        nextblock = new JBlock();
    }
    else if (block == "L") {
        delete nextblock;
        nextblock = new LBlock();
    }
    else if (block == "O") {
        delete nextblock;
        nextblock = new OBlock();
    }
    else if (block == "S") {
        delete nextblock;
        nextblock = new SBlock();
    }
    else if (block == "Z") {
        delete nextblock;
        nextblock = new TBlock();
    }
    else {

    }

    if ((levelnum == 3) || (levelnum == 4)) {
        nextblock->setheavy(true);
    }
    
}

