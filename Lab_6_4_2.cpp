#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void Create(double* arr, const int size, const double Low, const double High, int i) {
    if (i < size) {
        arr[i] = Low + (High - Low) * rand() / static_cast<double>(RAND_MAX);
        Create(arr, size, Low, High, i + 1);
    }
}

void Print(const double* arr, const int size, int i) {
    if (i < size) {
        cout << fixed << setprecision(2) << setw(8) << arr[i];
        Print(arr, size, i + 1);
    } else {
        cout << endl;
    }
}

double MaxElement(const double* arr, const int size, int i = 0) {
    if (size <= 0) {
        return 0.0;
    }
    if (i == size - 1) {
        return arr[i];
    }
    double restMax = MaxElement(arr, size, i + 1);
    return (arr[i] > restMax) ? arr[i] : restMax;
}

int FindLastPositive(const double* arr, int i) {
    if (i < 0) {
        return -1;
    }
    if (arr[i] > 0) {
        return i;
    }
    return FindLastPositive(arr, i - 1);
}

double SumToIndex(const double* arr, int lastIndex, int i = 0) {
    if (i >= lastIndex) {
        return 0.0;
    }
    return arr[i] + SumToIndex(arr, lastIndex, i + 1);
}

double SumBeforeLastPositive(const double* arr, const int size) {
    int lastPosIndex = FindLastPositive(arr, size - 1);
    if (lastPosIndex <= 0) {
        return 0.0;
    }
    return SumToIndex(arr, lastPosIndex, 0);
}

void Compress(double* arr, const int size, const double a, const double b, int i = 0, int k = 0) {
    if (i < size) {
        if (fabs(arr[i]) < a || fabs(arr[i]) > b) {
            arr[k] = arr[i];
            Compress(arr, size, a, b, i + 1, k + 1);
        } else {
            Compress(arr, size, a, b, i + 1, k);
        }
    } else if (k < size) {
        arr[k] = 0.0;
        Compress(arr, size, a, b, i, k + 1);
    }
}

#ifndef LINK_TEST
int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int n;
    double a, b;

    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    cout << "Enter interval [a, b]: ";
    cin >> a >> b;

    double* arr = new double[n];

    Create(arr, n, -10.0, 10.0, 0);
    cout << "Initial array:" << endl;
    Print(arr, n, 0);

    cout << "Max element = " << fixed << setprecision(2) << MaxElement(arr, n) << endl;
    cout << "Sum before last positive = " << fixed << setprecision(2) << SumBeforeLastPositive(arr, n) << endl;

    Compress(arr, n, a, b);
    cout << "Compressed array:" << endl;
    Print(arr, n, 0);

    delete[] arr;
    return 0;
}
#endif