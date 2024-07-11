#include "Command.h"

void DisplayOutputParameters(string outputParameters, long long countCompare, double runningTime) {
	
	if (outputParameters == "-time") { // Check if outputParameters is "-time"
		cout << "Running time: " << runningTime << endl;  // Print running time
	}
	else if (outputParameters == "-comp") { // Check if outputParameters is "-comp"
		cout << "Comparisions: " << countCompare << endl; // Print number of comparison
	} 
	else { // If outputParameters is neither "-time" nor "-comp"
		cout << "Running time: " << runningTime << endl;  // Print running time
		cout << "Comparisions: " << countCompare << endl;  // Print number of comparisons
	}
}

void CompareOrRunningTimeSortArray(int*& a, int n, string Algorithm, string outputParameters, long long& countCompare, double& runningTime) {

	if (outputParameters == "-time") { // Check if outputParameters is "-time"
		// Depending on the selected Algorithm, calculate running time
		if (Algorithm == "selection-sort") { 
			runningTimeSelectionSort(a, n, runningTime);
		}
		else if (Algorithm == "shaker-sort") {
			runningTimeShakerSort(a, n, runningTime);
		} 
		else if (Algorithm == "counting-sort") {
			runningTimeCountingSort(a, n, runningTime);
		}
		else if (Algorithm == "insertion-sort") {
			runningTimeInsertionSort(a, n, runningTime);
		}
		else if (Algorithm == "shell-sort") {
			runningTimeShellSort(a, n, runningTime);
		}
		else if (Algorithm == "quick-sort") {
			runningTimeQuickSort(a, 0, n - 1, runningTime);
		}
		else if (Algorithm == "bubble-sort") {
			runningTimeBubbleSort(a, n, runningTime);
		}
		else if (Algorithm == "heap-sort") {
			runningTimeHeapSort(a, n, runningTime);
		}
		else if (Algorithm == "merge-sort") {
			runningTimeMergeSort(a, n, runningTime);
		}
		else if (Algorithm == "radix-sort") {
			runningTimeRadixSort(a, n, runningTime);
		}
		else if (Algorithm == "flash-sort") {
			runningTimeFlashSort(a, n, runningTime);
		}
	}
	else if (outputParameters == "-comp") { // Check if outputParameters is "-comp"
		// Depending on the selected Algorithm, count comparisons
		if (Algorithm == "selection-sort") { 
			compareSeLectionSort(a, n, countCompare);
		}
		else if (Algorithm == "shaker-sort") {
			compareShakerSort(a, n, countCompare);
		}
		else if (Algorithm == "counting-sort") {
			compareCountingSort(a, n, countCompare);
		}
		else if (Algorithm == "insertion-sort") {
			compareInsertionSort(a, n, countCompare);
		}
		else if (Algorithm == "shell-sort") {
			compareShellSort(a, n, countCompare);
		}
		else if (Algorithm == "quick-sort") {
			compareQuickSort(a, 0, n - 1, countCompare);
		}
		else if (Algorithm == "bubble-sort") {
			compareBubbleSort(a, n, countCompare);
		}
		else if (Algorithm == "heap-sort") {
			compareHeapSort(a, n, countCompare);
		}
		else if (Algorithm == "merge-sort") {
			compareMergeSort(a, n, countCompare);
		}
		else if (Algorithm == "radix-sort") {
			compareRadixSort(a, n, countCompare);
		}
		else if (Algorithm == "flash-sort") {
			compareFlashSort(a, n, countCompare);
		}
	}
	else { // If outputParameters is neither "-time" nor "-comp"
		// Create a copy array 'b' for sorting algorithms that require it

		int* b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		// Perform both comparison and running time calculation for the selected Algorithm
		if (Algorithm == "selection-sort") {
			compareSeLectionSort(a, n, countCompare);
			runningTimeSelectionSort(b, n, runningTime);
		}
		else if (Algorithm == "shaker-sort") {
			compareShakerSort(a, n, countCompare);
			runningTimeShakerSort(b, n, runningTime);
		}
		else if (Algorithm == "counting-sort") {
			compareCountingSort(a, n, countCompare);
			runningTimeCountingSort(b, n, runningTime);
		}
		else if (Algorithm == "insertion-sort") {
			compareInsertionSort(a, n, countCompare);
			runningTimeInsertionSort(b, n, runningTime);
		}
		else if (Algorithm == "shell-sort") {
			compareShellSort(a, n, countCompare);
			runningTimeShellSort(b, n, runningTime);
		}
		else if (Algorithm == "quick-sort") {
			compareQuickSort(a, 0, n - 1, countCompare);
			runningTimeQuickSort(b, 0, n - 1, runningTime);
		}
		else if (Algorithm == "bubble-sort") {
			compareBubbleSort(a, n, countCompare);
			runningTimeBubbleSort(b, n, runningTime);
		}
		else if (Algorithm == "heap-sort") {
			compareHeapSort(a, n, countCompare);
			runningTimeHeapSort(b, n, runningTime);
		}
		else if (Algorithm == "merge-sort") {
			compareMergeSort(a, n, countCompare);
			runningTimeMergeSort(b, n, runningTime);
		}
		else if (Algorithm == "radix-sort") {
			compareRadixSort(a, n, countCompare);
			runningTimeRadixSort(b, n, runningTime);
		}
		else if (Algorithm == "flash-sort") {
			compareFlashSort(a, n, countCompare);
			runningTimeFlashSort(b, n, runningTime);
		}

		if (Algorithm == "bubble-sort") {
			compareBubbleSort(a, n, countCompare);
			runningTimeBubbleSort(b, n, runningTime);
		}
		else if (Algorithm == "heap-sort") {
			compareHeapSort(a, n, countCompare);
			runningTimeHeapSort(b, n, runningTime);
		}
		else if (Algorithm == "merge-sort") {
			compareMergeSort(a, n, countCompare);
			runningTimeMergeSort(b, n, runningTime);
		}

		delete[] b; // Deallocate memory for array 'b'
	}
}

