#pragma once

#include "tour.h"
#include <iostream>

using namespace std;
	
//--- Definition of initalKTsol
bool tour::initialKTsol(int height, int width) {

	if (height > 0 && width > 0) { //check that the board is valid

		KTsol = new int*[width]; //creation of 2d array
		for (int i = 0; i < width; i++) {

			KTsol[i] = new int[height];
		}

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {

				KTsol[i][j] = -1; //unvisited
			}
		}

		return true;
	}
	else {

		return false;
	}
}

//--- Definition of printSolution
void tour::printSolution(int **sol, int height, int width) {
	
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {

			cout << KTsol[j][i] << " ";					
		}
		cout << endl;
	}	

	//delete the solution array to avoid memory leaks
	for (int i = 0; i < width; i++) {
		
		delete[] KTsol[i];
	}

	delete[] KTsol;
}

//--- Definition of isSafe
int tour::isSafe(int ** sol, int x, int y, int height, int width) {
	
	if ( (x >= 0 && x < width) && (y >= 0 && y < height) && sol[x][y] == -1) {

		return 1;
	}
	else {

		//cout << x << " " << y << " " << sol[x][y] << endl;
		return 0;
	}		
}

//--- Definition of solveKT
bool tour::solveKT(int height, int width, int startx, int starty) {

	initialKTsol(height, width); //intialize the chess board

	startx = 0; //temp
	starty = 0; //temp

	KTsol[startx][starty] = 0; //temp starting position at (0,0), mark position as visited on the first move (index 0)

	if (solveKTUtil(KTsol, height, width, 0, 0, 1) == true) {

		printSolution(KTsol, height, width);
		return true;
	}
	else {

		cout << "No Possible Solution" << endl;
		return false;
	}
}

//--- Definition of sovleKTUtil
bool tour::solveKTUtil(int ** sol, int height, int width, int x, int y, int movei) {

	if (movei == height*width) return true; //checks if the entire board has been traversed

	else { //keep trying

		int nextX;
		int nextY;

		//try all possible moves
		for (int i = 0; i < 8; i++) {		

			int currentXMove = possibleXMoves[i];
			int currentYMove = possibleYMoves[i];

			nextX = x + currentXMove;
			nextY = y + currentYMove;

			if (isSafe(KTsol, nextX, nextY, height, width) == 1) {

				KTsol[nextX][nextY] = movei;

				if (solveKTUtil(KTsol, height, width, nextX, nextY, movei + 1) == true) {

					return true;
				}
				else {

					KTsol[nextX][nextY] = -1; //solution did not work, reset it and backtrack
				}
			}				
		}
	}
}

//--- Definition of solveKTAll
void tour::solveKTAll(int height, int width, int startx, int starty) {										

	initialKTsol(height, width); //intialize the chess board

	int solCount = 0;
	solveKTUtilAll(KTsol, height, width, 0, 0, 0, solCount);

	/*if (solCount > 0) {

		//TODO print all solutions, should be handled in util
		//printSolution(KTsol, height, width);
		
		return;
	}
	else {

		cout << "No Possible Solution For Starting Point: (" << startx << ", " << starty << ")" << endl << endl;
		return;
	}*/

	return;
}

//--- Definition of solveKTUtilALL
int tour::solveKTUtilAll(int ** sol, int height, int width, int x, int y, int movei, int &solCount) {

	if (isSafe(KTsol, x, y, height, width) == 0) { //check if move is not safe

		return 0;
	}

	if (movei == height * width) {
			
		cout << "Solution Found!" << endl;
		solCount++;
		cout << movei << " " << solCount << endl << endl;
		printSolution(KTsol, height, width);
		initialKTsol(height, width); //reintialize the chess board to find the next solution
		sol = KTsol;
		movei = 1;
		return solCount;
	}	

	KTsol[x][y] = movei; //mark cell as visited

	//try all possible moves
	for (int i = 0; i < 8; i++) {

		int currentXMove = possibleXMoves[i];
		int currentYMove = possibleYMoves[i];

		int nextX = x + currentXMove;
		int nextY = y + currentYMove;

		//works!!!****

		//cout << "movei : " << movei << endl;

		solveKTUtilAll(KTsol, height, width, nextX, nextY, movei + 1, solCount); //call function recursively with new cordinates and move count
	}

	KTsol[x][y] = -1; //mark cell as not visited (backtracking)
}



		

	

