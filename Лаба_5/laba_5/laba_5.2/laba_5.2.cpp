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

	cout << "���������� ��������:" << endl;
	add_contact(notebook, num_contacts);

	cout << "�������� ���������:" << endl;
	view_contacts(notebook, num_contacts);

	cout << "����� ��������:" << endl;
	cout << "������� �������: "; cin.getline(names.last_name, 10);
	cout << endl;
	search_contact(notebook, num_contacts, names.last_name);

	cout << "������ � ����:" << endl;
	cout << "������� ��� �����: "; cin.getline(names.file_name, 10);
	cout << endl;
	write_to_file(notebook, num_contacts, names.file_name);

	cout << "������ �� �����:" << endl;
	cout << "������� ��� �����: "; cin.getline(names.file_name, 10);
	cout << endl;
	read_from_file(notebook, num_contacts, names.file_name);

	return 0;
}

void add_contact(Contact* notebook, int& num_contacts) {
	unsigned i;
	cout << "������� ���: "; cin.getline(notebook[num_contacts].full_name, 50);
	cout << "������� �����: "; cin.getline(notebook[num_contacts].address, 100);
	cout << "������� ����� ��������: "; cin.getline(notebook[num_contacts].phone, 15);
	cout << "������� ���� �������� (� ������� �� �� ����): ";
	cin >> i; notebook[num_contacts].birth_date.day = i;
	cin >> i; notebook[num_contacts].birth_date.month = i;
	cin >> i; notebook[num_contacts].birth_date.year = i;
	cin.ignore();
	cout << "������� ����� ������, ����� ������� ���: "; cin.getline(notebook[num_contacts].status.work_place, 50);
	cout << "������� ���������: "; cin.getline(notebook[num_contacts].status.position, 30);
	cout << "������� ����� �����, ����� ������� ���: "; cin.getline(notebook[num_contacts].status.study_place, 50);

	num_contacts++;
	cout << endl << "������� ������� �������!" << endl << endl;
}

void view_contacts(Contact* notebook, int& num_contacts) {
	if (num_contacts == 0) {
		cout << "� ����� �����." << endl << endl;
	}
	else {
		for (int i = 0; i < num_contacts; i++) {
			cout << "���: " << notebook[i].full_name << endl;
			cout << "�����: " << notebook[i].address << endl;
			cout << "�������: " << notebook[i].phone << endl;
			cout << "���� ��������: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << endl;
			cout << "����� �����: " << notebook[num_contacts].status.study_place << endl;
			cout << "����� ������: " << notebook[num_contacts].status.work_place << endl;
			cout << "���������: " << notebook[num_contacts].status.position << endl << endl;
		}
	}
}

void search_contact(Contact* notebook, int& num_contacts, char* last_name) {
	bool check = false;
	for (int i = 0; i < num_contacts; i++) {
		if (strstr(notebook[i].full_name, last_name) != nullptr) {
			cout << "���: " << notebook[i].full_name << endl;
			cout << "�����: " << notebook[i].address << endl;
			cout << "�������: " << notebook[i].phone << endl;
			cout << "���� ��������: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << endl;
			cout << "����� �����: " << notebook[num_contacts].status.study_place << endl;
			cout << "����� ������: " << notebook[num_contacts].status.work_place << endl;
			cout << "���������: " << notebook[num_contacts].status.position << endl << endl;
			check = true;
		}
	}
	if (!check) {
		cout << "������� �� ������." << endl << endl;
	}
}

void write_to_file(Contact* notebook, int& num_contacts, char* file_name) {
	ofstream file(file_name, ios::app);
	if (file.is_open()) {
		for (int i = 0; i < num_contacts; i++) {
			file << "���: " << notebook[i].full_name << '\n'
				<< "�����: " << notebook[i].address << '\n'
				<< "�������: " << notebook[i].phone << '\n'
				<< "���� ��������: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << '\n'
				<< "����� ������: " << notebook[num_contacts].status.work_place << '\n'
				<< "���������: " << notebook[num_contacts].status.position << '\n'
				<< "����� �����: " << notebook[num_contacts].status.study_place << '\n' << '\n';
		}
		cout << "���������� ������� �������� � ����." << endl << endl;
		file.close();
	}
	else {
		cerr << "�� ������� ������� ���� ��� ������." << endl << endl;
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

		cout << "���������� ������� �������!" << endl << endl;
		file.close();
	}
	else {
		cerr << "�� ������� ������� ���� ��� ������." << endl << endl;
	}
}
