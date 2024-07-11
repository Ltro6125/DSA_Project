#pragma once

#ifndef Sort_H
#define Sort_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>


using namespace std;


//Selection Sort 
void compareSeLectionSort(int* a, int n, long long& count_compare);
void runningTimeSelectionSort(int* a, int n, double& runningTime);

//Shaker Sort
void compareShakerSort(int* arr, int n, long long& count_compare);
void runningTimeShakerSort(int* arr, int n, double& runningTime);

//Counting Sort
void compareCountingSort(int* a, int n, long long& count_compare);
void runningTimeCountingSort(int* a, int n, double& runningTime);

//Insertion Sort
void compareInsertionSort(int* a, int n, long long& count_compare);
void runningTimeInsertionSort(int* a, int n, double& runningTime);

//Shell Sort
void compareShellSort(int* a, int n, long long& count_compare);
void runningTimeShellSort(int* a, int n, double& runningTime);

//Quick Sort
int ComparePartition(int* a, int low, int high, long long& count_compare);
int Partition(int* a, int low, int high);
void quickSort(int* a, int low, int high, long long& count_compare);
void quickSortNoCompare(int* a, int low, int high);
void compareQuickSort(int* a, int low, int high, long long& count_compare);
void runningTimeQuickSort(int* a, int low, int high, double& runningTime);


// Bubble Sort
void swap(int& x, int& y);
void compareBubbleSort(int* a, int n, long long& count_compare);
void runningTimeBubbleSort(int* a, int n, double& runningTime);


// Heap Sort


void compareHeapify(int* a, int n, int i, long long& count_compare);
void compareHeapSort(int* a, int n, long long& count_compare);

void runningTimeHeapify(int* a, int n, int i);
void runningTimeHeapSort(int* a, int n, double& runningTime);



// Merge Sort

void compareMerge(int* a, int left, int mid, int right, long long& count_compare);
void compareMergeSortHelper(int* a, int left, int right, long long& count_compare);
void compareMergeSort(int* a, int n, long long& count_compare);


void runningTimeMerge(int* a, int left, int mid, int right);
void runningTimeMergeSortHelper(int* a, int left, int right);
void runningTimeMergeSort(int* a, int n, double& runningTime);


void outputArray(int* a, int n);

// Radix Sort
void compareRadixSort(int* a, int n, long long& count_compare);
void runningTimeRadixSort(int* a, int n, double& runningTime);

//Flash Sort
void compareFlashSort(int* a, int n, long long& count_compare);
void runningTimeFlashSort(int* a, int n, double& runningTime);




#endif