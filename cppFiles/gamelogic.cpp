#include "..//gameLogic/gameLogic.h"

void startGame(board *ptrBoard)
{
    printBoard(ptrBoard);

    bool player{true};
    int selectedPile{};
    while (gameWon(ptrBoard, player))
    {
        selectedPile = getMove(player, ptrBoard);
        /* Quit */
        if(selectedPile == -1){
            return;
        }
        player = processMove(ptrBoard, player, selectedPile);
        printBoard(ptrBoard);
    }
}

// Returns boolean corresponding to player whose turn is next
bool processMove(board *ptrBoard, bool player, int selectedPile)
{
    int distribute = ptrBoard->getRockValue(selectedPile);
    int currentVal{};
    ptrBoard->setRockValue(selectedPile, 0);
    while (distribute > 0)
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
    // Check for a capture
    int currentScore;
    if (player)
    {
        // If the last rock was placed on your side, and there were no rocks present before
        if ((selectedPile <= 6 && selectedPile >= 1) && ptrBoard->getRockValue(selectedPile) == 1)
        {
            currentScore = ptrBoard->getRockValue(7);
            // Add the rocks across to your pile
            ptrBoard->setRockValue(7, currentScore + ptrBoard->getRockValue(14 - selectedPile) + 1);
            ptrBoard->setRockValue(14 - selectedPile, 0);
            ptrBoard->setRockValue(selectedPile, 0);
        }
    }
    else
    {
        // If the last rock was placed on your side, and there were no rocks present before
        if ((selectedPile <= 13 && selectedPile >= 8) && ptrBoard->getRockValue(selectedPile) == 1)
        {
            currentScore = ptrBoard->getRockValue(0);
            // Add the rocks across to your pile
            ptrBoard->setRockValue(0, currentScore + ptrBoard->getRockValue(14 - selectedPile) + 1);
            ptrBoard->setRockValue(14 - selectedPile, 0);
            ptrBoard->setRockValue(selectedPile, 0);
        }
    }

    // Check whether player gets another turn
    if (player)
    {
        if (selectedPile == 7)
        {
            return true;
        }
        return false;
    }
    else
    {
        if (selectedPile == 0)
        {
            return false;
        }
        return true;
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