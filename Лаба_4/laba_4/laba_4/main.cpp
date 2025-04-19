#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>


#define size 50
using namespace std;

struct States {
	string name;
	string capital;
	string president;
	unsigned int population = 0;
	float square = 0;
};

States countries[size];
int num_countries = 0;

bool input_elements(States* countries, int i);
void output_elements(States* counties);
void delete_struct(States* countries);
void search_info(States *countries);
void write_to_file(States* countries, string file_name);
void read_from_file(States* countries, string file_name);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	
	cout << "����:" << endl;
	cout << "1 - ���������� ���������� � ����������� � ���� ������." << endl;
	cout << "2 - ������ ���������� � �����������." << endl;
	cout << "3 - �������� ���������� �� ���� ������." << endl;
	cout << "4 - ����� ����������." << endl;
	cout << "5 - ������ ���������� � ����." << endl;
	cout << "6 - ������ ���������� �� �����." << endl;
	cout << "7 - �����." << endl;
	
	do {
		cout << "����: "; cin >> choice; cout << endl;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7) {
			cout << "������!" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7);
	switch (choice) {
	case 1: {
		for (int i = num_countries; i < size; i++) {
			if (!input_elements(countries, i)) {
				cout << endl << endl;
				main();
			}
		}
	} break;
	case 2: {
		output_elements(countries);
		main();
		cout << endl << endl;
	} break;
	case 3: {
		delete_struct(countries);
	} break;
	case 4: {
		search_info(countries);
		cout << endl << endl;
		main();
	} break;
	case 5: {
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		string file_name;
		cout << "������� ��� �����: "; getline(cin, file_name);
		write_to_file(countries, file_name);
		main();
	} break;
	case 6: {
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		string file_name;
		cout << "������� ��� �����: "; getline(cin, file_name);
		read_from_file(countries, file_name);
		main();
	} break;
	case 7: {
		exit(0);
	} break;
	default: break;
	}

	return 0;
}

bool input_elements(States* countries, int i) {
	bool choice = 0;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "��������� ���������� � �����������." << endl << endl;
	cout << "������� �������� �����������: "; getline(cin, countries[i].name);
	cout << "������� ��� ����������: "; getline(cin, countries[i].president);
	cout << "������� �������� �������: "; getline(cin, countries[i].capital);
	while (true) {
		cout << "������� ����������� ��������� �����������: "; 
		cin >> countries[i].population;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������!" << endl;
		}
		else break;
	}
	while (true) {
		cout << "������� ������� �����������: "; 
		cin >> countries[i].square;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������!" << endl;
		}
		else break;
	}
	
	cout << endl << "������ ����������?" << endl;
	cout << "1 - ��, 0 - ���." << endl;
	cout << "����: "; cin >> choice; cout << endl;
	if (choice != 1) {
		choice = 0;
	}

	num_countries++;
	return choice;
}

void output_elements(States* countries) {
	short int choice;
	cout << "1 - ����� ���������� � ���������� �����������." << endl;
	cout << "2 - ����� ���������� � ���� ������������." << endl;
	do {
		cout << "����: "; cin >> choice; cout << endl;
		if (choice != 1 && choice != 2) {
			cout << "������!" << endl;
		}
	} while (choice != 1 && choice != 2);
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	switch (choice) {
	case 1: {
		string name_country;
		cout << "������� �������� ����������: "; getline(cin, name_country); cout << endl;
		for (int i = 0; i < num_countries; i++) {
			if (name_country == countries[i].name) {
				cout << "�����������: " << countries[i].name << endl;
				cout << "���������: " << countries[i].president << endl;
				cout << "�������: " << countries[i].capital << endl;
				cout << "����������� ���������: " << countries[i].population << endl;
				cout << "������� ����������: " << countries[i].square << endl << endl;
			}
		}
	} break;
	case 2: {
		for (int i = 0; i < num_countries; i++) {
			cout << "�����������: " << countries[i].name << endl;
			cout << "���������: " << countries[i].president << endl;
			cout << "�������: " << countries[i].capital << endl;
			cout << "����������� ���������: " << countries[i].population << endl;
			cout << "������� ����������: " << countries[i].square << endl << endl;
		}
	} break;
	}
}

