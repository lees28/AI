// Name: Soo Lee
// Vunetid: lees28
// email : soo.yeon.lee@vanderbilt.edu
// Class: CS 270
// Project 1 - Sudoku Solver
// Sep. 2016
// honor statement : I have not gained help on this assignment.

#ifndef SUDOKU_CPP
#define SUDOKU_CPP

#include "Sudoku.h"
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
using namespace std;

/*
* Default Constructor. Initializes the object (sudoku board) to an empty puzzle (all zeros)
*/
Sudoku::Sudoku() 
{
	// Initialize the sudoku_board matrix by filling in all positions with zeros
	int i = 0;
	while ( i < row * col){
		sudoku_board[i / row][i % col] = 0;
	}
} 
/*
for (int i = 0; i < row ; i++)
{
for (int j = 0; j < col; j++)
{
sudoku_board[i][j] = 0; //assign value 0
}
}
*/

/*
* Reinitializes the object with a new puzzle from the specified
* file. You may assume the input file has the specified format. 
*/
void Sudoku::loadFromFile(string filename)
{
	string line;
	ifstream sudoku(filename, ios::in);
	int i = 0;
	if (!sudoku.is_open())	//if file does not exist, throw exception statement
	 {
		throw std::invalid_argument("Exception opening/reading file!\n");
	 }
	else                    //else if the file exists, use an extractor to extract values 
	 {                      //from the file into the sudoku board
		while (i < row * col)
		 {
			sudoku >> sudoku_board[i / row][i % col]; 
			i++;
		 }
	 }
}


/*
* Prints the current puzzle contents to the screen in a nicely
* formatted manner.
*/
void Sudoku::print() const{
	for (int i = 0; i < row ; i++)
	 {
		if (i % 3 == 0 && i != 0)
		 {
			std::cout << "--------+---------+--------\n" ;
		 }
		for (int j = 0; j < col ; j++)
		 {
			if (j % 3 == 0 && j != 0)
			 {
				std::cout << "| ";
			 }
			if (j == 2 || j == 5)
			 {
				std::cout << sudoku_board[i][j] << " "	;
		     }
			else 
			 {
				std::cout << sudoku_board[i][j] << "  ";
			 }
		 }
		std::cout << std::endl;
	}
}

/*
* Determines if two puzzles are equal
*/
bool Sudoku::equals(const Sudoku &other) const{
	for (int i = 0; i < row; i++)
	 { 
		for (int j = 0; j < col; j++)
		 {
			int tmp = other.sudoku_board[i][j];
			if (sudoku_board[i][j] != tmp)
			 {
				return false;	//return false if elements at same position are different
			 }
		 }
	 }
	return true; //otherwise return false
}


/*
* The entry point for th solver. Returns true if a solution was
* found, otherwise returns false.
*/
bool Sudoku::solve(int r, int c){
	if (r == row)
		return 1;

	if (sudoku_board[r][c] != 0) {
		if (c == 8) {
			return solve(r + 1, 0);
		}
		return solve(r, c + 1);
	}

	for (int val = 1; val <= 9; val++) {
		if (valid(r, c, val)) {
			sudoku_board[r][c] = val;

			if (c == 8) {
				if (solve(r + 1, 0))
					return 1;
			}
			else {
				if (solve(r, c + 1))
					return 1;
			}
		}
	}

	sudoku_board[r][c] = 0;

	return 0;
}

/*
void solve(int r, int c)
{
if(board[r][c] == 0)
{
for(int i = 1; i < 10; i++)
{
if (!inRow(i, r) && !inCol(i, c) && !inSqr(i, r, c))
{
board[r][c] = i;
if(r == 8 && c == 8)
{
printBoard();
System.exit(0);
}
else if(c == 8) solve(r + 1, 0);
else solve(r, c + 1);
}
}
board[r][c] = 0;
}
else if(r == 8 && c == 8)
{
printBoard();
System.exit(0);
}
else if(c == 8)
{
solve(r + 1, 0);
}
else
{
solve(r, c + 1);
}
}
*/


/*
* Function to check whether the sudoku is solved or not. Returns true 
* if there are no zeros in the sudoku board.
*/
bool Sudoku::isSolved(){
	for (int i = 0; i < row; i++)
	 {
		for (int j = 0; j < col; j++)
		 {
			if (sudoku_board[i][j] == 0)
			 {
				return false;
			 }
		 }
	 }
	return true;
	
}

int Sudoku::valid(int r, int c, int val) {
	for (int n = 0; n < row; n++) 
	 {
		if (sudoku_board[n][c] == val || sudoku_board[r][n] == val)
		 {
			return 0;
		 } 
  	 }

	int sRow = (r / 3) * 3;
	int sCol = (c / 3) * 3;

	for (int i = sRow; i < sRow + 3; i++) {
		for (int j = sCol; j < sCol + 3; j++) {
			if (sudoku_board[i][j] == val)
				return 0;
		}
	}

	return 1;
}

#endif
