#ifndef gamelogic_h
#define gamelogic_h

#include <iostream>
#include "..//boardClass/boardClass.h"
#include "..//ASCIIBoard/printBoard.h"

void startGame(board* ptrBoard);
bool gameWon(board* ptrBoard, bool player);
bool processMove(board *ptrBoard, bool player, int selectedPile);

#endif