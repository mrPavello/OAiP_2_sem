#include <stdio.h>
#include <iostream>


int main() {
    setlocale(LC_ALL, "ru");
    FILE* fileA, * fileB, * fileC, * fileD;
    errno_t errA, errB, errC, errD;
    int numA, numB, numC;

    errA = fopen_s(&fileA, "NameA.txt", "r");
    errB = fopen_s(&fileB, "NameB.txt", "r");
    errC = fopen_s(&fileC, "NameC.txt", "r");

    if (errA != 0 || errB != 0 || errC != 0) {
        perror("Ошибка при открытии файлов.\n");
        return EXIT_FAILURE;
    }

    errD = fopen_s(&fileD, "NameD.txt", "w");

    if (errD != 0) {
        perror("Ошибка при создании файла NameD.txt.\n");
        return EXIT_FAILURE;
    }

    while (fscanf_s(fileA, "%d", &numA) != EOF && fscanf_s(fileB, "%d", &numB) != EOF && fscanf_s(fileC, "%d", &numC) != EOF) {
        int minElement = numA > numB ? (numA > numC ? numA : numC) : (numB > numC ? numB : numC);
        fprintf(fileD, "%d ", minElement);
    }

    fclose(fileA);
    fclose(fileB);
    fclose(fileC);
    fclose(fileD);

    printf("Файл NameD.txt успешно создан.\n");

    return 0;
}