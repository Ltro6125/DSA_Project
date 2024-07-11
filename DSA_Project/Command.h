#pragma once


#ifndef Command_H
#define Command_H

#include <iostream>
#include <string>
#include <fstream>
#include "File.h"
#include <vector>
#include "Sort.h"
#include "DataGenerator.h"

using namespace std;

void DisplayOutputParameters(string outputParameters, long long countCompare, double runningTime);

void CompareOrRunningTimeSortArray(int*& a, int n, string Algorithm, string outputParameters, long long& countCompare, double& runningTime);
string GetInputOrderDescription(string inputOrder);
string GetAlgorithmDescription(string Algorithm);

void Command1(string Algorithm, string givenInput, string outputParameters);

void GenerateInputData(int*& a, int n, string inputOrder);



void Command2(string Algorithm, int inputSize, string inputOrder, string outputParameters);
void Command3(string Algorithm, int inputSize, string outputParameters);
void Command4(string Algorithm1, string Algorithm2, string givenInput);
void Command5(string Algorithm1, string Algorithm2, int inputSize, string inputOrder);



#endif