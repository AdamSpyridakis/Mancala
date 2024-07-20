#include "..//gameLogic/gameLogic.h"

void startGame(board *ptrBoard)
{
    printBoard(ptrBoard);

    bool player{true};
    int selectedPile{};
    while (gameWon(ptrBoard, player))
    {
        selectedPile = getMove(player, ptrBoard);
        processMove(ptrBoard, player, selectedPile);
        printBoard(ptrBoard);
        if (player)
        {
            player = false;
        }
        else
        {
            player = true;
        }
    }
}

void processMove(board *ptrBoard, bool player, int selectedPile)
{
    int distribute = ptrBoard->getRockValue(selectedPile);
    int currentVal{};
    ptrBoard->setRockValue(selectedPile, 0);
    while (distribute >= 0)
    {
        selectedPile++;
        // loop back around
        if (selectedPile > 13)
        {
            selectedPile = 0;
        }
        currentVal = ptrBoard->getRockValue(selectedPile);
        currentVal++;
        ptrBoard->setRockValue(selectedPile, currentVal);
        distribute--;
    }
}

// Game ends when the player whose turn it is has no rocks left
bool gameWon(board *ptrBoard, bool player)
{
    bool gameOver{false};
    if (player)
    {
        for (int i{1}; i <= 6; i++)
        {
            if (ptrBoard->getRockValue(i) != 0)
            {
                // Player 1 has rocks, game not over
                gameOver = true;
            }
        }
    }
    else
    {
        for (int i{8}; i <= 13; i++)
        {
            if (ptrBoard->getRockValue(i) != 0)
            {
                // Player 2 has rocks, game not over
                gameOver = true;
            }
        }
    }
    return gameOver;
}