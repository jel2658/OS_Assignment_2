#include "header.h"
using namespace std;

int main() {

	fstream file;
	file.open("input.txt");

	if (file.is_open()) {

		string line[3];
		for (int i = 0; getline(file, line[i]); i++) {
			cout << "Getting lines...\n";
		}

		size_t num = line[0].find_last_not_of("0123456789");
		string num2 = line[0].substr(num + 1);
		//cout << num2;
		processes = stoi(num2);
		//cout << processes;
		num = line[1].find_last_not_of("0123456789");
		num2 = line[1].substr(num + 1);
		resourceTypes = stoi(num2);
		//cout << resourceTypes;
		num = line[2].find_first_of("0123456789");
		num2 = line[2].substr(num);
		//cout << num2;

		int instances[10];
		instances[0] = stoi(num2);
		for (int i = 1; i < resourceTypes; i++) {
			num = num2.find_first_of(" ");
			num2 = num2.substr(num + 1);
			instances[i] = stoi(num2);
		}
		

	}
	else {
		cout << "Unable to open input file.";
	}

	file.close();
	return 0;
}