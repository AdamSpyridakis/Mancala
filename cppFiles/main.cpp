#include "..//main/main.h"

int main() {
    board board1;
    board *ptrBoard;

    ptrBoard = &board1;

    printBoard(ptrBoard);
    
    return 0;
}