#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    errno_t err;
    FILE* f_1;
    int colNumber, column;

    err = fopen_s(&f_1, "matrix.txt", "r");
    if (err != 0) {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }
    printf_s("Какой столбец вывести?\n");
    scanf_s("%d", &colNumber);

    fscanf_s(f_1, "%d", &column);

    if (colNumber < 1 || colNumber > column) {
        printf("Некорректный номер столбца.");
        fclose(f_1);
        exit(0);
    }

    FILE* f_2;
    err = fopen_s(&f_2, "col_matrix.txt", "w");
    if (err != 0) {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }

    float value;
    for (int i = 1; i <= colNumber; i++) {
        for (int j = 1; j <= colNumber; j++) {
            fscanf_s(f_1, "%f", &value);
            if (j == column) {
                fprintf_s(f_2, "%f\n", value);
            }
        }
    }
   
    printf("Извлечение столбца выполнено успешно\n");
    fclose(f_1);
    fclose(f_2);
    return 0;
}