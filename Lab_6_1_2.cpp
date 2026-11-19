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

int Count(const int* a, const int size, int i) {
    if (i < size) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            return 1 + Count(a, size, i + 1);
        } else {
            return Count(a, size, i + 1);
        }
    } else {
        return 0;
    }
}

int Sum(const int* a, const int size, int i) {
    if (i < size) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            return a[i] + Sum(a, size, i + 1);
        } else {
            return Sum(a, size, i + 1);
        }
    } else {
        return 0;
    }
}

void Zero(int* a, const int size, int i) {
    if (i < size) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            a[i] = 0;
        }
        Zero(a, size, i + 1);
    }
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

    cout << "Count = " << Count(a, n, 0) << endl;
    cout << "Sum = " << Sum(a, n, 0) << endl;

    Zero(a, n, 0);
    Print(a, n, 0);

    return 0;
}
#endif