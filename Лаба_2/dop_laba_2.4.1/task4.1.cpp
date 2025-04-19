#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    FILE* fileA, * fileB;
    errno_t errA, errB;
    errA = fopen_s(&fileA, "fileA.txt", "r");
    errB = fopen_s(&fileB, "fileB.txt", "w");

    if (errA != 0 || errB != 0) {
        perror("Не удалось открыть файлы.\n");
        return EXIT_FAILURE;
    }

    int number;
    while (fscanf_s(fileA, "%d", &number) == 1) {
        if (number > 0) {
            fprintf_s(fileB, "%d\n", number);
        }
    }

    fclose(fileA);
    fclose(fileB);

    printf("Файл fileB успешно создан.\n");

    return 0;
}