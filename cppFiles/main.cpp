#include "..//main/main.h"

int main() {
    board board1;
    board *ptrBoard;

    ptrBoard = &board1;
    startGame(ptrBoard);
    
    return 0;
}