#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "utility.h"
#include "cpu.h"
#include "exception.h"

using namespace std;

void menu()
{
	cout << "0) Exit" << endl;
	cout << "1) Run" << endl;
	cout << "2) Show registers" << endl;
}

void display_registers_content(vector<pair<string, int>> registers)
{
	const int width = 14;
	const int width_s = width - 2;
	cout << right << setw(width) << "Register |" << setw(width) << "Value(dec) |" << endl;
	for (int i = 0; i < width * 2; ++i) {
		cout << '-';
	}
	cout << endl;
	for (auto& i : registers) {
		cout << setw(width_s) << i.first << " |" << setw(width_s) << dec << i.second << " |" << endl;
	}
}
void start() {
	cout << "Program starting." << endl;
	cout << "Load file." << endl;
}
int main()
{
	start();
	string filename;
	cin >> filename;

	try {
		int select = 1;
		CPU* c = new CPU();
		c->loadProgram(filename);

		do {
			cout << endl;
			menu();
			cin >> select;

			switch (select) {
			case 1:
				c->run();
				cout << "Finished with success." << endl;
				break;
			case 2:
				cout << "The values of registers" << endl;
				display_registers_content(c->getRegisters());
				break;
			}
		} while (select != 0);
	}
	catch (exception& e) {
		cout << e.what() << endl;
		cout << "The program will be terminated." << endl;
		cout << "Exiting..." << endl;
	}
	return 0;
}

