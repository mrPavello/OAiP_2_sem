#include <cstdarg>
#include <iostream>
using namespace std;

int fmin(int count, ...) {
    va_list args;
    va_start(args, count);

    int maxVal = va_arg(args, int);

    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val > maxVal) {
            maxVal = val;
        }
    }

    va_end(args);

    return maxVal;
}

int main() {
    setlocale(LC_ALL, "ru");

    int max1 = fmin(3, 5, 2, 7);
    cout << "Максимальное среди чисел 5, 2, 7 это " << max1 << endl;
    int max2 = fmin(4, 10, 15, 3, 8);
    cout << "Максимальное среди чисел 10, 15, 3, 8 это " << max2 << endl;
    int max3 = fmin(2, 100, 200);
    cout << "Максимальное среди чисел 100, 200 это " << max3 << endl;

    return 0;
}