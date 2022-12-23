#include "NQueens.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Please enter one argument only !" << std::endl;
        return (1);
    }
    unsigned int arg = std::stoi(av[1]);
    NQueens game(arg);
    
    if (game.N < 3) {
        std::cout << "There is no possible solution !" << std::endl;
    }
    game.initBoard();
    if (game.solveNQueens(0) == false) {
        std::cout << "No solution could be found." << std::endl;
        return (1);
    }
    std::cout << "Hereby is one of the possible solutions for the N Queens problem:" << std::endl;
    game.printSolution();
    return (0);
} 