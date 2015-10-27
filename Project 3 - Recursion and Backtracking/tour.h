#pragma once

class tour {

	bool initialKTsol(int height, int width);

	void printSolution(int **sol, int height, int width);

	int isSafe(int ** sol, int x, int y, int height, int width);

	bool solveKTUtil(int ** sol, int height, int width, int x, int y, int movei);

	bool solveKT(int height, int width, int startx, int starty);

	int solveKTUtilall(int ** sol, int height, int width, int x, int y, int movei, int solcount);

	void solveKTall(int height, int width, int startx, int starty);

};