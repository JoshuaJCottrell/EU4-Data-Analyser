#include "CsvWriter.h"

#include <iostream>;
#include <fstream>;

// Writes a string of text to a csv file
void write(string fileName, string text) {
	ofstream file(fileName + ".csv");
	file << text;
	file.close();
}

void CsvWriter::writeToCsv(vector<string> text) {
	for (int i = 0; i < text.size(); i += 2) {
		write(text[i], text[i + 1]);
	}
}
