#include <iostream>
#include "FileReader.h";

using namespace std;

int main() {
	string formattedData = FileReader::formatLines(FileReader::extractLines("data.eu4"));

	return 0;
}