#include "NQueens.hpp"

NQueens::NQueens(void): N(4) {}

NQueens::NQueens(unsigned int num): N(num) {}

NQueens::NQueens(NQueens const & src) { *this = src; }

NQueens::~NQueens(void) {}

NQueens & NQueens::operator=(NQueens const & rhs) {
    if (this != &rhs)
        this->N = rhs.N;
    return (*this);
}

void NQueens::initBoard(void) {
    unsigned int num_row = this->N;
    unsigned int num_col = this->N;

    std::vector<unsigned int> row(num_col, 0);
    std::vector<std::vector<unsigned int>> vec(num_row, row);
    this->board = vec;
}

void NQueens::printSolution(void) {
    std::vector<std::vector<unsigned int>>::iterator i;
    std::vector<unsigned int>::iterator j;

    for (i = this->board.begin(); i < this->board.end(); i++) {
        for (j = i->begin(); j != i->end(); j++)
            std::cout << *j << " ";
        std::cout << std::endl;
    }

    //An easier alternative:
    // for(int i = 0 ; i < this->board.size(); i++){
	// 	for(int j = 0; j < this->board[i].size(); j++)
	// 		std::cout << this->board[i][j] << " ";
	// 	std::cout << std::endl;
	// }
}

bool NQueens::isSafe(int row, int col) {
    int i;
    int j;
    
    //checking the row on the left side:
    for (i = 0; i < col; i++) {
        if (this->board[row][i])
            return false;
    }

    //Alternative:
    // std::vector<std::vector<unsigned int>>::iterator i;
    // std::vector<unsigned int>::iterator j;

    // for (i = this->board.begin(); i < this->board.end(); i++) {
    //     for (j = i->begin(); j != i->end(); j++) {
    //         if (*j)
    //             return false;
    //     }
    // }
    
    //checking upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (this->board[i][j])
            return false;
    }

    //checking lower left diagonal
    for (i = row, j = col; j >= 0 && i < static_cast<int>(this->N); i++, j--) {
        if (this->board[i][j])
            return false;
    }
    return true;
}

bool NQueens::solveNQueens(int col){
    if (col >= static_cast<int>(this->N))
        return true;
    for (int i = 0; i < static_cast<int>(this->N); i++) {
        if (isSafe(i, col)) {
            this->board[i][col] = 1;
            if (solveNQueens(col + 1))
                return true;
            this->board[i][col] = 0; // here we backtrack
        }
    }
    return false;
}