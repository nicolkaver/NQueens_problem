#ifndef NQUEENS_HPP
# define NQUEENS_HPP

# include <iostream>
# include <string>
# include <vector>
# include <bits/stdc++.h>

class NQueens {
public:
    NQueens();
    NQueens(unsigned int);
    NQueens(NQueens const &);
    ~NQueens();
    NQueens & operator=(NQueens const &);

    void initBoard();
    void printSolution();
    bool isSafe(int, int);
    bool solveNQueens(int);

    unsigned int N;
    std::vector<std::vector<unsigned int > > board;
};

#endif