#include <stdio.h>
#include<iostream>

int main() {
    setlocale(LC_ALL, "ru");
    FILE* f, * g;
    errno_t errf, errg;
    errf = fopen_s(&f, "f.txt", "r");
    errg = fopen_s(&g, "g.txt", "w");

    if (errf != 0 || errg != 0) {
        perror("Не удалось открыть файлы.\n");
        return EXIT_FAILURE;
    }
    

    int number, value;
    printf("Введите пороговое значение: ");
    scanf_s("%d", &value);

    while (fscanf_s(f, "%d", &number) != EOF) {
        if (number > value) {
            fprintf(g, "%d\n", number);
        }
    }

    fclose(f);
    fclose(g);

    printf("Файл g успешно создан.\n");

    return 0;
}