#include <iostream>
#include "FileReader.h";
#include "CsvWriter.h";

#include <vector>

using namespace std;

int main() {
	vector<string> formattedData = FileReader::formatLines("data.eu4");

	CsvWriter::writeToCsv(formattedData);

	return 0;
}