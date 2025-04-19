#include <iostream>

using namespace std;

int* func_array(int size, int* array, ...) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (array[i] < 0) {
			count++;
		}
	}
	int *array_2(new int[size]);
	int c_i = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] >= 0) {
			array_2[c_i] = array[i];
			c_i++;
		}
	}
	
	for (c_i; c_i < size; c_i++) {
		array_2[c_i] = 0;
	}
	
	if (count > 0) {
		return array_2;
	}
	else return array;
}

int main() {
	setlocale(LC_ALL, "ru");

	int size;

	cout << "Введите размер массива: "; cin >> size;

	int* array(new int[size]);

	cout << "Заполните массив: ";	
	for (int i = 0; i < size; i++) {
		cout << "\nA[" << i + 1 << "] = "; cin >> *(array + i);
	}
	int* new_array(new int[size]);
	new_array = func_array(size, array, array);
	bool check = true;

	for (int i = 0; i < size; i++) {
		if (array[i] == new_array[i]) {
			check = false;
		}
	}
	if (!check) {
		cout << "В массиве нет отрицательных элементов." << endl;
	}
	else {
		cout << "Изменённый массив:" << endl;
		for (int i = 0; i < size; i++) {
			cout << new_array[i] << "  ";
		}
	}
	
	return 0;
}