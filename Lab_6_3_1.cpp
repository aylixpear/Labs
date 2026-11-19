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
        cout << setw(5) << a[i];
    }
    cout << endl;
}

void Sort(int* a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

template <typename T>
void Create(T* a, const int size, const T Low, const T High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + (High - Low) * rand() / static_cast<T>(RAND_MAX);
    }
}

template <typename T>
void Print(const T* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << setw(8) << a[i];
    }
    cout << endl;
}

template <typename T>
void Sort(T* a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

#ifndef LINK_TEST
int main() {
    srand((unsigned)time(NULL));

    const int n = 10;

    int a[n];
    Create(a, n, -20, 30);
    cout << "Int array before sort:" << endl;
    Print(a, n);

    Sort(a, n);
    cout << "Int array after sort:" << endl;
    Print(a, n);

    cout << endl;

    double b[n];
    Create(b, n, -10.0, 20.0);
    cout << "Double array before sort:" << endl;
    Print(b, n);

    Sort(b, n);
    cout << "Double array after sort:" << endl;
    Print(b, n);

    return 0;
}
#endif