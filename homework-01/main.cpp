/*
* Title: Sorting and Algorithm Efficiency
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 1
* Description: Driver (.cpp) file for the Selection, Merge, Quick, and Radix sort algorithms and their helper functions
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "sorting.h"
using namespace std;

int main() {
	// Testing Question 2 Part C
	// ------------------------------------------------------------------
	int size = 16;
	int* arr = new int[size];
	int compCount = 0;
	int moveCount = 0;
	
	arr[0] = 12;
	arr[1] = 7;
	arr[2] = 11;
	arr[3] = 18;
	arr[4] = 19;
	arr[5] = 9;
	arr[6] = 6;
	arr[7] = 14;
	arr[8] = 21;
	arr[9] = 3;
	arr[10] = 17;
	arr[11] = 20;
	arr[12] = 5;
	arr[13] = 12;
	arr[14] = 14;
	arr[15] = 8;

	cout << "\n---Selection Sort---" << endl;
	cout << "\nThe array before selection sort" << endl;
	displayArray(arr, size);

	selectionSort(arr, size, compCount, moveCount);
	cout << "\nNumber of key comparisons: " << compCount << endl;
	cout << "Number of data moves: " << moveCount << endl;
	
	cout << "\nThe array after selection sort" << endl;
	displayArray(arr, size);

	// ------------------------------------------------------------------

	compCount = 0;
	moveCount = 0;

	arr[0] = 12;
	arr[1] = 7;
	arr[2] = 11;
	arr[3] = 18;
	arr[4] = 19;
	arr[5] = 9;
	arr[6] = 6;
	arr[7] = 14;
	arr[8] = 21;
	arr[9] = 3;
	arr[10] = 17;
	arr[11] = 20;
	arr[12] = 5;
	arr[13] = 12;
	arr[14] = 14;
	arr[15] = 8;

	cout << "\n\n---Merge Sort---" << endl;
	cout << "\nThe array before merge sort" << endl;
	displayArray(arr, size);

	mergeSort(arr, size, compCount, moveCount);
	cout << "\nNumber of key comparisons: " << compCount << endl;
	cout << "Number of data moves: " << moveCount << endl;

	cout << "\nThe array after merge sort" << endl;
	displayArray(arr, size);

	// ------------------------------------------------------------------

	compCount = 0;
	moveCount = 0;

	arr[0] = 12;
	arr[1] = 7;
	arr[2] = 11;
	arr[3] = 18;
	arr[4] = 19;
	arr[5] = 9;
	arr[6] = 6;
	arr[7] = 14;
	arr[8] = 21;
	arr[9] = 3;
	arr[10] = 17;
	arr[11] = 20;
	arr[12] = 5;
	arr[13] = 12;
	arr[14] = 14;
	arr[15] = 8;

	cout << "\n\n---Quick Sort---" << endl;
	cout << "\nThe array before quick sort" << endl;
	displayArray(arr, size);

	quickSort(arr, size, compCount, moveCount);
	cout << "\nNumber of key comparisons: " << compCount << endl;
	cout << "Number of data moves: " << moveCount << endl;

	cout << "\nThe array after quick sort" << endl;
	displayArray(arr, size);

	// ------------------------------------------------------------------

	compCount = 0;
	moveCount = 0;

	arr[0] = 12;
	arr[1] = 7;
	arr[2] = 11;
	arr[3] = 18;
	arr[4] = 19;
	arr[5] = 9;
	arr[6] = 6;
	arr[7] = 14;
	arr[8] = 21;
	arr[9] = 3;
	arr[10] = 17;
	arr[11] = 20;
	arr[12] = 5;
	arr[13] = 12;
	arr[14] = 14;
	arr[15] = 8;

	cout << "\n\n---Radix Sort---" << endl;
	cout << "\nThe array before radix sort" << endl;
	displayArray(arr, size);

	radixSort(arr, size);
	cout << "\nThe array after radix sort" << endl;
	displayArray(arr, size);
	cout << endl << endl;

	delete [] arr; // Deallocating the space taken by arr

	// End of Testing Question 2 Part C
	// ------------------------------------------------------------------


	// Testing Question 2 Part D
	// ------------------------------------------------------------------

	performanceAnalysis();

	// End of Testing Question 2 Part D
	// ------------------------------------------------------------------

	return 0;
}