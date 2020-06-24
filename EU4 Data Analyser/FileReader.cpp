#include "FileReader.h";
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

// Recursive struct that helps store the blocks of data during formatting
struct formatBlock {
	formatBlock* parent;
	vector<formatBlock*> childs;
	vector<string> dataPoints;
	string name;
};

// Removes tabs and spaces from the start and end of a string
string trim(string line) {
	int strt;
	int end;

	for (strt = 0; strt < line.size(); strt++) {
		if (line.at(strt) != ' ' && line.at(strt) != '\t') {
			break;
		}
	}

	for (end = line.size(); end > 0; end--) {
		if (line.at(end - 1) != ' ' && line.at(end - 1) != '\t') {
			break;
		}
	}

	return line.substr(strt, end);
}

// Returns the index in the string where the equals sign is
int findEq(string line) {
	int chr = 0;

	for (chr = 0; chr < line.size(); chr++) {
		if (line.at(chr) == '=') {
			break;
		}
	}

	return chr;
}

// Returns the part of the string before the equals sign
string getName(string line) {
	int chr = findEq(line);

	return line.substr(0, chr);
}

// Returns the part of the string after the equals sign
string getData(string line) {
	int chr = findEq(line);

	return line.substr(chr + 1, line.size());
}

// Formats the data into a csv format
string formatData(formatBlock* data, vector<string> dataPoints) {
	string formatted = "id,";

	vector<string> d;
	d.push_back("");

	for (string s : dataPoints) {
		formatted += s + ",";
		d.push_back("");
	}

	formatted = formatted.substr(0, formatted.size() - 1) + "\n";

	for (int i = 0; i < data->childs.size(); i++) {
		d[0] = data->childs[i]->name;

		for (int n = 0; n < dataPoints.size(); n++) {
			for (string s : data->childs[i]->dataPoints) {
				if (dataPoints[n] == getName(s)) {
					d[n + 1] = getData(s);
				}
			}
		}

		for (int n = 0; n < d.size(); n++) {
			formatted += d[n] + ",";
		}

		formatted = formatted.substr(0, formatted.size() - 1) + "\n";
	}

	return formatted;
}

// Extracts the lines from the file denoted by the file name into a format block
formatBlock* extractLines(string fileName) {
	cout << "INFO: Extraction Started!" << endl;

	ifstream file;
	file.open(fileName);

	formatBlock* current = new formatBlock();

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			line = trim(line);

			if (line.find('{') != string::npos) {
				if (line.find('}') != string::npos) {
					current->dataPoints.push_back(line);
				}
				else {
					formatBlock* child = new formatBlock();
					child->name = getName(line);
					child->parent = current;

					current->childs.push_back(child);

					current = child;
				}
			}
			else if (line.find('}') != string::npos) {
				current = current->parent;
			}
			else {
				current->dataPoints.push_back(line);
			}
		}

	}

	file.close();

	cout << "INFO: Extraction Completed!" << endl;

	return current;
}

string FileReader::formatLines(string fileName) {
	formatBlock* data = extractLines(fileName);

	formatBlock* provinces = NULL;

	for (int i = 0; i < data->childs.size(); i++) {
		if (data->childs[i]->name == "provinces") {
			provinces = data->childs[i];
			break;
		}
	}
	delete data;

	vector<string> points;

	points.push_back("name");

	return formatData(provinces, points);
}
