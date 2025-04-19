#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    errno_t err;
    FILE* f_1;
    int rowNumber, colNumber;

    err = fopen_s(&f_1, "matrix.txt", "r");
    if (err != 0) {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }
    printf_s("Какую строку вывести?\n");
    scanf_s("%d", &rowNumber);

    fscanf_s(f_1, "%d", &colNumber);

    if (rowNumber < 1 || rowNumber > colNumber) {
        printf("Некорректный номер строки.");
        fclose(f_1);
        exit(0);
    }

    FILE* f_2;
    err = fopen_s(&f_2, "row_matrix.txt", "w");
    if (err != 0) {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }

    float value;
    for (int i = 1; i <= colNumber; i++) {
        for (int j = 1; j <= colNumber; j++) {
            fscanf_s(f_1, "%f", &value);
            if (i == rowNumber) {
                fprintf_s(f_2, "%f ", value);
            }
        }
    }

    printf("Извлечение строки %d выполнено успешно\n", rowNumber);
    fclose(f_1);
    fclose(f_2);
    return 0;
}