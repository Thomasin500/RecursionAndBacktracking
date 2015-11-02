#pragma once

#include <vector>

using namespace std;

class tour {

public:
	
	bool initialKTsol(int height, int width);
	/*-----------------------------------------------------------------------
	initialKTsol

	Precondition:  height and width as ints
	Postcondition: initializes a 2d soluton array with -1 in each element
	-----------------------------------------------------------------------*/
	
	void printSolution(int **sol, int height, int width);
	/*-----------------------------------------------------------------------
	printSolution

	Precondition:  solution array sol, ints height and width
	Postcondition: outputs the 2d array sol
	-----------------------------------------------------------------------*/

	int isSafe(int ** sol, int x, int y, int height, int width);
	/*-----------------------------------------------------------------------
	isSafe

	Precondition:  2d array sol, ints x,y,height, and width
	Postcondition: returns a 1 if the x and y cordinates are valid for the given board, 0 otherwise
	-----------------------------------------------------------------------*/

	bool solveKTUtil(int ** sol, int height, int width, int x, int y, int movei);
	/*-----------------------------------------------------------------------
	solveKTUtil (helper function of solveKT)

	Precondition:  2d array sol, ints x, y, width, height, and movei (number of moves so far)
	Postcondition: solves the first solution for the knights tour for the given board
	-----------------------------------------------------------------------*/

	bool solveKT(int height, int width, int startx, int starty);
	/*-----------------------------------------------------------------------
	solveKT

	Precondition:  ints height, width as well as the starting position (startx, starty)
	Postcondition: wrapper function that uses the util to determine a knights tour for the given board, outputs solution if it exists
	-----------------------------------------------------------------------*/

	int solveKTUtilAll(int ** sol, int height, int width, int x, int y, int movei, int &solcount);
	/*-----------------------------------------------------------------------
	solveKTUtilAll (helper function of solveKTAll)

	Precondition:   2d array sol, ints x, y, width, height, movei (number of moves so far), and int solution count
	Postcondition: determines number of solutions for a knights tour for the given starting position and board
	-----------------------------------------------------------------------*/

	void solveKTAll(int height, int width, int startx, int starty);
	/*-----------------------------------------------------------------------
	solveKTUtil

	Precondition:   board of int height and width and starting position startx and starty
	Postcondition: wrapper function that uses the util to determine all the solutions of a knights tour for the given board and start position
	-----------------------------------------------------------------------*/

	//pointer to 2d array KTsol
	int **KTsol;

	//boolean that states whether the current knights tour is solved or not
	bool solved = false;

	//totalmoves in the current knights tour
	int totalMoves = 0;

	//all possible x moves for a knight chess piece
	int possibleXMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	
	//all possible y moves for a knight chess piece
	int possibleYMoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	//all pairs of possible moves for a knight chess piece (x,y)
	int pairs[8][2] = { {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1} };
	
	//8 different pairs
	//40320 different permutations

};