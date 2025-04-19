#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;


struct Contact {
	char full_name[50];
	char address[100];
	char phone[15];

	struct Status {
		char study_place[50];
		char work_place[50];
		char position[30];
	} status;
	struct Birthday {
		unsigned day : 5;
		unsigned month : 4;
		unsigned year : 11;
	} birth_date;
	
};

void add_contact(Contact* notebook, int& num_contacts);
void view_contacts(Contact* notebook, int& num_contacts);
void search_contact(Contact* notebook, int& num_contacts, char* last_name);
void write_to_file(Contact* notebook, int& num_contacts, char* file_name);
void read_from_file(Contact* notebook, int& num_contacts, char* file_name);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num_contacts = 0;
	Contact* notebook = new Contact[num_contacts];
	union {
		char last_name[10];
		char file_name[10];
	} names;

	cout << "Добавление кониакта:" << endl;
	add_contact(notebook, num_contacts);

	cout << "Просмотр контактов:" << endl;
	view_contacts(notebook, num_contacts);

	cout << "Поиск контакта:" << endl;
	cout << "Введите фамилию: "; cin.getline(names.last_name, 10);
	cout << endl;
	search_contact(notebook, num_contacts, names.last_name);

	cout << "Запись в файл:" << endl;
	cout << "Введите имя файла: "; cin.getline(names.file_name, 10);
	cout << endl;
	write_to_file(notebook, num_contacts, names.file_name);

	cout << "Чтение из файла:" << endl;
	cout << "Введите имя файла: "; cin.getline(names.file_name, 10);
	cout << endl;
	read_from_file(notebook, num_contacts, names.file_name);

	return 0;
}

void add_contact(Contact* notebook, int& num_contacts) {
	unsigned i;
	cout << "Введите ФИО: "; cin.getline(notebook[num_contacts].full_name, 50);
	cout << "Укажите адрес: "; cin.getline(notebook[num_contacts].address, 100);
	cout << "Введите номер телефона: "; cin.getline(notebook[num_contacts].phone, 15);
	cout << "Введите дату рождения (в формате ДД ММ ГГГГ): ";
	cin >> i; notebook[num_contacts].birth_date.day = i;
	cin >> i; notebook[num_contacts].birth_date.month = i;
	cin >> i; notebook[num_contacts].birth_date.year = i;
	cin.ignore();
	cout << "Укажите место работы, иначе введите нет: "; cin.getline(notebook[num_contacts].status.work_place, 50);
	cout << "Укажите должность: "; cin.getline(notebook[num_contacts].status.position, 30);
	cout << "Укажите место учёбы, иначе введите нет: "; cin.getline(notebook[num_contacts].status.study_place, 50);

	num_contacts++;
	cout << endl << "Контакт успешно добавен!" << endl << endl;
}

void view_contacts(Contact* notebook, int& num_contacts) {
	if (num_contacts == 0) {
		cout << "В книге пусто." << endl << endl;
	}
	else {
		for (int i = 0; i < num_contacts; i++) {
			cout << "ФИО: " << notebook[i].full_name << endl;
			cout << "Адрес: " << notebook[i].address << endl;
			cout << "Телефон: " << notebook[i].phone << endl;
			cout << "Дата рождения: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << endl;
			cout << "Место учёбы: " << notebook[num_contacts].status.study_place << endl;
			cout << "Место работы: " << notebook[num_contacts].status.work_place << endl;
			cout << "Должность: " << notebook[num_contacts].status.position << endl << endl;
		}
	}
}

void search_contact(Contact* notebook, int& num_contacts, char* last_name) {
	bool check = false;
	for (int i = 0; i < num_contacts; i++) {
		if (strstr(notebook[i].full_name, last_name) != nullptr) {
			cout << "ФИО: " << notebook[i].full_name << endl;
			cout << "Адрес: " << notebook[i].address << endl;
			cout << "Телефон: " << notebook[i].phone << endl;
			cout << "Дата рождения: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << endl;
			cout << "Место учёбы: " << notebook[num_contacts].status.study_place << endl;
			cout << "Место работы: " << notebook[num_contacts].status.work_place << endl;
			cout << "Должность: " << notebook[num_contacts].status.position << endl << endl;
			check = true;
		}
	}
	if (!check) {
		cout << "Контакт не найден." << endl << endl;
	}
}

void write_to_file(Contact* notebook, int& num_contacts, char* file_name) {
	ofstream file(file_name, ios::app);
	if (file.is_open()) {
		for (int i = 0; i < num_contacts; i++) {
			file << "ФИО: " << notebook[i].full_name << '\n'
				<< "Адрес: " << notebook[i].address << '\n'
				<< "Телефон: " << notebook[i].phone << '\n'
				<< "Дата рождения: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << '\n'
				<< "Место работы: " << notebook[num_contacts].status.work_place << '\n'
				<< "Должность: " << notebook[num_contacts].status.position << '\n'
				<< "Место учёбы: " << notebook[num_contacts].status.study_place << '\n' << '\n';
		}
		cout << "Информация успешно щаписана в файл." << endl << endl;
		file.close();
	}
	else {
		cerr << "Не удалось открыть файл для записи." << endl << endl;
	}
}

void read_from_file(Contact* notebook, int& num_contacts, char* file_name) {
	ifstream file(file_name);
	int i;
	cin.ignore();
	if (file.is_open()) {
		while (file.getline(notebook[++num_contacts].full_name, 50)) {
			file >> ws;
			file.getline(notebook[++num_contacts].address, 50);
			file.getline(notebook[++num_contacts].phone, 15);
			file >> i; notebook[num_contacts].birth_date.day = i;
			file >> i; notebook[num_contacts].birth_date.month = i;
			file >> i; notebook[num_contacts].birth_date.year = i;
			file.getline(notebook[num_contacts].status.work_place, 50);
			file.getline(notebook[num_contacts].status.position, 30);
			file.getline(notebook[num_contacts].status.study_place, 50);
		}

		cout << "Информация успешно считана!" << endl << endl;
		file.close();
	}
	else {
		cerr << "Не удалось открыть файл для чтения." << endl << endl;
	}
}
