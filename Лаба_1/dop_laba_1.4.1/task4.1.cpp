#include <iostream>
#include <cmath>
using namespace std;

double dichotomy(double (*equation)(double), double a, double b, double e) {
    while (abs(a - b) > 2 * e) {
        double x = (a + b) / 2;
        if (equation(a) * equation(x) <= 0)
            b = x;
        else
            a = x;
    }
    return (a + b) / 2;
}

double equation1(double x) {
    return pow(x, 3) + 2 * x - 1;
}

double equation2(double x) {
    return exp(x) - 2;
}

int main() {
    setlocale(LC_ALL, "ru");

    double a1, b1, a2, b2, e = 0.001;
    cout << "������� ����� ������� ��� ������� ���������: ";
    cin >> a1;
    cout << "������� ������ ������� ��� ������� ���������: ";
    cin >> b1;
    cout << "������� ����� ������� ��� ������� ���������: ";
    cin >> a2;
    cout << "������� ������ ������� ��� ������� ���������: ";
    cin >> b2;
    cout << endl;

    double root1 = dichotomy(equation1, a1, b1, e);
    double root2 = dichotomy(equation2, a2, b2, e);


    cout << "������ ������� ���������: " << root1 << endl;
    cout << "������ ������� ���������: " << root2 << endl;

    return 0;
}