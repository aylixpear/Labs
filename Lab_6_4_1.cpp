#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void Create(double* arr, const int size, const double Low, const double High) {
    for (int i = 0; i < size; i++) {
        arr[i] = Low + (High - Low) * rand() / static_cast<double>(RAND_MAX);
    }
}

void Print(const double* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << setw(8) << arr[i];
    }
    cout << endl;
}

double MaxElement(const double* arr, const int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double SumBeforeLastPositive(const double* arr, const int size) {
    int lastPosIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            lastPosIndex = i;
        }
    }

    if (lastPosIndex <= 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < lastPosIndex; i++) {
        sum += arr[i];
    }
    return sum;
}

void Compress(double* arr, const int size, const double a, const double b) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (fabs(arr[i]) < a || fabs(arr[i]) > b) {
            arr[k++] = arr[i];
        }
    }
    while (k < size) {
        arr[k++] = 0.0;
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

    Create(arr, n, -10.0, 10.0);
    cout << "Initial array:" << endl;
    Print(arr, n);

    cout << "Max element = " << fixed << setprecision(2) << MaxElement(arr, n) << endl;
    cout << "Sum before last positive = " << fixed << setprecision(2) << SumBeforeLastPositive(arr, n) << endl;

    Compress(arr, n, a, b);
    cout << "Compressed array:" << endl;
    Print(arr, n);

    delete[] arr;
    return 0;
}
#endif