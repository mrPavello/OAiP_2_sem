#include <cstdarg>
#include <iostream>
using namespace std;

int fmin(int count, ...) {
    va_list args;
    va_start(args, count);

    int minVal = va_arg(args, int);

    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val < minVal) {
            minVal = val;
        }
    }

    va_end(args);

    return minVal;
}

int main() {
    setlocale(LC_ALL, "ru");

    int min1 = fmin(3, 5, 2, 7);
    cout << "Минимальное среди чисел 5, 2, 7 это " << min1 << endl;
    int min2 = fmin(4, 10, 15, 3, 8);
    cout << "Минимальное среди чисел 10, 15, 3, 8 это " << min2 << endl;
    int min3 = fmin(2, 100, 200);
    cout << "Минимальное среди чисел 100, 200 это " << min3 << endl;

    return 0;
}