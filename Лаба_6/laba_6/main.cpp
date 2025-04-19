#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    double value;
    Node* next;
};

Node* add_node(Node* head, double value) {
    Node* new_node = new Node;
    new_node->value = value;
    new_node->next = head;
    head = new_node;
    return head;
}

bool delete_node(Node*& head, double value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

Node* find_node(Node* head, double value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void print_list(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void write_to_file(Node* head, const string& filename) {
    ofstream file(filename);

    Node* current = head;

    while (current != nullptr) {
        file << current->value << " ";
        current = current->next;
    }

    file.close();
}

Node* read_from_file(const string& filename) {
    ifstream inFile(filename);
    Node* head = nullptr;
    double value;

    while (inFile >> value) {
        head = add_node(head, value);
    }

    inFile.close();
    return head;
}

double calculation(Node* head) {
    double sum = 0;
    int count = 0;

    Node* current = head;

    while (current != nullptr) {
        if (current->value > 0) {
            sum += current->value;
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

int main() {
    setlocale(LC_ALL, "ru");
    Node* head = nullptr;

    int choice;
    double value;
    string filename;

    do {
        cout << endl << "Меню: " << endl;
        cout << "1 - добавить элемент" << endl;
        cout << "2 - удалить элемент" << endl;
        cout << "3 - найти элемнет" << endl;
        cout << "4 - печать списка" << endl;
        cout << "5 - запись в файл" << endl;
        cout << "6 - чтение из файла" << endl;
        cout << "7 - среднее значение положительных элемнетов" << endl;
        cout << "0 - выход" << endl;
        cout << "Ваш выбор: "; cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите число для добавления: ";
            cin >> value;
            head = add_node(head, value);
            break;
        case 2:
            cout << "Введите число, которое удалить: ";
            cin >> value;
            if (!delete_node(head, value)) {
                cout << "Число не найдено!" << endl;
            }
            break;
        case 3:
            cout << "Введите число, которое найти: ";
            cin >> value;
            if (find_node(head, value) != nullptr) {
                cout << "Число найдено!" << endl;
            }
            else {
                cout << "Число не найдено!" << endl;
            }
            break;
        case 4:
            print_list(head);
            break;
        case 5:
            cout << "Введите имя файла: ";
            cin >> filename;
            write_to_file(head, filename);
            break;
        case 6:
            cout << "Введите имя файла: ";
            cin >> filename;
            head = read_from_file(filename);
            break;
        case 7:
            cout << "Среднее значение положительных элементов: " << calculation(head) << endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Некорректный ввод, попробуйте еще раз!" << endl;
        }
    } while (choice != 0);

    return 0;
}