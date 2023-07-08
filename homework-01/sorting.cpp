/*
* Title: Sorting and Algorithm Efficiency
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 1
* Description: Implementation (.cpp) file for the Selection, Merge, Quick, and Radix sort algorithms and their helper functions
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "sorting.h"
using namespace std;



// Implementation of Selection sort algorithm
void selectionSort(int* arr, const int size, int& compCount, int& moveCount) {
	int maxIndex;
	int temp;
	compCount = 0;
	moveCount = 0;

	for (int i = size - 1; i >= 1; i--) {
		maxIndex = findMaxIndex(arr, i + 1, compCount);

		temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
		moveCount = moveCount + 3; // In each iteration there is 3 data moves
	}
}

// Helper function for the selection sort algorithm
int findMaxIndex(const int* arr, const int size, int& compCount) {
	int index = 0;

	for (int i = 1; i < size; i++) {

		compCount++; // In each iteration there is 1 comparison
		if (arr[i] > arr[index]) {
			index = i;
		}
	}

	return index;
}




// Merge function of the merge sort
void merge(int* arr, const int first, const int mid, const int last, int& compCount, int& moveCount) {
	// Since the first and last addresses can be any index of the original array we cant just consider them as 0 and size - 1
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	// But since we allocate the new temp array which has a size same as the to be merged part of the original array
	// But index of the temp must start at 0 because it is not related with the indexes of the subarrays (It just keep the sorted numbers)
	int tempIndex = 0;
	int sizeOfTemp = last - first + 1;
	int* temp = new int[sizeOfTemp];

	// First add the numbers to the temp until one of them is empty
	while (first1 <= last1 && first2 <= last2) {

		compCount++;
		if (arr[first1] < arr[first2]) {
			temp[tempIndex] = arr[first1];
			first1++;
			moveCount++;
		}

		else {
			temp[tempIndex] = arr[first2];
			first2++;
			moveCount++;
		}

		tempIndex++;
	}

	// Handling the remaining elements of an array
	while (first1 <= last1) {
		temp[tempIndex] = arr[first1];

		first1++;
		tempIndex++;
		moveCount++;
	}

	while (first2 <= last2) {
		temp[tempIndex] = arr[first2];

		first2++;
		tempIndex++;
		moveCount++;
	}

	tempIndex = 0; // Set temp to 0 again to iterate through all the elements of it

	// Copying the sorted array back into the original array
	for (int i = first; i <= last; i++, tempIndex++) {
		arr[i] = temp[tempIndex];
		moveCount++;
	}

	// Deallocate the temp memory
	delete[] temp;
}

// Recursive implementation of the merge sort algorithm
void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount) {
	if (first < last) {
		int mid = (first + last) / 2; // Divide

		mergeSort(arr, first, mid, compCount, moveCount); // Conquer
		mergeSort(arr, mid + 1, last, compCount, moveCount); // Conquer
		merge(arr, first, mid, last, compCount, moveCount); // Combine
	}
}

// Helper function of the recursive merge sort
void mergeSort(int* arr, const int size, int& compCount, int& moveCount) {
	int first = 0;
	int last = size - 1;
	compCount = 0;
	moveCount = 0;

	mergeSort(arr, first, last, compCount, moveCount);
}




// Partition function of the quick sort algoritm
void partition(int* arr, const int first, const int last, int& pivotIndex, int& compCount, int& moveCount) {
	int pivot = arr[first]; // Choosing the first array element as the pivot
	moveCount++;

	int lastS1 = first;
	int firstUnknown = first + 1;

	for (; firstUnknown <= last; firstUnknown++) {

		compCount++;
		if (arr[firstUnknown] < pivot) { // The ones that go into S1
			lastS1++;

			// Swapping
			int temp = arr[lastS1];
			arr[lastS1] = arr[firstUnknown];
			arr[firstUnknown] = temp;

			moveCount = moveCount + 3;
		}
		// If it is in S2 just increment the firstUnknown in the loop update
	}

	// Put pivot into its proper place
	arr[first] = arr[lastS1];
	arr[lastS1] = pivot;
	moveCount = moveCount + 2;

	// Return the index of pivot
	pivotIndex = lastS1;
}

// Recursive Quick Sort algorithm
void quickSort(int* arr, int first, int last, int& compCount, int& moveCount) {
	int pivotIndex;

	if (first < last) {
		partition(arr, first, last, pivotIndex, compCount, moveCount); // Partition the array into S1 and S2

		// Sort S1 and S2 recursively
		quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
		quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
	}
}

// Helper function of the quick sort algorithm
void quickSort(int* arr, const int size, int& compCount, int& moveCount) {
	int first = 0;
	int last = size - 1;
	compCount = 0;
	moveCount = 0;

	quickSort(arr, first, last, compCount, moveCount);
}




// Function that finds the maximum digit number in an array
int findMaxDigit(int* arr, const int size) {
	// First find the max number in the array
	int max = arr[0];
	int count = 0;

	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	// Find the digit count of the max number
	while (max > 0) {
		count++;
		max = max / 10;
	}

	return count;
}

// Radix Sort algorithm (Only for positive ???)
void radixSort(int* arr, const int size) {
	// Get the max digit count
	int digitCount = findMaxDigit(arr, size);

	// Initialize the groups of each digit with size
	int** groups = new int* [10];

	for (int i = 0; i < 10; i++) {
		groups[i] = new int[size];
	}

	// Initialize 10 counters for each group
	int* counters = new int[10];
	for (int i = 0; i < 10; i++) {
		counters[i] = 0;
	}


	int pos, remainder, curNum, iter = 0;
	for (int i = 1; i <= digitCount; i++) { // Iterate for each digit
		pos = (int)pow(10, i - 1);

		// Place the items to their proper groups
		for (int j = 0; j < size; j++) {
			curNum = arr[j];
			remainder = (curNum / pos) % 10;
			groups[remainder][counters[remainder]] = curNum;

			counters[remainder]++;
		}

		// Fill the original array with the items in the groups
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < counters[j]; k++) {
				arr[iter++] = groups[j][k];
			}
		}

		// Resetting all the iterators to 0 including the original arrays iterator
		for (int a = 0; a < 10; a++) {
			counters[a] = 0;
		}
		iter = 0;
	}

	// Deallocating the used memory
	delete[] counters;

	for (int i = 0; i < 10; i++) {
		delete[] groups[i];
	}
	delete[] groups;
}


void displayArray(const int* arr, const int size) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}


void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
	// Declaring the arrays
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	int num;

	// Filling the array with random numbers that randomly distibuted
	for (int i = 0; i < size; i++) {
		num = (rand() % 100) + 1;

		arr1[i] = num;
		arr2[i] = num;
		arr3[i] = num;
		arr4[i] = num;
	}
}

void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
	// Declaring the arrays
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	int num;
	int temp1;
	int temp2;

	// Filling the array with random numbers that randomly distibuted
	for (int i = 0; i < size; i++) {
		num = (rand() % 100) + 1;

		arr1[i] = num;
		arr2[i] = num;
		arr3[i] = num;
		arr4[i] = num;
	}

	// Ordering the array in ascending order
	mergeSort(arr1, size, temp1, temp2);
	mergeSort(arr2, size, temp1, temp2);
	mergeSort(arr3, size, temp1, temp2);
	mergeSort(arr4, size, temp1, temp2);
}

void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
	// Declaring the arrays
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	int num;
	int temp1;
	int temp2;

	// Filling the array with random numbers that randomly distibuted
	for (int i = 0; i < size; i++) {
		num = (rand() % 100) + 1;

		arr1[i] = num;
		arr2[i] = num;
		arr3[i] = num;
		arr4[i] = num;
	}

	// Ordering the array in descending order
	mergeSortReverse(arr1, size, temp1, temp2);
	mergeSortReverse(arr2, size, temp1, temp2);
	mergeSortReverse(arr3, size, temp1, temp2);
	mergeSortReverse(arr4, size, temp1, temp2);
}

// Merge function of the merge sort
void mergeReverse(int* arr, const int first, const int mid, const int last, int& compCount, int& moveCount) {
	// Since the first and last addresses can be any index of the original array we cant just consider them as 0 and size - 1
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	// But since we allocate the new temp array which has a size same as the to be merged part of the original array
	// But index of the temp must start at 0 because it is not related with the indexes of the subarrays (It just keep the sorted numbers)
	int tempIndex = 0;
	int sizeOfTemp = last - first + 1;
	int* temp = new int[sizeOfTemp];

	// First add the numbers to the temp until one of them is empty
	while (first1 <= last1 && first2 <= last2) {

		compCount++;
		if (arr[first1] > arr[first2]) {
			temp[tempIndex] = arr[first1];
			first1++;
			moveCount++;
		}

		else {
			temp[tempIndex] = arr[first2];
			first2++;
			moveCount++;
		}

		tempIndex++;
	}

	// Handling the remaining elements of an array
	while (first1 <= last1) {
		temp[tempIndex] = arr[first1];

		first1++;
		tempIndex++;
		moveCount++;
	}

	while (first2 <= last2) {
		temp[tempIndex] = arr[first2];

		first2++;
		tempIndex++;
		moveCount++;
	}

	tempIndex = 0; // Set temp to 0 again to iterate through all the elements of it

	// Copying the sorted array back into the original array
	for (int i = first; i <= last; i++, tempIndex++) {
		arr[i] = temp[tempIndex];
		moveCount++;
	}

	// Deallocate the temp memory
	delete[] temp;
}

// Recursive implementation of the merge sort algorithm
void mergeSortReverse(int* arr, int first, int last, int& compCount, int& moveCount) {
	if (first < last) {
		int mid = (first + last) / 2; // Divide

		mergeSortReverse(arr, first, mid, compCount, moveCount); // Conquer
		mergeSortReverse(arr, mid + 1, last, compCount, moveCount); // Conquer
		mergeReverse(arr, first, mid, last, compCount, moveCount); // Combine
	}
}

// Helper function of the recursive merge sort
void mergeSortReverse(int* arr, const int size, int& compCount, int& moveCount) {
	int first = 0;
	int last = size - 1;
	compCount = 0;
	moveCount = 0;

	mergeSortReverse(arr, first, last, compCount, moveCount);
}

void performanceAnalysis() {
	
	int initial = 6000;
	int incrementVal = 4000;
	int size;
	clock_t timer; // timer for the elapsed time calculation

	int* arr1 = NULL;
	int* arr2 = NULL;
	int* arr3 = NULL;
	int* arr4 = NULL;

	// elapsedTimeArr hold the elapsed times of the analysis. First 28 element holds the reports of random order, next 28 element for increasing and last 28 for decreasing order
	// In each of the 28 elements, first 7 element holds the values for selection sort in 7 different sizes, and then for mergeSort, quickSort, and radixSort. 
	// For comp and move count Same is valid except they dont have values for radix sort
	double* elapsedTimeArr = new double[84]; 
	int* compCountArr = new int[63]; 
	int* moveCountArr = new int[63];


	// Recording the Data
	incrementVal = 4000;
	// Making the analysis for the randomly ordered array
	for (int i = 0; i < 7; i++) {
		size = initial + (incrementVal * i);
		createRandomArrays(arr1, arr2, arr3, arr4, size);

		// For selection sort
		timer = clock();
		selectionSort(arr1, size, compCountArr[0 + i], moveCountArr[0 + i]);
		elapsedTimeArr[0 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For merge sort
		timer = clock();
		mergeSort(arr2, size, compCountArr[7 + i], moveCountArr[7 + i]);
		elapsedTimeArr[7 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For quick sort
		timer = clock();
		quickSort(arr3, size, compCountArr[14 + i], moveCountArr[14 + i]);
		elapsedTimeArr[14 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For radix sort
		timer = clock();
		radixSort(arr4, size);
		elapsedTimeArr[21 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;

		arr1 = NULL;
		arr2 = NULL;
		arr3 = NULL;
		arr4 = NULL;
	}


	incrementVal = 4000;
	// Making the analysis for the ascendingly ordered array
	for (int i = 0; i < 7; i++) {
		size = initial + (incrementVal * i);
		createAscendingArrays(arr1, arr2, arr3, arr4, size);

		// For selection sort
		timer = clock();
		selectionSort(arr1, size, compCountArr[21 + i], moveCountArr[21 + i]);
		elapsedTimeArr[28 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For merge sort
		timer = clock();
		mergeSort(arr2, size, compCountArr[21 + 7 + i], moveCountArr[21 + 7 + i]);
		elapsedTimeArr[28 + 7 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For quick sort
		timer = clock();
		quickSort(arr3, size, compCountArr[21 + 14 + i], moveCountArr[21 + 14 + i]);
		elapsedTimeArr[28 + 14 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;
		
		// For radix sort
		timer = clock();
		radixSort(arr4, size);
		elapsedTimeArr[28 + 21 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;

		arr1 = NULL;
		arr2 = NULL;
		arr3 = NULL;
		arr4 = NULL;
	}


	incrementVal = 4000;
	// Making the analysis for the descending ordered array
	for (int i = 0; i < 7; i++) {
		size = initial + (incrementVal * i);
		createDescendingArrays(arr1, arr2, arr3, arr4, size);

		// For selection sort
		timer = clock();
		selectionSort(arr1, size, compCountArr[42 + i], moveCountArr[42 + i]);
		elapsedTimeArr[56 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For merge sort
		timer = clock();
		mergeSort(arr2, size, compCountArr[42 + 7 + i], moveCountArr[42 + 7 + i]);
		elapsedTimeArr[56 + 7 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		// For quick sort
		timer = clock();
		quickSort(arr3, size, compCountArr[42 + 14 + i], moveCountArr[42 + 14 + i]);
		elapsedTimeArr[56 + 14 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;
		
		// For radix sort
		timer = clock();
		radixSort(arr4, size);
		elapsedTimeArr[56 + 21 + i] = 1000 * double(clock() - timer) / CLOCKS_PER_SEC;

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;

		arr1 = NULL;
		arr2 = NULL;
		arr3 = NULL;
		arr4 = NULL;
	}

	// Displaying the recorded datas

	// Displaying the randomly ordered data
	cout << "-----Performing Analysis on Randomly Ordered Arrays-----" << endl << endl;

	int printCount = 0;
	for (int i = 0; i < 28; i++) {
		if (i == 0) {
			cout << "--------------------------------------------------------" << endl;
			cout << "Analysis of Selection Sort" << endl;
		}
		if (i == 7) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Merge Sort" << endl;
		}
		if (i == 14) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Quick Sort" << endl;
		}
		if (i == 21) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Radix Sort" << endl;
		}
		if (i % 7 == 0) {
			printCount = 0;
			cout.width(15); cout << left << "Array Size";
			cout.width(15); cout << left << "Elapsed Time";
			if (i <= 20) {
				cout.width(15); cout << left << "compCount";
				cout.width(15); cout << left << "moveCount";
			}
			cout << endl;
		}


		cout.width(15); cout << left << initial + (printCount * incrementVal);

		cout.width(6); cout << left << elapsedTimeArr[i];
		cout.width(9); cout << left << "ms";
		if (i <= 20) {
			cout.width(15); cout << left << compCountArr[i];
			cout.width(15); cout << left << moveCountArr[i];
		}
		cout << endl;

		printCount++;
	}

	// Displaying the Ascendingly ordered data
	cout << "\n\n-----Performing Analysis on Ascendingly Ordered Arrays-----" << endl << endl;

	printCount = 0;
	for (int i = 28; i < 56; i++) {
		if (i == 28) {
			cout << "--------------------------------------------------------" << endl;
			cout << "Analysis of Selection Sort" << endl;
		}
		if (i == 35) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Merge Sort" << endl;
		}
		if (i == 42) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Quick Sort" << endl;
		}
		if (i == 49) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Radix Sort" << endl;
		}
		if (i % 7 == 0) {
			printCount = 0;
			cout.width(15); cout << left << "Array Size";
			cout.width(15); cout << left << "Elapsed Time";
			if (i <= 48) {
				cout.width(15); cout << left << "compCount";
				cout.width(15); cout << left << "moveCount";
			}
			cout << endl;
		}


		cout.width(15); cout << left << initial + (printCount * incrementVal);

		cout.width(6); cout << left << elapsedTimeArr[i];
		cout.width(9); cout << left << "ms";
		if (i <= 41 + 7) {
			cout.width(15); cout << left << compCountArr[i - 7];
			cout.width(15); cout << left << moveCountArr[i - 7];
		}
		cout << endl;

		printCount++;
	}

	// Displaying the descendingly ordered data
	cout << "\n\n-----Performing Analysis on Descendingly Ordered Arrays-----" << endl << endl;

	printCount = 0;
	for (int i = 56; i < 84; i++) {
		if (i == 56) {
			cout << "--------------------------------------------------------" << endl;
			cout << "Analysis of Selection Sort" << endl;
		}
		if (i == 63) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Merge Sort" << endl;
		}
		if (i == 70) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Quick Sort" << endl;
		}
		if (i == 77) {
			cout << "\n--------------------------------------------------------" << endl;
			cout << "Analysis of Radix Sort" << endl;
		}
		if (i % 7 == 0) {
			printCount = 0;
			cout.width(15); cout << left << "Array Size";
			cout.width(15); cout << left << "Elapsed Time";
			if (i <= 76) {
				cout.width(15); cout << left << "compCount";
				cout.width(15); cout << left << "moveCount";
			}
			cout << endl;
		}


		cout.width(15); cout << left << initial + (printCount * incrementVal);

		cout.width(6); cout << left << elapsedTimeArr[i];
		cout.width(9); cout << left << "ms";
		if (i <= 62 + 14) {
			cout.width(15); cout << left << compCountArr[i - 14];
			cout.width(15); cout << left << moveCountArr[i - 14];
		}
		cout << endl;

		printCount++;
	}
	cout << "--------------------------------------------------------" << endl;
	// End of the Analysis

	// Deallocating the memory taken by the arrays that keep the results
	delete [] elapsedTimeArr;
	delete [] compCountArr;
	delete [] moveCountArr;

}