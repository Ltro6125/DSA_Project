#include "Sort.h"

//Selection Sort 

void compareSeLectionSort(int* a, int n, long long& count_compare) {
	count_compare = 0;
	// One by one move the boundary of the unsorted subarray
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		// Find the minimum element in the unsorted array
		int minIndex = i;
		for (int j = i + 1; ++count_compare && j < n; j++) {
			if (++count_compare && a[j] < a[minIndex]) {
				minIndex = j; // Update the index of the minimum element
			}
		}
		// Swap the found minimum element with the first element
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;

	}

}

void runningTimeSelectionSort(int* a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();
	// One by one move the boundary of the unsorted subarray
	for (int i = 0; i < n - 1; i++) {
		// Find the minimum element in the unsorted array
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j; // Update the index of the minimum element
			}
		}
		// Swap the found minimum element with the first element
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;

	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}

//Shaker Sort

void compareShakerSort(int* arr, int n, long long& count_compare) {
	count_compare = 0;
	bool swapped = true; // Initialize swapped to true to enter the loop
	int start = 0; // Initialize the starting index
	int end = n - 1; // Initialize the ending index

	// Loop until no elements are swapped in a complete pass
	while (++count_compare && swapped) {
		swapped = false; // Reset swapped to false

		// Traverse the array from left to right
		for (int i = start; ++count_compare && i < end; ++i) {
			// If the current element is greater than the next element, swap them
			if (++count_compare && arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true; // Set swapped to true to indicate a swap has occurred
			}
		}

		// If no elements were swapped, the array is sorted
		if (++count_compare && !swapped) {
			break;
		}

		--end; // Decrease the end index as the largest element is now in place

		swapped = false;  // Reset swapped to false

		// Traverse the array from right to left
		for (int i = end - 1; ++count_compare && i >= start; --i) {
			// If the current element is greater than the next element, swap them
			if (++count_compare && arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true; // Set swapped to true to indicate a swap has occurred
			}
		}

		++start; // Increase the start index as the smallest element is now in place
	}
}


void runningTimeShakerSort(int* arr, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	bool swapped = true; // Initialize swapped to true to enter the loop
	int start1 = 0;  // Initialize the starting index
	int end1 = n - 1; // Initialize the ending index

	// Loop until no elements are swapped in a complete pass
	while (swapped) {
		swapped = false; // Reset swapped to false

		// Traverse the array from left to right
		for (int i = start1; i < end1; ++i) {
			// If the current element is greater than the next element, swap them
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true; // Set swapped to true to indicate a swap has occurred
			}
		}

		// If no elements were swapped, the array is sorted
		if (!swapped) {
			break;
		}

		--end1;  // Decrease the end index as the largest element is now in place

		swapped = false; // Reset swapped to false

		// Traverse the array from right to left
		for (int i = end1 - 1; i >= start1; --i) {
			// If the current element is greater than the next element, swap them
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true; // Set swapped to true to indicate a swap has occurred
			}
		}

		++start1; // Increase the start index as the smallest element is now in place
	}
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}



//Counting Sort

void compareCountingSort(int* a, int n, long long& count_compare) {
	count_compare = 0;

	if (++count_compare && n <= 1) {
		return;
	}
	// Find the maximum element in the array
	int maxVal = -1e9;
	for (int i = 0; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] > maxVal) {
			maxVal = a[i];
		}
	}

	// Create a count array to store count of each element
	int* count = new int[maxVal + 1];

	for (int i = 0; ++count_compare && i <= maxVal; i++) {
		count[i] = 0;
	}


	// Store the count of each element in the count array
	for (int i = 0; ++count_compare && i < n; ++i) {
		++count[a[i]];
	}

	// Modify the count array such that each element at each index stores the sum of previous counts
	for (int i = 1; ++count_compare && i <= maxVal; ++i) {
		count[i] += count[i - 1];
	}

	// Create an output array to store the sorted elements
	int* output = new int[n];

	// Build the output array
	for (int i = n - 1; ++count_compare && i >= 0; --i) {
		output[--count[a[i]]] = a[i];
	}

	// Copy the sorted elements from the output array back to the original array
	for (int i = 0; ++count_compare && i < n; ++i) {
		a[i] = output[i];
	}

	// Copy the sorted elements from the output array back to the original array
	delete[] output;
	delete[] count;
}



