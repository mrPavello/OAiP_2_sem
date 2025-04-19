#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;


enum MENU {
	add = 1,
	view,
	deletion,
	search,
	complete
};

struct Contact {

	char full_name[50];
	char address[100];
	char phone[15];

	struct Birthday {
		unsigned day : 5;
		unsigned month : 4;
		unsigned year : 11;
	} birth_date;
};


void add_contact(Contact* notebook, int& num_contacts);
void view_contacts(Contact* notebook, int& num_contacts);
void deletion_contact(Contact* notebook, int& num_contacts, char* last_name);
void search_contact(Contact* notebook, int& num_contacts, char* last_name);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num_contacts = 0;
	Contact* notebook = new Contact[num_contacts];
	char last_name[10];
	int choice;

	do {
		cout << "����" << endl;
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ���������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� �������� �� �������" << endl;
		cout << "5 - �����" << endl << endl;
		cout << "����: "; cin >> choice;

		switch (choice) {
		case add: {
			add_contact(notebook, num_contacts);
		} break;
		case view: {
			view_contacts(notebook, num_contacts);
		} break;
		case deletion: {
			cin.ignore();
			cout << "������� �������: "; cin.getline(last_name, 10);
			cout << endl;
			deletion_contact(notebook, num_contacts, last_name);
		} break;
		case search: {
			cin.ignore();
			cout << "������� �������: "; cin.getline(last_name, 10);
			cout << endl;
			search_contact(notebook, num_contacts, last_name);
		} break;
		case complete: break;
		default: {
			cout << "������! ������� ��� ���." << endl;
		}
		}

	} while (choice != complete);


	return 0;
}

void add_contact(Contact* notebook, int& num_contacts) {
	cin.ignore();
	unsigned i;
	cout << "������� ���: "; cin.getline(notebook[num_contacts].full_name, 50);
	cout << "������� �����: "; cin.getline(notebook[num_contacts].address, 100);
	cout << "������� ����� ��������: "; cin.getline(notebook[num_contacts].phone, 15);
	cout << "������� ���� �������� (� ������� �� �� ����): ";
	cin >> i; notebook[num_contacts].birth_date.day = i;
	cin >> i; notebook[num_contacts].birth_date.month = i;
	cin >> i; notebook[num_contacts].birth_date.year = i;
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
			cout << "���� ��������: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << endl << endl;
		}
	}
}

void deletion_contact(Contact* notebook, int& num_contacts, char* last_name) {
	for (int i = 0; i < num_contacts; i++) {
		if (strstr(notebook[i].full_name, last_name) != nullptr) {
			for (int j = i; j < num_contacts - 1; j++) {
				notebook[j] = notebook[j + 1];
			}
			num_contacts--;
			cout << "������� ������� �����." << endl << endl;
			break;
		}
		else {
			cout << "������� �� ������." << endl << endl;
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
			cout << "���� ��������: " << notebook[i].birth_date.day << "." << notebook[i].birth_date.month << "." << notebook[i].birth_date.year << endl << endl;
			check = true;
		}
	}
	if (!check) {
		cout << "������� �� ������." << endl << endl;
	}
}