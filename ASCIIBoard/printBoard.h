#ifndef printboard_h
#define printboard_h

#include <iostream>
#include "..//boardClass/boardClass.h"

// All terminal prints/inputs are declared here. Will make it easier to convert to non-terminal eventually
void printBoard(board* ptr);
int getMove(bool player, board* ptr);
void checkWinner(board* ptr);

#endif