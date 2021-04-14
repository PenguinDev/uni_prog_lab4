#pragma once
#include <string> 
#include <vector>
#include "main.h"

using namespace std;

void askToStopInput(bool* isUserInputValues);
string askFor(string text, vector<string> compareTo);
vector<vector<string>> castToStringVector(vector<Substance> substances);
double inputDoubleMass();