string GetInputOrderDescription(string inputOrder) {

	if (inputOrder == "-rand") {
		return "Randomize";  // Return description for random order
	}
	else if (inputOrder == "-nsorted") {
		return "Nearly Sorted";  // Return description for nearly sorted order
	}
	else if (inputOrder == "-sorted") {
		return "Sorted"; // Return description for sorted order
	}
	else if (inputOrder == "-rev") {
		return "Reversed"; // Return description for reversed order
	}
}

string GetAlgorithmDescription(string Algorithm) {
	if (Algorithm == "selection-sort") {
		return "Selection Sort";   // Return description for selection sort
	}
	else if (Algorithm == "insertion-sort") {
		return "Insertion Sort";  // Return description for insertion sort
	}
	else if (Algorithm == "bubble-sort") {
		return "Bubble Sort"; // Return description for bubble sort
	}
	else if (Algorithm == "shaker-sort") {
		return "Shaker Sort";  // Return description for shaker sort
	}
	else if (Algorithm == "shell-sort") {
		return "Shell Sort"; // Return description for shell sort
	}
	else if (Algorithm == "heap-sort") {
		return "Heap Sort";  // Return description for heap sort
	}
	else if (Algorithm == "merge-sort") {
		return "Merge Sort"; // Return description for merge sort
	}
	else if (Algorithm == "quick-sort") {
		return "Quick Sort";  // Return description for quick sort
	}
	else if (Algorithm == "counting-sort") {
		return "Counting Sort"; // Return description for counting sort
	}
	else if (Algorithm == "radix-sort") {
		return "Radix Sort"; // Return description for radix sort
	}
	else if (Algorithm == "flash-sort") {
		return "Flash Sort";  // Return description for flash sort
	}
}

void Command1(string Algorithm, string givenInput, string outputParameters) {
	int* a; // Declare a pointer 'a' for the array of type int
	int n;  // Declare an integer variable 'n' to store the size of the array
	long long countCompare = 0; // Initialize a long long variable 'countCompare' to 0 for comparisons
	double runningTime = 0; // Initialize a double variable 'runningTime' to store running time in milliseconds

	// Read array from file into 'a' and set 'n' to the number of elements read
	ReadArrayFromFile(givenInput, a, n);

	if (n > 1000000) {
		cout << "Exceeds input size" << endl;
		return;
	}

	// Call function to compare or measure running time of sorting algorithm
	CompareOrRunningTimeSortArray(a, n, Algorithm, outputParameters, countCompare, runningTime);

	
	cout << "ALGORITHM MODE" << endl; // Print header for the algorithm mode section
	cout << "Algorithm: " << GetAlgorithmDescription(Algorithm) << endl; // Print selected algorithm
	cout << "Input file: " << givenInput << endl; // Print input file name
	cout << "Input size: " << n << endl; // Print number of elements in input array
	cout << "-------------------------" << endl; // Print separator line

	// Display output parameters such as comparisons and running time
	DisplayOutputParameters(outputParameters, countCompare, runningTime);

	// Write sorted array to output file
	WriteArrayToFile("output.txt", a, n);


	// Deallocate memory for the array
	delete[] a;
}

