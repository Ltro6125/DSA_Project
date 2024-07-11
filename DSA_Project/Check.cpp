#include "Check.h"

bool isInteger(string str) {

	// Iterate through each character in the string 'str'
	for (int i = 0; i < str.size(); i++) {
		// Check if the character is not a digit
		if (!isdigit(str[i])) {
			return false; // Return false if any character is not a digit
		}
	}

	return true;  // Return true if all characters are digits
}

bool checkValidInputSize(int n) {
	if (n <= 1000000) { // Check if the input size 'n' is less than or equal to 1,000,000
		return true;
	}
	return false;
}

bool isFormatFile(string str) {
	const char* c_str = str.c_str(); // Convert string 'str' to C-style string
	const char* pch = strchr(c_str, '.'); // Find the first occurrence of '.' in the C-style string

	// Check conditions for invalid format
	if (pch == nullptr || pch == c_str || *(pch + 1) == '\0') {
		return false; // Return false if the '.' is missing or at the beginning/end of the string
	}
	// Check if the file format is "txt"
	if (strcmp(pch + 1, "txt") == 0) {
		return true; // Return true if the file format is "txt"
	}
	return false; // Return false if the file format is not "txt"
}

bool checkAlgorithm(string token) {

	// List of valid sorting algorithms
	vector<string> algorithms = { "selection-sort", "shaker-sort", "counting-sort", "insertion-sort", "shell-sort", "quick-sort", "bubble-sort","heap-sort","merge-sort", "radix-sort", "flash-sort" };

	// Iterate through each algorithm in the list
	for (int i = 0; i < algorithms.size(); i++) {
		// Check if the given token matches any algorithm in the list
		if (token == algorithms[i]) {
			return true; // Return true if the token is a valid algorithm
		}
	}

	return false;  // Return false if the token is not a valid algorithm
}

bool checkDataOrder(string token) {

	// List of valid data orders
	vector<string> dataOrder = { "-rand","-nsorted","-sorted","-rev" };

	// Iterate through each data order in the list
	for (int i = 0; i < dataOrder.size(); i++) {
		// Check if the given token matches any data order in the list
		if (token == dataOrder[i]) {
			return true; // Return true if the token is a valid data order
		}
	}

	return false; // Return false if the token is not a valid data order
}

bool checkOutputParameters(string token) {
	// List of valid output parameters
	vector<string> outputParameters = { "-time","-comp","-both" };

	// Iterate through each output parameter in the list
	for (int i = 0; i < outputParameters.size(); i++) {
		// Check if the given token matches any output parameter in the list
		if (token == outputParameters[i]) {
			return true; // Return true if the token is a valid output parameter
		}
	}

	return false; // Return false if the token is not a valid output parameter

}