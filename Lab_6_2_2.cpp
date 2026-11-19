#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) {
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

void Print(const int* a, const int size, int i) {
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

double AverageOdd(const int* a, const int size, int i = 0, int sum = 0, int count = 0) {
    if (i < size) {
        if (a[i] % 2 != 0) {
            sum += a[i];
            count++;
        }
        return AverageOdd(a, size, i + 1, sum, count);
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

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "Average of odd elements = " << AverageOdd(a, n) << endl;

    return 0;
}
#endif