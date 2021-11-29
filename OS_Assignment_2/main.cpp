#include "header.h"
using namespace std;

int main() {

	fstream file;
	file.open("input.txt");

	if (file.is_open()) {

		string line[100];
		for (int i = 0; getline(file, line[i]); i++) {
			cout << "Getting lines...\n";
		}

		/*size_t num = line[0].find_last_not_of("0123456789");	// Old code. Originally had the program find number of processes and resource types, but was unable to figure it out that way. It now assumes 5 processes and 3 resource types.
		*														This should be changed through the header file, if necessary.
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
		}*/
		
		int Available[resourceTypes];
		int Max[processes][resourceTypes];
		int Allocation[processes][resourceTypes];
		int Need[processes][resourceTypes];

		size_t temp;
		string temp2;

		int toNext = 2 + processes;

		for (int i = 2; i < toNext; i++) {
			for (int j = 0; j < resourceTypes; j++) {

				temp = line[i].find_first_of("0123456789");
				temp2 = line[i].substr(temp);
				Allocation[i][j] = stoi(temp2);
				cout << Allocation[i][j];
				temp++;
			}
			cout << "\n";
		}

		toNext = toNext + processes;

		{
			int Work[resourceTypes];
			bool Finish[processes];
		}
	}
	else {
		cout << "Unable to open input file.";
	}

	file.close();
	return 0;
}