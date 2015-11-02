#pragma once 

///////////////////////////////////
//	Thomas Freeman
//	Data Structures Project 3 - Recursion and Backtracking
///////////////////////////////////

#include "tour.h"
#include "permutations.h"

using namespace std;

int arraySize = 3;

void testSubProject1() {

	permutations<int> perm;

	cout << "5! should be 120 and 7! should be 5040: " << endl;

	long fact1 = perm.factorial(5);

	long fact2 = perm.factorial(7);

	cout << "5! equals: " << fact1 << endl;
	cout << "7! equals: " << fact2 << endl << endl;

	cout << "An array contains the values [1, 2, 3] and should be outputted as 1 2 3 : " << endl;
	
	int arrayy[3] = { 1,2,3 };

	perm.outputArray(arrayy, 3, cout);


	cout << endl << "***Permutations***" << endl;
	cout << "Array is [1,2,3}:" << endl;
	perm.outputPermutations(arrayy, 0, 3, cout);

	cout << endl << "Subproject 1 Test Completed" << endl;

}

void testSubProject2() {

	int input;

	cout << "Would you like to solve one solution for a given starting point or all solutions? (1 for one solution, 2 for all)" << endl;
	cin >> input;
	cout << endl;

	if (input == 1) {
		
		cout << "Height: 4    Width: 3\nStart X: 0    Start Y: 0" << endl << endl;
		tour kt;
		kt.solveKT(4, 3, 0, 0);
	}
	if (input == 2) {

		cout << "Height: 3    Width: 7\nStart X: 0    Start Y: 0" << endl << endl;
		cout << "Should be 8 solutions" << endl;
		cout << "testing all solutions..." << endl; 

		tour kt;
		kt.solveKTAll(3, 7, 0, 0);
		//testSubProject2();
	}	
}


int main() {

	int input;

	cout << "Would you like to test sub-project 1 or 2?" << endl;
	cin >> input;
	cout << endl;

	if (input == 1) {

		testSubProject1();
	}
	if (input == 2) {

		testSubProject2();
	} 

/*
	cout << "Height: 4    Width: 3\nStart X: 0    Start Y: 0" << endl << endl;
	cout << "Should be 8 solutions" << endl;
	cout << "testing all solutions..." << endl;

	tour kt;
	kt.solveKTAll(4, 3, 0, 0);

	


	testSubProject2();
	
	cout << "Height: 4    Width: 3\nStart X: 0    Start Y: 0" << endl << endl;
	tour kt;
	kt.solveKT(4, 3, 0, 0);

	*/

	cout << endl << "done";

	cin.ignore();
	
	cin.ignore();
	cin.ignore();


	return 0;
}