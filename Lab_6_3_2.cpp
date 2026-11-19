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
        cout << setw(5) << a[i];
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

void Sort(int* a, const int size, int i = 0, int j = 0) {
    if (i < size - 1) {
        if (j < size - i - 1) {
            if (a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
            Sort(a, size, i, j + 1);
        } else {
            Sort(a, size, i + 1, 0);
        }
    }
}

template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i) {
    if (i < size) {
        a[i] = Low + (High - Low) * rand() / static_cast<T>(RAND_MAX);
        Create(a, size, Low, High, i + 1);
    }
}

template <typename T>
void Print(const T* a, const int size, int i) {
    if (i < size) {
        cout << fixed << setprecision(2) << setw(8) << a[i];
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

template <typename T>
void Sort(T* a, const int size, int i = 0, int j = 0) {
    if (i < size - 1) {
        if (j < size - i - 1) {
            if (a[j] < a[j + 1]) {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
            Sort(a, size, i, j + 1);
        } else {
            Sort(a, size, i + 1, 0);
        }
    }
}

#ifndef LINK_TEST
int main() {
    srand((unsigned)time(NULL));

    const int n = 10;

    int a[n];
    Create(a, n, -20, 30, 0);
    cout << "Int array before sort:" << endl;
    Print(a, n, 0);

    Sort(a, n);
    cout << "Int array after sort:" << endl;
    Print(a, n, 0);

    cout << endl;

    double b[n];
    Create(b, n, -10.0, 20.0, 0);
    cout << "Double array before sort:" << endl;
    Print(b, n, 0);

    Sort(b, n);
    cout << "Double array after sort:" << endl;
    Print(b, n, 0);

    return 0;
}
#endif