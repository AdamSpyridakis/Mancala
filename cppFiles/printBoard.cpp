#include "..//ASCIIBoard/printBoard.h"

// Prints the board using ASCII characters
void printBoard(board *ptr)
{
    // Make the indices for the top - to let players know what pile they select
    std::cout << "       ";
    for(char letter{65}; letter<71; letter++){
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
    std::cout << ptr->getRockValue(0) << " |\n" << "|    ";
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
    for(char letter{71}; letter<77; letter++){
        std::cout << letter << letter << "   ";
    }
}