void runningTimeCountingSort(int* a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();
	if (n <= 1) return;

	// Find the maximum element in the array
	int maxVal = -1e9;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxVal) {
			maxVal = a[i];
		}
	}

	// Create a count array to store count of each element
	int* count = new int[maxVal + 1];

	for (int i = 0; i <= maxVal; i++) {
		count[i] = 0;
	}


	// Store the count of each element in the count array
	for (int i = 0; i < n; ++i) {
		++count[a[i]];
	}

	// Modify the count array such that each element at each index stores the sum of previous counts
	for (int i = 1; i <= maxVal; ++i) {
		count[i] += count[i - 1];
	}

	// Create an output array to store the sorted elements
	int* output = new int[n];

	// Build the output array
	for (int i = n - 1; i >= 0; --i) {
		output[--count[a[i]]] = a[i];
	}

	// Copy the sorted elements from the output array back to the original array
	for (int i = 0; i < n; ++i) {
		a[i] = output[i];
	}

	// Free the dynamically allocated memory
	delete[] output;
	delete[] count;

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
	// Doan code duoc lay tu nguon chat gpt
}


//Insertion Sort
void compareInsertionSort(int* a, int n, long long& count_compare) {
	count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++) { //iterate through element of array from beginning to end

		int value = a[i]; // value holds value of element a[i]
		int vitri = i - 1; // vitri holds previous position of element a[i]
		while (++count_compare && vitri >= 0 && ++count_compare && a[vitri] > value) {  // this loop shifts previous element to right if it > value
			a[vitri + 1] = a[vitri];  // shifts previous element to right
			vitri--;  // update vitri to check next element
		}
		a[vitri + 1] = value;  // insert value into correct position
	}
}


void runningTimeInsertionSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	for (int i = 1; i < n; i++) { //iterate through element of array from beginning to end

		int value = a[i]; // value holds value of element a[i]
		int vitri = i - 1; // vitri holds previous position of element a[i]
		while (vitri >= 0 && a[vitri] > value) {  // this loop shifts previous element to right if it > value
			a[vitri + 1] = a[vitri];  // shifts previous element to right
			vitri--;  // update vitri to check next element
		}
		a[vitri + 1] = value;  // insert value into correct position
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}






//Shell Sort
void compareShellSort(int* a, int n, long long& count_compare) {
	for (int interval = n / 2; ++count_compare && interval > 0; interval /= 2) { // loop over the intervals
		for (int i = interval; ++count_compare && i < n; i++) {
			int temp = a[i]; // temp holds the value to be compared
			int j;
			for (j = i; ++count_compare && j >= interval && a[j - interval] > temp; j -= interval) {

				a[j] = a[j - interval]; // shift element to make room for temp
			}
			a[j] = temp; // place temp in correct position
		}
	}
}


void runningTimeShellSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	for (int interval = n / 2; interval > 0; interval /= 2) { // loop over the intervals
		for (int i = interval; i < n; i++) {
			int temp = a[i]; // temp holds the value to be compared
			int j;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {

				a[j] = a[j - interval]; // shift element to make room for temp
			}
			a[j] = temp; // place temp in correct position
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}
//Quick Sort
int medianOfThree(int* a, int low, int high) {
	int mid = low + (high - low) / 2;
	int first = a[low];
	int middle = a[mid];
	int last = a[high];

	if ((first > middle) != (first > last)) {
		return low; // first is the median
	}
	else if ((middle > first) != (middle > last)) {
		return mid; // middle is the median
	}
	else {
		return high; // last is the median
	}
}

int ComparePartition(int* a, int low, int high, long long& count_compare) {
	count_compare += 6;
	int pivotIndex = medianOfThree(a, low, high);  // choose the pivot
	swap(a[pivotIndex], a[high]); //swap the pivot to the end
	int pivot = a[high];
	int i = low - 1; // i holds last index of elements that less than pivot
	for (int j = low; ++count_compare && j < high; j++) { //iterates from low to high

		++count_compare;
		if (a[j] <= pivot) {  //check a[j] <= pivot
			i++;   // increase i
			swap(a[i], a[j]);  // swap element less than pivot to the left of pivot
		}

	}
	swap(a[i + 1], a[high]); // swap pivot to correct position

	return i + 1; // return position of pivot
}


int Partition(int* a, int low, int high) {
	int pivotIndex = medianOfThree(a, low, high);  // choose the pivot
	swap(a[pivotIndex], a[high]); //swap the pivot to the end
	int pivot = a[high];
	int i = low - 1; // i holds last index of elements that less than pivot
	for (int j = low; j < high; j++) { //iterates from low to high
		if (a[j] <= pivot) { //check a[j] <= pivot
			i++; // increase i
			swap(a[i], a[j]); // swap element less than pivot to the left of pivot
		}
	}
	swap(a[i + 1], a[high]); // swap pivot to correct position
	return i + 1; // return position of pivot
}


void quickSort(int* a, int low, int high, long long& count_compare) {
	if (low < high) { //check if the subarray has more than one element
		++count_compare;
		int pi = ComparePartition(a, low, high, count_compare); // partition the array and get the pivot index
		quickSort(a, pi + 1, high, count_compare);  // recursive sort the right subarray
		quickSort(a, low, pi - 1, count_compare); // recursive sort the left subarray
	}
	else {
		++count_compare;
	}
}

void quickSortNoCompare(int* a, int low, int high) {
	if (low < high) { //check if the subarray has more than one element
		int pi = Partition(a, low, high);  // partition the array and get the pivot index
		quickSortNoCompare(a, pi + 1, high); // recursive sort the right subarray
		quickSortNoCompare(a, low, pi - 1); // recursive sort the left subarray
	}
}



void compareQuickSort(int* a, int low, int high, long long& count_compare) {
	count_compare = 0;
	quickSort(a, low, high, count_compare);
}


void runningTimeQuickSort(int* a, int low, int high, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();
	quickSortNoCompare(a, low, high);
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}

//Bubble Sort
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void compareBubbleSort(int* a, int n, long long& count_compare) {
	count_compare = 0; // Initialize count_compare to 0

	for (int i = 0; ++count_compare &&  i <= n - 2; i++) { // Iterate through the array elements from the beginning to the second-to-last element
		for (int j = 0; ++count_compare && j <= n - 2 - i; j++) { // Iterate through the unsorted part of the array
			if (++count_compare && a[j + 1] < a[j]) { // Check if the next element is smaller than the current element
				swap(a[j + 1], a[j]); // Swap the elements if they are in the wrong order
			}
		}
	}

}

void runningTimeBubbleSort(int* a, int n, double& runningTime) {
	// Record the start time
	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i <= n - 2; i++) { // Iterate through the array elements from the beginning to the second-to-last element
		for (int j = 0; j <= n - 2 - i; j++) {  // Iterate through the unsorted part of the array
			if ( a[j + 1] < a[j]) { // Check if the next element is smaller than the current element
				swap(a[j + 1], a[j]); // Swap the elements if they are in the wrong order
			}
		}
	}
	// Record the end time
	auto end = std::chrono::high_resolution_clock::now();
	// Calculate the duration of the sorting process
	chrono::duration<double, milli> duration = end - start;
	// Store the running time in milliseconds into the variable runningTime
	runningTime = duration.count();
}

//Heap Sort
void compareHeapify(int* a, int n, int i, long long& count_compare) {
	// Initialize largest as root
	int largest = i;

	// Left and right child indexes
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// Compare left child with root
	if (++count_compare && l < n && ++count_compare && a[l] > a[largest]) 
		largest = l; // Update largest if left child is larger

	// Compare right child with largest so far
	if (++count_compare && r < n && ++count_compare && a[r] > a[largest]) 
		largest = r; // Update largest if right child is larger

	// If largest is not root, swap and recursive heapify the affected sub-tree
	if (++count_compare && largest != i) { 
		swap(a[i], a[largest]);
		compareHeapify(a, n, largest, count_compare);
	}
}

