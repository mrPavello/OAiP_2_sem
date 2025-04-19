#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream in("FILE1.txt");
    if (!in.is_open()) {
        cout << "Error! FILE1.txt doesn't open!";
        return -1;
    }
    ofstream out("FILE2.txt");
    if (!out.is_open()) {
        cout << "Error! FILE2.txt doesn't open!";
        return -1;
    }
    string line, first_word, word;
    int count_letters = 0;
    char c;
    
    in >> first_word;
    
    in.seekg(0, ios::beg);
    while (getline(in, line)) {
        if (line.find(first_word) != string::npos) {
            out << line << endl;
        }
    }
    out.close();
    ifstream in_2("FILE2.txt");
    if (!in_2.is_open()) {
        cout << "Error! FILE2.txt doesn't open!";
        return -1;
    }
    while (in_2 >> c) {
        if (c != ' ' && c != '.' && c != ',') {
            count_letters++;
        }
    }
    cout << "Count of letters in FILE2.txt " << count_letters << endl;
    in.close();
   
    return 0;
}