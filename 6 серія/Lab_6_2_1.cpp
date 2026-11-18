#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

double AverageOdd(const int* a, const int size) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            sum += a[i];
            count++;
        }
    }
    if (count == 0)
        return 0.0;
    return static_cast<double>(sum) / count;
}

#ifndef LINK_TEST
int main() {
    srand((unsigned)time(NULL));

    const int n = 25;
    const int Low = -20;
    const int High = 30;

    int a[n];

    Create(a, n, Low, High);
    Print(a, n);

    cout << "Average of odd elements = " << AverageOdd(a, n) << endl;

    return 0;
}
#endif