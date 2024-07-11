#pragma once

#ifndef Check_H
#define	Check_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInteger(string str);
bool checkValidInputSize(int n);
bool isFormatFile(string str);

bool checkAlgorithm(string token);
bool checkDataOrder(string token);
bool checkOutputParameters(string token);

#endif 