void GenerateInputData(int*& a, int n, string inputOrder) {

	// Allocate memory for array 'a' of size 'n'
	a = new int[n];

	// Check inputOrder to determine how to generate data
	if (inputOrder == "-rand") {
		// Generate random data
		GenerateData(a, n, 0);
	}
	else if (inputOrder == "-nsorted") {
		// Generate nearly sorted data
		GenerateData(a, n, 3);
	}
	else if (inputOrder == "-sorted") {
		// Generate sorted data
		GenerateData(a, n, 1);
	}
	else if (inputOrder == "-rev") {
		// Generate reverse sorted data
		GenerateData(a, n, 2);
	}
}

void Command2(string Algorithm, int inputSize, string inputOrder, string outputParameters) {

	int* a; // Declare a pointer 'a' for the array of type int
	int n = inputSize; // Declare an integer variable 'n' to store the size of the array

	long long countCompare = 0; // Initialize a long long variable 'countCompare' to 0 for comparisons
	double runningTime = 0; // Initialize a double variable 'runningTime' to store running time in milliseconds

	
	GenerateInputData(a, n, inputOrder); // Generate input data based on inputSize and inputOrder

	WriteArrayToFile("input.txt", a, n); // Write input data to "input.txt"

	// Compare or measure running time of sorting algorithm on array 'a'
	CompareOrRunningTimeSortArray(a, n, Algorithm, outputParameters, countCompare, runningTime); 

	
	cout << "ALGORITHM MODE" << endl; // Print header for the algorithm mode section
	cout << "Algorithm: " << GetAlgorithmDescription(Algorithm) << endl; // Print selected algorithm
	cout << "Input size: " << n << endl; // Print input size
	cout << "Input order: " << GetInputOrderDescription(inputOrder) << endl; // Print input order description

	cout << "-------------------------" << endl; // Print separator line

	DisplayOutputParameters(outputParameters, countCompare, runningTime); // Display output parameters such as comparisons and running time


	WriteArrayToFile("output.txt", a, n); // Write sorted array to "output.txt"

	delete[] a; // Deallocate memory for array 'a'

}

void Command3(string Algorithm, int inputSize, string outputParameters) {
	int* a;  // Declare a pointer 'a' for the array of type int
	int n = inputSize; // Initialize an integer 'n' to inputSize

	long long countCompare = 0;  // Initialize countCompare (long long) to 0 for comparisons
	double runningTime = 0; // Initialize a double variable to store running time in milliseconds

	vector<string> inputOrders = { "-rand","-nsorted","-sorted","-rev" };


	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << GetAlgorithmDescription(Algorithm) << endl;
	cout << "Input size: " << n << endl << endl;


	for (int i = 0; i < inputOrders.size(); i++) { // Iterate through each input order option
		GenerateInputData(a, n, inputOrders[i]); // Generate input data based on current order

		string fileName = "input_" + to_string(i+1) + ".txt"; // Generate file name for current input order
		WriteArrayToFile(fileName, a, n); // Write array 'a' to file with generated file name

		CompareOrRunningTimeSortArray(a, n, Algorithm, outputParameters, countCompare, runningTime);  // Compare or measure running time of sorting algorithm on array 'a'
		 
		cout << "Input order: " << GetInputOrderDescription(inputOrders[i]) << endl;  // Print description of current input order
		cout << "-------------------------" << endl; // Print separator line

		DisplayOutputParameters(outputParameters, countCompare, runningTime); // Display output parameters such as comparisons and running time
		delete[] a; // Deallocate memory for array 'a'
		a = NULL;  // Set 'a' to NULL to avoid dangling pointer


		cout << endl; // Print an extra newline 

	}
}

