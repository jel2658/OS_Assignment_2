#include "header.h"
using namespace std;

int main() {

	fstream file;
	file.open("input.txt");

	if (file.is_open()) {

		string line[2];
		for (int i = 0; getline(file, line[i]); i++) {
			cout << "Getting lines...";
		}

		size_t num = line[0].find_last_not_of("0123456789");
		string num2 = line[0].substr(num + 1);
		//cout << num2;
		processes = stoi(num2);
		//cout << processes;


	}
	else {
		cout << "Unable to open input file.";
	}

	file.close();
	return 0;
}