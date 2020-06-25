#pragma once

#include <string>
#include <vector>

using namespace std;

namespace CsvWriter {
	// Writes a batch of csv files from the text given
	void writeToCsv(vector<string> text);
}