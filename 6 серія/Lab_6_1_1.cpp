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

int Count(const int* a, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int Sum(const int* a, const int size) {
    int s = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            s += a[i];
        }
    }
    return s;
}

void Zero(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            a[i] = 0;
        }
    }
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

    cout << "Count = " << Count(a, n) << endl;
    cout << "Sum = " << Sum(a, n) << endl;

    Zero(a, n);
    Print(a, n);

    return 0;
}
#endif