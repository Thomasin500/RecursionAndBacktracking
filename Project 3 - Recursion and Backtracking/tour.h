#pragma once

#include <vector>

using namespace std;

class tour {

public:
	//TODO need to add constructor
	bool initialKTsol(int height, int width);
	
	void printSolution(int **sol, int height, int width);

	int isSafe(int ** sol, int x, int y, int height, int width);

	bool solveKTUtil(int ** sol, int height, int width, int x, int y, int movei);

	bool solveKT(int height, int width, int startx, int starty);

	int solveKTUtilAll(int ** sol, int height, int width, int x, int y, int movei, int &solcount);

	void solveKTAll(int height, int width, int startx, int starty);

	int **KTsol;

	vector<int*> solutions;

	//array which represents the movement in (x,y)
	//ex: (2, -1) would move to the right 2 places and down one place
	int move[2] = { 0,0 };

	int possibleXMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	int possibleYMoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	int pairs[8][2] = { {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1} };

	
	//8 different pairs
	//40320 different permutations

};