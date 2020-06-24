#pragma once

#include <string>

namespace CsvWriter {
	// Writes the given text to a csv file specified by the file name
	void writeToCsv(std::string fileName, std::string text);
}