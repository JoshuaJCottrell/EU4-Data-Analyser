#include "CsvWriter.h"

#include <iostream>;
#include <fstream>;

using namespace std;

void CsvWriter::writeToCsv(std::string fileName, std::string text) {
	ofstream file(fileName + ".csv");
	file << text;
	file.close();
}
