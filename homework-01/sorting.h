/*
* Title: Sorting and Algorithm Efficiency
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 1
* Description: Header (.h) file for the Selection, Merge, Quick, and Radix sort algorithms and their helper functions
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// The sorting algorithms that are defined in Question 2 Part A
void selectionSort(int* arr, const int size, int& compCount, int& moveCount);
void mergeSort(int* arr, const int size, int& compCount, int& moveCount);
void quickSort(int* arr, const int size, int& compCount, int& moveCount);
void radixSort(int* arr, const int size);

// Auxiliary functions that are defined in Question 2 Part B
void displayArray(const int* arr, const int size);
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);

// The performance analysis function that is defined in Question 2 Part D
void performanceAnalysis();


// Helper function for selection sort algorithm
int findMaxIndex(const int* arr, const int size, int& compCount);

// Helper function for merge sort algorithm
void merge(int* arr, const int first, const int mid, const int last, int& compCount, int& moveCount);
void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount);

// Helper function for quick sort algorithm
void partition(int* arr, const int first, const int last, int& pivotIndex, int& compCount, int& moveCount);
void quickSort(int* arr, int first, int last, int& compCount, int& moveCount);

// Helper function for radix sort algorithm
int findMaxDigit(int* arr, const int size);

// Helper merge sort function to sort an array in descending order
void mergeSortReverse(int* arr, const int size, int& compCount, int& moveCount);
void mergeReverse(int* arr, const int first, const int mid, const int last, int& compCount, int& moveCount);
void mergeSortReverse(int* arr, int first, int last, int& compCount, int& moveCount);

