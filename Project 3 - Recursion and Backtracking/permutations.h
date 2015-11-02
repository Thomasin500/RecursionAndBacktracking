#pragma once

//Permutations Class
//This class is used to display each permutation of a given array as well as calculate factorials
//It takes as an input the array to be permutated as well as its size
//output is each permutation of the array
//tested with the array [1,2,3]

#include <iostream>

using namespace std;
template <class T>
class permutations {

public:	

	//this function outputs the array items
	template <class T> 
	void outputArray(T* items, const int& size, ostream &out) {
	
		for (int i = 0; i < size; i++) {

			out << items[i] << " ";
		}	

		out << endl;
	}
	/*-----------------------------------------------------------------------
	outputArray

	Precondition:  an array of any data type
	Postcondition: all the array items have been displayed
	-----------------------------------------------------------------------*/

	//calculates the factorial of any integer N
	long factorial(const int& n) {
	
		if (n == 1) {

			return n;
		}
		else {

			return n * factorial(n - 1);
		}
	}
	/*-----------------------------------------------------------------------
	factorial

	Precondition:  integer n
	Postcondition: this function recursively calculates and returns the factorial of the input n 
	-----------------------------------------------------------------------*/
	
	//displays each permutation
	template <class T> 
	void outputPermutations(T* items, int pos, const int& size, ostream& out) {
		
		if (pos == size) {

			//out << "Array is empty" << endl;
			outputArray(items, size, out);
			return;
		}
		else {

			for (int i = pos; i < size; i++) {

				swap(items[i], items[pos]);
				outputPermutations(items, pos + 1, size, out);
				swap(items[i], items[pos]);
			}
		}
	}
	/*-----------------------------------------------------------------------
	outputPermutations

	Precondition:  array of any datatype, the array's size, and the stream to be outputted
	Postcondition: all permuations of the array are outputted
	-----------------------------------------------------------------------*/
};