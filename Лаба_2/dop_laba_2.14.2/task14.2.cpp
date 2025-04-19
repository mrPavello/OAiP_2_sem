#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    FILE* f, * g;
    errno_t errf, errg;
    int num;
    errf = fopen_s(&f, "f.txt", "r");
    errg = fopen_s(&g, "g.txt", "w");

    if (errf != 0 || errg != 0) {
        perror("Не удалось открыть файлы.\n");
        return EXIT_FAILURE;
    }

    while (fscanf_s(f, "%d", &num) == 1) {
        bool find = 0;
        fseek(g, 0, SEEK_SET);
        while (!feof(g)) {
            int current;
            fscanf_s(g, "%d", &current);
            if (current == num) {
                find = 1;
                break;
            }
        }

        if (!find) {
            fprintf_s(g, "%d\n", num);
        }
    }

    fclose(f);
    fclose(g);

    printf("Файл g.txt успешно создан.\n");

    return 0;
}