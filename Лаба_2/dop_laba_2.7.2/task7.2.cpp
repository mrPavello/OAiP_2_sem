#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    FILE* A, * B, * C, * D;
    errno_t errA, errB, errC, errD;
    int numA, numB, numC;

    errA = fopen_s(&A, "A.txt", "r");
    errB = fopen_s(&B, "B.txt", "r");
    errC = fopen_s(&C, "C.txt", "r");

    if (errA != 0 || errB != 0 || errC != 0) {
        perror("Ошибка при открытии файлов.\n");
        return EXIT_FAILURE;
    }

    errD = fopen_s(&D, "D.txt", "w");

    if (errD != 0) {
        perror("Ошибка при создании файла NameD.txt.\n");
        return EXIT_FAILURE;
    }

    while (fscanf_s(A, "%d", &numA) == 1 && fscanf_s(B, "%d", &numB) == 1 && fscanf_s(C, "%d", &numC) == 1) {
        fprintf_s(D, "%d\n%d\n%d\n", numA, numB, numC);
    }

    fclose(A);
    fclose(B);
    fclose(C);
    fclose(D);

    printf("Файл D успешно создан.\n");

    return 0;
}