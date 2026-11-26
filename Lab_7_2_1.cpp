#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int MinInRow(int** a, const int rowNo, const int n) {
    int minVal = a[rowNo][0];
    for (int j = 1; j < n; j++) {
        if (a[rowNo][j] < minVal) {
            minVal = a[rowNo][j];
        }
    }
    return minVal;
}

int SumMinOddRows(int** a, const int k, const int n) {
    int S = 0;
    for (int i = 1; i < k; i += 2) {
        S += MinInRow(a, i, n);
    }
    return S;
}

int main() {
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    const int Low = -10;
    const int High = 50;

    int** a = new int*[k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int S = SumMinOddRows(a, k, n);
    cout << "S = " << S << endl;

    for (int i = 0; i < k; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}