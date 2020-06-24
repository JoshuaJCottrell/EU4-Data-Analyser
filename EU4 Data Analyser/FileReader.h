#pragma once
#include<string>

using namespace std;

// Extracts the lines from the file specified by the file name
string extractLines(const char* fileName);

// Formats the given lines into csv text
string formatLines(char* lines);
