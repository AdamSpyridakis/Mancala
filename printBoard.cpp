#include "ASCIIBoard/printBoard.h"

// Prints the board using ASCII characters
void printBoard(board *ptr)
{
    std::cout << "|    ";
    for (int i{1}; i < 7; i++)
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
    if (ptr->getRockValue(0) < 10)
    {
        std::cout << "0";
    }
    std::cout << ptr->getRockValue(0) << " |";
    for (int i{}; i < 29; i++)
    {
        std::cout << '-';
    }
    std::cout << "| ";
    if (ptr->getRockValue(7) < 10)
    {
        std::cout << "0";
    }
    std::cout << ptr->getRockValue(7) << " |\n" << "|    ";
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
    std::cout << "|    |";
}
