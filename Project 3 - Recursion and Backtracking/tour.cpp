#pragma once

#include "tour.h"
#include <iostream>

using namespace std;
	
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

	
void tour::printSolution(int **sol, int height, int width) {
	
	int k = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			cout << sol[i][j] << " ";
			k++;

			if (k == width) {

				k = 0;
				cout << endl;
			}
		}
	}	

	//delete the solution array to avoid memory leaks
	for (int i = 0; i < width; i++) {
		
		delete[] sol[i];
	}

	delete[] sol;
}

int tour::isSafe(int ** sol, int x, int y, int height, int width) {
	
	//cout << x << endl << y << endl << height << endl << width << endl << sol[x][y] << endl;

	if ( (x >= 0 && x < width) && (y >= 0 && y < height) && sol[x][y] == -1) {

		return 1;
	}
	else {

		//cout << x << " " << y << " " << sol[x][y] << endl;
		return 0;
	}		
}

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


void tour::solveKTAll(int height, int width, int startx, int starty) {

												 
 //base case is that all possible move solutions have been tried (8! = 40320) ...seems extreme
	//try std::next_permutation on the pairs array?

	//something like while (i < 40320) { give next permutation to the solveKT function, 
	//save each sucessful solution array board, check for duplicates, etc.. }
	//I feel like this would take an extremely long time to compute

	//randomly choose next move...at the very end compare all solutions and if there are duplicates dont count both, only 1 ....i dont think so

	//solveKTUtilall(int ** sol, int height, int width, int x, int y, int movei, int solcount)


	initialKTsol(height, width); //intialize the chess board

	startx = 0; //temp
	starty = 0; //temp

	int solCount = 0;

	KTsol[startx][starty] = 0; //temp starting position at (0,0), mark position as visited on the first move (index 0)

	solveKTUtilAll(KTsol, height, width, 0, 0, 1, solCount);

	if (solCount > 0) {

		//TODO print all solutions, should be handled in util
		//printSolution(KTsol, height, width);
		
		return;
	}
	else {


		cout << "No Possible Solution For Starting Point: (" << startx << ", " << starty << ")" << endl << endl;
		return;

	}



	return;
}

int tour::solveKTUtilAll(int ** sol, int height, int width, int x, int y, int movei, int &solCount) {
	
	/*
	
		if the correct number of moves have been made (h*w) increment the solution count, print the solution, and return, done in this function call

		have a for loop that makes each possible move
		check if the next move is valid, if it is, call this function again with the new cordinates and increment the move count

		at the end of all the function calls return a value based on if a solution was found from thsi starting point
	
	*/
	
	if (movei == height * width) {
			
		cout << "Solution Found!" << endl;
		solCount++;
		cout << movei << " " << solCount << endl << endl;
		printSolution(sol, height, width);
		return 1;
	}

	for (int i = 0; i < 8; i++) {

		int currentXMove = possibleXMoves[i];
		int currentYMove = possibleYMoves[i];

		int nextX = x + currentXMove;
		int nextY = y + currentYMove;

		if (isSafe(sol, nextX, nextY, height, width) == 1) {


			sol[nextX][nextY] = movei; //mark cell as visited

			cout << "marked cell as visited  " << sol[nextX][nextY] << endl;

			if (solveKTUtilAll(sol, height, width, nextX, nextY, movei + 1, solCount) == 1) { //call function recursively with new cordinates and move count

				return 1;
			}
			else {

				sol[nextX][nextY] = -1; //solution did not work, reset it and backtrack
			}
		}
		else {

			return 0;
		}
	}
	
	
	if (solCount > 1) {
		
		return 1;
	}

	else {
		
		return 0;
	}


}



		

	

