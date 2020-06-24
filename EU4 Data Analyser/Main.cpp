#include <iostream>
#include "FileReader.h";
#include "CsvWriter.h";

using namespace std;

int main() {
	string formattedData = FileReader::formatLines("data.eu4");

	CsvWriter::writeToCsv("data", formattedData);

	return 0;
}