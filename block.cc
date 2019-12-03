#include "block.h"

using namespace::std;

Block::Block(string name, Colour colour, int rotationpos, bool heavy):
    name{name}, colour{colour}, rotationpos{rotationpos}, heavy{heavy} {}

Block::~Block() {};