void delete_struct(States* countries) {
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	string name_country;
	bool num = 0, choice;
	cout << "������� �������� ����������, ������� ������� ������� �� ���� ������: "; getline(cin, name_country); cout << endl;

	for (int i = 0; i < num_countries; i++) {
		if (countries[i].name == name_country) {
			for (int j = i; j < num_countries; j++) {
				countries[j] = countries[j + 1];
			}
			num = 1;
		}
	}

	if (!num) {
		cout << "���������� �� �������." << endl;
		delete_struct(countries);
	}
	else {
		cout << "���������� ������� �������!" << endl;
		cout << "������� ����������? �� - 1, ��� - 0." << endl;
		cout << "����: "; cin >> choice;
		if (choice) {
			delete_struct(countries);
		}
		else {
			main();
		}
	}
}

void search_info(States* countries) {
	int choice;
	string name_country;
	cout << "����� ���������� �������?" << endl;
	cout << "1. ��� ���������� � �����������: " << endl;
	cout << "2. ��������� �����������." << endl;
	cout << "3. ������� �����������." << endl;
	cout << "4. ����������� ��������� �����������." << endl;
	cout << "5. ������� ���������� �����������." << endl;
	do {
		cout << "����: "; cin >> choice; cout << endl;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
			cout << "������!" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "������� �������� ������������: "; getline(cin, name_country);
	
	switch (choice) {
	case 1: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "�����������: " << countries[i].name << endl;
				cout << "���������: " << countries[i].president << endl;
				cout << "�������: " << countries[i].capital << endl;
				cout << "����������� ���������: " << countries[i].population << endl;
				cout << "������� ����������: " << countries[i].square << endl << endl;
			}
			else {
				cout << "������ �� �������." << endl << endl;
			}
		}
	} break;
	case 2: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "���������: " << countries[i].president << endl;
			}
			else {
				cout << "������ �� �������." << endl << endl;
			}
		}
	} break;
	case 3: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "�������: " << countries[i].capital << endl;
			}
			else {
				cout << "������ �� �������." << endl << endl;
			}
		}
	} break;
	case 4: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "����������� ���������: " << countries[i].population << endl;
			}
			else {
				cout << "������ �� �������." << endl << endl;
			}
		}
	} break;
	case 5: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "������� ����������: " << countries[i].square << endl;
			}
			else {
				cout << "������ �� �������." << endl << endl;
			}
		}
	} break;
	}
}

void write_to_file(States* countries, string file_name) {
	ofstream file(file_name, ios::app);
	if (file.is_open()) {
		for (int i = 0; i < num_countries; i++) {
			file << countries[i].name << '\n'
				<< countries[i].president << '\n'
				<< countries[i].capital << '\n'
				<< countries[i].population << '\n'
				<< countries[i].square << '\n' << '\n';
		}
		cout << "���������� ������� �������� � ����!" << endl << endl;
		file.close();
	}
	else {
		cerr << "�� ������� ������� ���� ��� ������." << endl << endl;
	}
}

void read_from_file(States* countries, string file_name) {
	
	ifstream file(file_name);
	if (file.is_open()) {
		while (num_countries < size && file >> countries[num_countries].name) {
			file >> ws;
			getline(file, countries[num_countries].president);
			getline(file, countries[num_countries].capital);
			file >> countries[num_countries].population;
			file >> countries[num_countries].square;
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			num_countries++;
		}
		cout << "���������� ������� �������!" << endl << endl;
		file.close();
	}
	else {
		cout << "�� ������� ������� ���� ��� ������." << endl << endl;
	}
}