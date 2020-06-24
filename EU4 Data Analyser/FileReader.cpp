#include "FileReader.h";
#include <iostream>
#include <fstream>

string extractLines(const char* fileName) {
	ifstream file;
	file.open(fileName);

	string lines;

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			lines += line + "\n";
		}

	}

	return lines;
}

string formatLines(const char* lines) {
	return nullptr;
}
