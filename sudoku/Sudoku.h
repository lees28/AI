// Name: Soo Lee
// Vunetid: lees28
// email : soo.yeon.lee@vanderbilt.edu
// Class: CS 270
// Project 1 - Sudoku Solver
// Sep. 2016
// honor statement : I have not gained help on this assignment.


#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>


class Sudoku {
private:
	int row = 9; //size of row 
	int col = 9; //size of column
	int sudoku_board[9][9]; //default matrix of the sudoku board with a size of 9 x 9

public:

	// constructors
	Sudoku();    // default ctor that initializes the board 

	void loadFromFile(std::string filename);	

	void print() const;

	bool equals(const Sudoku &other) const;

	bool solve(int r, int c);

	bool isSolved();

	int valid(int r, int c, int val);
};
#endif
