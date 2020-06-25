#pragma once
#include<string>;
#include <vector>;

using namespace std;

namespace FileReader {
	// Formats the given lines into a batch of csv text
	vector<string> formatLines(string lines);
}
