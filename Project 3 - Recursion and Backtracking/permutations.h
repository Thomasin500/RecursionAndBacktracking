#pragma once

#include <iostream>

using namespace std;
template <class T>
class permutations {

public:	

	template <class T> 
	void outputArray(T* items, const int& size, ostream &out) {
	
		for (int i = 0; i < size; i++) {

			out << items[i] << " ";
		}	

		out << endl;
	}

	long factorial(const int& n) {
	
		if (n == 1) {

			return n;
		}
		else {

			return n * factorial(n - 1);
		}
	}
	
	//will be n! permutations (n == size of array)
	//TODO***S This function is a little different than the one given in the project description and does not meet all the critieria of it
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
};