#include "File.h"

void ReadArrayFromFile(string fileName, int*& a, int& n) {
	ifstream ifs(fileName); // Open the file specified by fileName for input

	if (!ifs) { // Check if the file opening failed
		cout << "Can not open the file " << endl; // Print an error message if the file cannot be opened
		return;
	}

	ifs >> n; // Read the number of elements from the file and store it in n
	a = new int[n];  // Allocate memory dynamically for an array 'a' of size n

	// Iterate through the file to read each element into array 'a'
	for (int i = 0; i < n; i++) {
		ifs >> a[i]; // Read each integer from the file and store it in the array 'a'
	}

	ifs.close(); // Close the input file stream after reading all elements


}
void WriteArrayToFile(string fileName, int* a, int n) {

	ofstream ofs(fileName); // Open the file specified by fileName for output

	if (!ofs) { // Check if the file opening failed
		cout << "Can not open the file " << endl; // Print an error message if the file cannot be opened
		return;  // Exit the function if file opening failed
	}

	ofs << n << endl; // Write the number of elements 'n' to the file followed by a newline

	// Iterate through array 'a' to write each element to the file separated by spaces
	for (int i = 0; i < n; i++) { 
		ofs << a[i] << " ";  // Write each element of array 'a' to the file followed by a space
	}

	ofs.close(); // Close the output file stream after finishing writing

}