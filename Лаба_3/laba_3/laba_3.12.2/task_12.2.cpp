#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void input(string filename, char my_string[]);
int output(string filename);

int main() {
	setlocale(LC_ALL, "ru");

	char my_string[255];
	
	cout << "Введите строку символов, разделённых пробелами." << endl;
	cin.getline(my_string, 255);

	input("FILE1.txt", my_string);
	
	cout << "Нечетные числа: " << endl;
	output("FILE1.txt");

	return 0;
}
void input(string filename, char my_string[]) {
	ofstream out(filename);
	if (!out.is_open()) {
		cerr << "Error! File doesn't open!";
	}
	out << my_string;
}

int output(string filename) {
	ifstream in(filename);
	if (!in.is_open()) {
		cerr << "Error! File doesn't open!";
	}

	char symbol;
	int number;
	while (in >> symbol) {
		if (isdigit(symbol)) {
			number = symbol - '0';
			if (number % 2 != 0) {
				cout << number << " ";
			}
		}
		
	}
	
	in.close();
	return 0;
}