void Command4(string Algorithm1, string Algorithm2, string givenInput) {
	int* a, *b; // Declare pointers 'a' and 'b' for arrays of type int
	int na, nb; // Declare integer variables 'na' and 'nb' to store sizes of arrays 'a' and 'b'
	long long countCompare1 = 0, countCompare2 = 0; // Initialize long long variables countCompare1 and countCompare2  to 0 for comparisons
	double runningTime1 = 0, runningTime2 = 0; // Initialize double variables runningTime1 and runningTime2 to 0 for storing running times in milliseconds

	// Read arrays 'a' and 'b' from given input file
	ReadArrayFromFile(givenInput, a, na);
	ReadArrayFromFile(givenInput, b, nb);

	if (na > 1000000) {
		cout << "Exceeds input size" << endl;
		return;
	}

	cout << "COMPARE MODE" << endl; // Print header for the compare mode section
	cout << "Algorithm: " << GetAlgorithmDescription(Algorithm1) << " | " << GetAlgorithmDescription(Algorithm2) << endl; // Print selected algorithms

	cout << "Input file: " << givenInput << endl;  // Print input file name
	cout << "Input size: " << na << endl;  // Print size of array 'a'

	cout << "-------------------------" << endl; // Print separator line

	// Compare or measure running time of sorting algorithm Algorithm1 on array 'a'
	CompareOrRunningTimeSortArray(a, na, Algorithm1, "-both", countCompare1, runningTime1);

	// Compare or measure running time of sorting algorithm Algorithm2 on array 'b'
	CompareOrRunningTimeSortArray(b, nb, Algorithm2, "-both", countCompare2, runningTime2);

	// Print running times of algorithms Algorithm1 and Algorithm2
	cout << "Running Time: " << runningTime1 << '\t' << "|  " << runningTime2 << endl;

	// Print number of comparisons made by algorithms Algorithm1 and Algorithm2
	cout << "Comparisions: " << countCompare1 << '\t' << "|  " << countCompare2 << endl;


	// Deallocate memory for arrays 'a' and 'b'
	delete[] a;
	delete[] b;
}

void Command5(string Algorithm1, string Algorithm2, int inputSize, string inputOrder) {
	int* a, * b;  // Declare pointers 'a' and 'b' for arrays of type int
	int na = inputSize, nb = inputSize; // Declare integer variables 'na' and 'nb' to inputSize 
	long long countCompare1 = 0, countCompare2 = 0; // Initialize long long variables countCompare1 and countCompare2  to 0 for comparisons
	double runningTime1 = 0, runningTime2 = 0; // Initialize double variables runningTime1 and runningTime2 to 0 for storing running times in milliseconds

	// Generate input data for array 'a' based on inputOrder
	GenerateInputData(a, na, inputOrder);

	// Allocate memory for array 'b' and copy elements from 'a' to 'b'
	b = new int[nb];

	for (int i = 0; i < nb; i++) {
		b[i] = a[i];
	}

	// Write array 'a' to file "input.txt"
	WriteArrayToFile("input.txt", a, na);

	// Compare or measure running time of sorting Algorithm1 on array 'a'
	CompareOrRunningTimeSortArray(a, na, Algorithm1, "-both", countCompare1, runningTime1);

	// Compare or measure running time of sorting Algorithm2 on array 'b'
	CompareOrRunningTimeSortArray(b, nb, Algorithm2, "-both", countCompare2, runningTime2);

	cout << "COMPARE MODE" << endl; // Print header for the compare mode section
	cout << "Algorithm: " << GetAlgorithmDescription(Algorithm1) << " | " << GetAlgorithmDescription(Algorithm2) << endl; // Print selected algorithms
	cout << "Input size: " << inputSize << endl; // Print input size
	cout << "Input order: " << GetInputOrderDescription(inputOrder) << endl; // Print input order description
	cout << "-------------------------" << endl; // Print separator line

	// Print running times of Algorithm1 and Algorithm2
	cout << "Running Time: " << runningTime1 << '\t' << "|  " << runningTime2 << endl;
	// Print comparisons made by Algorithm1 and Algorithm2
	cout << "Comparisions: " << countCompare1 << '\t' << "|  " << countCompare2 << endl;

	// Deallocate memory for arrays 'a' and 'b'
	delete[] a;
	delete[] b;
}