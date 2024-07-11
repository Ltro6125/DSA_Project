#pragma once

#ifndef File_H
#define File_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadArrayFromFile(string fileName, int*& a, int& n);
void WriteArrayToFile(string fileName, int* a, int n);



#endif