void compareHeapSort(int* a, int n, long long& count_compare) {
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
		compareHeapify(a, n, i, count_compare);

	// One by one extract an element from heap
	for (int i = n - 1; ++count_compare && i > 0; i--) {
		// Move current root to end
		swap(a[0], a[i]);
		// call compareHeapify on the reduced heap
		compareHeapify(a, i, 0, count_compare);
	}
}

void runningTimeHeapify(int* a, int n, int i) {
	// Initialize largest as root
	int largest = i;

	// Left and right child indexes
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// Compare left child with root
	if (l < n && a[l] > a[largest]) 
		largest = l; // Update largest if left child is larger

	// Compare right child with largest so far
	if (r < n && a[r] > a[largest]) 
		largest = r; // Update largest if right child is larger

	// If largest is not root, swap and recursive heapify the affected sub-tree
	if (largest != i) {
		swap(a[i], a[largest]);
		runningTimeHeapify(a, n, largest);
	}
}

void runningTimeHeapSort(int* a, int n, double& runningTime) {

	// Record the start time
	auto start = chrono::high_resolution_clock::now();

	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		runningTimeHeapify(a, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(a[0], a[i]);
		// call compareHeapify on the reduced heap
		runningTimeHeapify(a, i, 0);
	}
	// Record the end time
	auto end = std::chrono::high_resolution_clock::now();
	// Calculate the duration of the sorting process
	chrono::duration<double, milli> duration = end - start;
	// Store the running time in milliseconds into the variable runningTime
	runningTime = duration.count();
}

// Merge Sort



void compareMerge(int* a, int left, int mid, int right, long long& count_compare) {
	int n = right - left + 1; // Calculate the size of the temporary array
	int* temp = new int[n]; // Create a temporary array to store merged elements
	int idx = 0; // Initialize index for the temporary array

	// Initialize indices for the two subarrays
	int i = left, j = mid + 1;

	// Merge the two subarrays into the temporary array
	while (++count_compare && i <= mid && ++count_compare && j <= right)
	{
		// Check if the current element in the left subarray is less than or equal to the current element in the right subarray
		if (++count_compare && a[i] <= a[j]) 
		{
			temp[idx++] = a[i++]; // Place the current element in the left subarray into temp and increment i by 1
		}
		else
		{
			temp[idx++] = a[j++]; // Place the current element in the right subarray into temp and increment j by 1
		}
	}

	// Copy any remaining elements from the left subarray to the temporary array
	while (++count_compare && i <= mid)
	{
		temp[idx++] = a[i++];
	}
	// Copy any remaining elements from the right subarray to the temporary array
	while (++count_compare && j <= right)
	{
		temp[idx++] = a[j++];
	}

	// Copy elements from temporary array back to original array
	for (int i = 0; ++count_compare && i < n; i++)
	{
		a[left + i] = temp[i];
	}

	// Free the dynamically allocated memory
	delete[] temp;
}

void compareMergeSortHelper(int* a, int left, int right, long long& count_compare) {

	// Base case: if left index is greater or equal to right index, return
	if (++count_compare && left >= right) {
		return;
	}
	// Calculate the middle index
	int mid = left + (right - left) / 2;

	// Recursively divide the array into two halves
	compareMergeSortHelper(a, left, mid, count_compare);
	compareMergeSortHelper(a, mid + 1, right, count_compare);

	// Merge the two sorted halves
	compareMerge(a, left, mid, right, count_compare);
}

void compareMergeSort(int* a, int n, long long& count_compare) {
	// Initialize count_compare to 0
	count_compare = 0;

	// Call the compareMergeSortHelper function to start Merge Sort
	compareMergeSortHelper(a, 0, n - 1, count_compare);
}

