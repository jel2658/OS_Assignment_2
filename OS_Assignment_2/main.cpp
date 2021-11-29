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

		size_t temp = 0;
		string temp2 = line[2]; // "0 1 0"

		int toNext = processes;

		for (int i = 0; i < toNext; i++) {
			temp2 = line[2 + i];
			for (int j = 0; j < resourceTypes; j++) {

				Allocation[i][j] = stoi(temp2);
				temp = temp2.find_first_of("0123456789");
				temp2 = temp2.substr(++temp);
				//cout << temp2;
				//cout << Allocation[i][j] << " ";
			}
			//cout << "\n";
		}

		toNext = toNext + processes;

		temp = 0;
		temp2 = line[3 + processes];
		//cout << temp2 << "\n";

		for (int i = 0; i < processes; i++) {
			temp2 = line[3 + processes + i];
			for (int j = 0; j < resourceTypes; j++) {

				Max[i][j] = stoi(temp2);
				temp = temp2.find_first_of("0123456789");
				temp2 = temp2.substr(++temp);
				//cout << Max[i][j] << " ";
			}
			//cout << "\n";
		}

		temp = 0;
		temp2 = line[9 + processes];
		//cout << temp2 << "\n";

		for (int i = 0; i < resourceTypes; i++) {

			Available[i] = stoi(temp2);
			temp = temp2.find_first_of("0123456789");
			temp2 = temp2.substr(++temp);
			//cout << Available[i] << " ";
		}

		for (int i = 0; i < processes; i++) {
			for (int j = 0; j < resourceTypes; j++) {
				Need[i][j] = Max[i][j] - Allocation[i][j];
			}
		}

		bool safe = false;
			int Work[resourceTypes];
			bool Finish[processes];
			int sequence[processes];
			int safeProcesses = 0;

			for (int i = 0; i < processes; i++) {
				Finish[i] = false;
			}

			for (int i = 0; i < resourceTypes; i++) {
				Work[i] = Available[i];
			}

			while (safeProcesses < processes) {
				for (int i = 0; i < processes; i++) {
					if (!Finish[i]) {
						int j = 0;
						while (j < resourceTypes) {
							if (!(Need[i][j] <= Work[j])) {
								break;
							}
							j++;
						}
						if (j == resourceTypes) {
							for (int index = 0; index < resourceTypes; index++) {
								Work[index] = Work[index] + Allocation[i][index];
							}
							sequence[safeProcesses] = i;
							safeProcesses++;
							Finish[i] = true;
							safe = true;
						}
					}
				}
				
			}
			//cout << safe << "\n";
			for (int i = 0; i < processes; i++) {
				//cout << Finish[i] << "\n";
				if (!Finish[i]) {
					safe = false;
					break;
				}
			}

			if (safe) {
				cout << "System is in a safe state.\n";
				cout << "Safe sequence of processes is: \n";
				for (int i = 0; i < processes; i++) {
					cout << sequence[i] << " ";
				}
			}
			else {
				cout << "System is not in a safe state.\n";
			}
		
	}
	else {
		cout << "Unable to open input file.";
	}

	file.close();
	return 0;
}