#include "..//ASCIIBoard/printBoard.h"

// Prints the board using ASCII characters
void printBoard(board *ptr)
{
    // Make the indices for the top - to let players know what pile they select
    std::cout << "       ";
    for (char letter{70}; letter > 64; letter--)
    {
        std::cout << letter << letter << "   ";
    }
    // Begin printing the board
    std::cout << "\n|    ";
    for (int i{6}; i > 0; i--)
    {
        std::cout << "| ";
        // print 0 if less than 10 for formatting - see boardClass.h for example
        if (ptr->getRockValue(i) < 10)
        {
            std::cout << "0";
        }
        std::cout << ptr->getRockValue(i);
        std::cout << " ";
    }
    std::cout << "|    |\n"
              << "| ";
    if (ptr->getRockValue(7) < 10)
    {
        std::cout << "0";
    }
    std::cout << ptr->getRockValue(7) << " |";
    for (int i{}; i < 29; i++)
    {
        std::cout << '-';
    }
    std::cout << "| ";
    if (ptr->getRockValue(0) < 10)
    {
        std::cout << "0";
    }
    std::cout << ptr->getRockValue(0) << " |\n"
              << "|    ";
    for (int i{8}; i < 14; i++)
    {
        std::cout << "| ";
        // print 0 if less than 10 for formatting - see boardClass.h for example
        if (ptr->getRockValue(i) < 10)
        {
            std::cout << "0";
        }
        std::cout << ptr->getRockValue(i);
        std::cout << " ";
    }
    std::cout << "|    |\n";
    // Make the indices for the bottom
    std::cout << "       ";
    for (char letter{71}; letter < 77; letter++)
    {
        std::cout << letter << letter << "   ";
    }
}

// Send a move request to the terminal
int getMove(bool player, board *ptr)
{
    char index{0};
    bool movecheck{true};
    int numberValue;
    if (player)
    {
        // check that it's a valid move
        while (movecheck)
        {
            std::cout << "\nPlayer 1: Enter a rock index: ";
            std::cin >> index;
            if ((index >= 65 && index <= 70) && ptr->getRockValue(index - 64) > 0)
            {
                movecheck = false;
                numberValue = index - 64;
            }
            // Quit if 'Q'
            else if (index == 81)
            {
                return -1;
            }
            else
            {
                std::cout << "Invalid move. Try again";
            }
        }
    }
    else
    {
        while (movecheck)
        {
            std::cout << "\nPlayer 2: Enter a rock index: ";
            std::cin >> index;
            if ((index >= 71 && index <= 76) && (ptr->getRockValue(index - 63) > 0))
            {
                movecheck = false;
                numberValue = index - 63;
            }
            // Quit if 'Q'
            else if (index == 81)
            {
                return -1;
            }
            else
            {
                std::cout << "Invalid move. Try again";
            }
        }
    }
    return numberValue;
}

void checkWinner(board* ptr) {
    if(ptr->getRockValue(7) > ptr->getRockValue(0)) {
        std::cout << "\nPlayer 1 wins!";
    }
    else if(ptr->getRockValue(0) > ptr->getRockValue(7)) {
        std::cout << "\nPlayer 1 wins!";
    }
    else {
        std::cout << "It's a draw!";
    }
}