void runningTimeMerge(int* a, int left, int mid, int right) {
	int n = right - left + 1; // Calculate the size of the temporary array
	int* temp = new int[n]; // Create a temporary array to store merged elements
	int idx = 0; // Initialize index for the temporary array

	// Initialize indices for the two subarrays
	int i = left, j = mid + 1;

	// Merge the two subarrays into the temporary array
	while (i <= mid && j <= right)
	{
		// Check if the current element in the left subarray is less than or equal to the current element in the right subarray
		if (a[i] <= a[j])
		{
			temp[idx++] = a[i++]; // Place the current element in the left subarray into temp and increment i by 1
		}
		else
		{
			temp[idx++] = a[j++]; // Place the current element in the right subarray into temp and increment j by 1
		}
	}

	// Copy any remaining elements from the left subarray to the temporary array
	while (i <= mid)
	{
		temp[idx++] = a[i++];
	}

	// Copy any remaining elements from the right subarray to the temporary array
	while (j <= right)
	{
		temp[idx++] = a[j++];
	}

	// Copy elements from temporary array back to original array
	for (int i = 0; i < n; i++)
	{
		a[left + i] = temp[i];
	}

	// Free the dynamically allocated memory
	delete[] temp;
}

void runningTimeMergeSortHelper(int* a, int left, int right) {
	// Base case: if left index is greater or equal to right index, return
	if (left >= right) {
		return;
	}
	// Calculate the middle index
	int mid = left + (right - left) / 2;

	// Recursively divide the array into two halves
	runningTimeMergeSortHelper(a, left, mid);
	runningTimeMergeSortHelper(a, mid + 1, right);

	// Merge the two sorted halves
	runningTimeMerge(a, left, mid, right);
}

void runningTimeMergeSort(int* a, int n, double& runningTime) {
	// Record the start time
	auto start = chrono::high_resolution_clock::now();

	// Call the runningTimeMergeSortHelper function to start Merge Sort
	runningTimeMergeSortHelper(a, 0, n - 1);

	// Record the end time
	auto end = std::chrono::high_resolution_clock::now();
	// Calculate the duration of the sorting process
	chrono::duration<double, milli> duration = end - start;
	// Store the running time in milliseconds into the variable runningTime
	runningTime = duration.count();
}

// Radix Sort

void compareRadixSort(int* a, int n, long long& count_compare) {

	count_compare = 0;

	int base = ceil(log10(*max_element(a, a + n) + 1)); // Find the number of digits of the max element
	int exp = 1; // Initialize a variable to divide the elements

	// Loops based on base. 
	for (int i = 0; ++count_compare && i < base; i++) {
		vector<vector<int>> result(10); // Create 10 buckets.

		for (int j = 0; ++count_compare && j < n; j++) {
			result[(a[j] / exp) % 10].push_back(a[j]); // Add a[j] to its bucket based on each digit: units, tens, hundreds, thousands,...
		}
		exp *= 10; // Exp multiply by 10 to browse the next digit.

		int index = 0;

		// Copy elements from buckets to the original array
		for (int k = 0; ++count_compare && k < 10; k++) { 
			if (!result[k].empty()) {
				for (int x : result[k]) {
					a[index++] = x;
				}
			}
		}
	}
}

