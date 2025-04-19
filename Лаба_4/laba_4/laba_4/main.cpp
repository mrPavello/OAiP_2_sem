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
	
	cout << "Меню:" << endl;
	cout << "1 - Добавление инфориации о государстве в базу данных." << endl;
	cout << "2 - Чтение информации о государстве." << endl;
	cout << "3 - Удаление информации из базы данных." << endl;
	cout << "4 - Поиск информации." << endl;
	cout << "5 - Запись информации в файл." << endl;
	cout << "6 - Чтение информации из файла." << endl;
	cout << "7 - Выход." << endl;
	
	do {
		cout << "Ввод: "; cin >> choice; cout << endl;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7) {
			cout << "Ошибка!" << endl;
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
		cout << "Введите имя файла: "; getline(cin, file_name);
		write_to_file(countries, file_name);
		main();
	} break;
	case 6: {
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		string file_name;
		cout << "Введите имя файла: "; getline(cin, file_name);
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
	cout << "Заполните информацию о государстве." << endl << endl;
	cout << "Введите название государства: "; getline(cin, countries[i].name);
	cout << "Введите ФИО президента: "; getline(cin, countries[i].president);
	cout << "Введите название столицы: "; getline(cin, countries[i].capital);
	while (true) {
		cout << "Введите численность населения государства: "; 
		cin >> countries[i].population;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка!" << endl;
		}
		else break;
	}
	while (true) {
		cout << "Введите площадь государтсва: "; 
		cin >> countries[i].square;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка!" << endl;
		}
		else break;
	}
	
	cout << endl << "Хотите продолжить?" << endl;
	cout << "1 - да, 0 - нет." << endl;
	cout << "Ввод: "; cin >> choice; cout << endl;
	if (choice != 1) {
		choice = 0;
	}

	num_countries++;
	return choice;
}

void output_elements(States* countries) {
	short int choice;
	cout << "1 - Вывод информации о конкретном государстве." << endl;
	cout << "2 - Вывод информации о всех государствах." << endl;
	do {
		cout << "Ввод: "; cin >> choice; cout << endl;
		if (choice != 1 && choice != 2) {
			cout << "Ошибка!" << endl;
		}
	} while (choice != 1 && choice != 2);
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	switch (choice) {
	case 1: {
		string name_country;
		cout << "Введите название государсва: "; getline(cin, name_country); cout << endl;
		for (int i = 0; i < num_countries; i++) {
			if (name_country == countries[i].name) {
				cout << "Государство: " << countries[i].name << endl;
				cout << "Президент: " << countries[i].president << endl;
				cout << "Столица: " << countries[i].capital << endl;
				cout << "Численность населения: " << countries[i].population << endl;
				cout << "Площадь территории: " << countries[i].square << endl << endl;
			}
		}
	} break;
	case 2: {
		for (int i = 0; i < num_countries; i++) {
			cout << "Государство: " << countries[i].name << endl;
			cout << "Президент: " << countries[i].president << endl;
			cout << "Столица: " << countries[i].capital << endl;
			cout << "Численность населения: " << countries[i].population << endl;
			cout << "Площадь территории: " << countries[i].square << endl << endl;
		}
	} break;
	}
}

void delete_struct(States* countries) {
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	string name_country;
	bool num = 0, choice;
	cout << "Введите название государсва, которое желаете удалить из базы данных: "; getline(cin, name_country); cout << endl;

	for (int i = 0; i < num_countries; i++) {
		if (countries[i].name == name_country) {
			for (int j = i; j < num_countries; j++) {
				countries[j] = countries[j + 1];
			}
			num = 1;
		}
	}

	if (!num) {
		cout << "Государтво не найдено." << endl;
		delete_struct(countries);
	}
	else {
		cout << "Информация успешно удалена!" << endl;
		cout << "Желаете продолжить? Да - 1, нет - 0." << endl;
		cout << "Ввод: "; cin >> choice;
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
	cout << "Какую инфлрмацию вывести?" << endl;
	cout << "1. Вся информация о государстве: " << endl;
	cout << "2. Президент государства." << endl;
	cout << "3. Столица государства." << endl;
	cout << "4. Численность населения государства." << endl;
	cout << "5. Площадь территории государства." << endl;
	do {
		cout << "Ввод: "; cin >> choice; cout << endl;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
			cout << "Ошибка!" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Введите название государстава: "; getline(cin, name_country);
	
	switch (choice) {
	case 1: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "Государство: " << countries[i].name << endl;
				cout << "Президент: " << countries[i].president << endl;
				cout << "Столица: " << countries[i].capital << endl;
				cout << "Численность населения: " << countries[i].population << endl;
				cout << "Площадь территории: " << countries[i].square << endl << endl;
			}
			else {
				cout << "Ничего не найдено." << endl << endl;
			}
		}
	} break;
	case 2: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "Президент: " << countries[i].president << endl;
			}
			else {
				cout << "Ничего не найдено." << endl << endl;
			}
		}
	} break;
	case 3: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "Столица: " << countries[i].capital << endl;
			}
			else {
				cout << "Ничего не найдено." << endl << endl;
			}
		}
	} break;
	case 4: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "Численность населения: " << countries[i].population << endl;
			}
			else {
				cout << "Ничего не найдено." << endl << endl;
			}
		}
	} break;
	case 5: {
		for (int i = 0; i < num_countries; i++) {
			if (countries[i].name == name_country) {
				cout << "Площадь территории: " << countries[i].square << endl;
			}
			else {
				cout << "Ничего не найдено." << endl << endl;
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
		cout << "Информация успешно записана в файл!" << endl << endl;
		file.close();
	}
	else {
		cerr << "Не удалось открыть файл для записи." << endl << endl;
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
		cout << "Информация успешно считана!" << endl << endl;
		file.close();
	}
	else {
		cout << "Не удалось открыть файл для чтения." << endl << endl;
	}
}