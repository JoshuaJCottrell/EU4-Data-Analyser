#include "FileReader.h";
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char* extractLines(const char* fileName) {
	ifstream file;
	file.open(fileName);

	string lines;

	if (file.is_open()) {
		std::string line;

		while (std::getline(file, line)) {
			lines += line + "\n";
		}

	}

	return lines.c_str();
}

const char* formatLines(const char* lines) {
	return nullptr;
}