void runningTimeRadixSort(int *a, int n, double& runningTime) {

	auto start = chrono::high_resolution_clock::now();

	int base = ceil(log10(*max_element(a, a + n) + 1)); // Find the number of digits of the max element
	int exp = 1; // Initialize a variable to divide the elements

	// Loops based on base. 
	for (int i = 0; i < base; i++) {
		vector<vector<int>> result(10);
		// Browse n elements.
		for (int j = 0; j < n; j++) {
			result[(a[j] / exp) % 10].push_back(a[j]); // Add a[j] to its bucket based on each digit: units, tens, hundreds, thousands,...
		}
		exp *= 10; // Exp multiply by 10 to browse the next digit.

		int index = 0;

		// Copy elements from buckets to the original array
		for (int k = 0; k < 10; k++) {
			if (!result[k].empty()) {
				for (int x : result[k]) {
					a[index++] = x;
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}



/*
* Idea: Basing on sorting each digit of the integer in descending or ascending, classify the elements according to each digit: units, tens, hundreds, thousands,...
* Step-by-step discription:
* - Finding out the max element, the numbers of digit is the numbers of loop.
* - Classify the elements into 2D array, save the data from 2D array to original array. Repeat until the last digit.
* Complexity: O(d(n + b)) or O(n):
* - n: number of elements.
* - b: base.
* - d: number of digit of the max element.
* This is an algorithm that executes in linear time but it is only suitable with sorting the integers.
*/



//Flash Sort

void compareFlashSort(int* a, int n, long long& count_compare) {

	count_compare = 0;
	// Find max element and min element.

	int maxVal = *max_element(a, a + n);
	int minVal = *min_element(a, a + n);
	int dis = maxVal - minVal; // Calculate the distance between max and min.

	if (minVal == maxVal) return;  // If the distance is 0, stop.

	int bucket = int(0.45 * n); // Calculate the bucket by bucket = 0.45 * n.

	// Create an array to store the positions of the last element in each bucket. 
	int* L = new int[bucket];

	for (int i = 0; ++count_compare && i < bucket; i++) {
		L[i] = 0;
	}

	// Calculate the number of elements in each bucket.
	for (int i = 0; ++count_compare && i < n; i++) {
		int k = (int)((double)(bucket - 1) * (a[i] - minVal) / dis);
		L[k]++;
	}

	// Calculate the positions of the last element in each bucket. 
	for (int i = 1; ++count_compare && i < bucket; i++) {
		L[i] += L[i - 1];
	}

	int count = 0;
	int i = 0;
	// Bring the elements to the correct bucket.
	while (count < n && ++count_compare) {
		int k = (int)((double)(bucket - 1) * (a[i] - minVal) / dis);
		while (i >= L[k] && ++count_compare) {
			k = (int)((double)(bucket - 1) * (a[++i] - minVal) / dis);
		}
		int temp = a[i];
		while (i != L[k] && ++count_compare) {
			k = (int)((double)(bucket - 1) * (a[i] - minVal) / dis);
			// Swap the current element with the last position of the bucket. After that, the last position decreases by 1 unit.
			swap(temp, a[--L[k]]);
			++count;
		}
	}
	delete[] L;  // Deallocate L.
	// Sort each bucket by insertion sort.
	for (int x = 1; ++count_compare && x < n; x++) {
		int key = a[x];
		int y = x - 1;
		while (++count_compare && y >= 0 && ++count_compare && a[y] > key) {
			a[y + 1] = a[y];
			y--;
		}
		a[y + 1] = key;
	}
}


void runningTimeFlashSort(int* a, int n, double& runningTime) {
	auto start = chrono::high_resolution_clock::now();

	// Find max element and min element.
	int maxVal = *max_element(a, a + n);
	int minVal = *min_element(a, a + n);
	int dis = maxVal - minVal;  // Calculate the distance between max and min.

	if (minVal == maxVal) return;  // If the distance is 0, stop.

	int bucket = int(0.45 * n); // Calculate the bucket by bucket = 0.45 * n.
	// Create an array to store the positions of the last element in each bucket. 
	int* L = new int[bucket];
	for (int i = 0; i < bucket; i++) {
		L[i] = 0;
	}

	// Calculate the number of elements in each bucket.
	for (int i = 0; i < n; i++) {
		int k = (int)((double)(bucket - 1) * (a[i] - minVal) / dis);
		L[k]++;
	}

	// Calculate the positions of the last element in each bucket. 
	for (int i = 1; i < bucket; i++) {
		L[i] += L[i - 1];
	}

	int count = 0;
	int i = 0;
	// Bring the elements to the correct bucket.

	while (count < n) {
		int k = (int)((double)(bucket - 1) * (a[i] - minVal) / dis);
		while (i >= L[k]) {
			k = (int)((double)(bucket - 1) * (a[++i] - minVal) / dis);
		}
		int temp = a[i];
		while (i != L[k]) {
			k = (int)((double)(bucket - 1) * (a[i] - minVal) / dis);
			// Swap the current element with the last position of the bucket. After that, the last position decreases by 1 unit.
			swap(temp, a[--L[k]]);
			++count;
		}
	}
	delete[] L; // Deallocate L.
	// Sort each bucket by insertion sort.
	for (int x = 1; x < n; x++) {
		int key = a[x];
		int y = x - 1;
		while (y >= 0 && a[y] > key) {
			a[y + 1] = a[y];
			y--;
		}
		a[y + 1] = key;
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	runningTime = duration.count();
}





void outputArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";

	}
	cout << endl;
}

