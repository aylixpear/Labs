#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1) {
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
    }
}

void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1) {
        CreateRows(a, k, n, Low, High, rowNo + 1);
    }
}

void PrintRow(int** a, const int rowNo, const int n, int colNo) {
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < n - 1) {
        PrintRow(a, rowNo, n, colNo + 1);
    } else {
        cout << endl;
    }
}

void PrintRows(int** a, const int k, const int n, int rowNo) {
    if (rowNo == 0) {
        cout << endl;
    }
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1) {
        PrintRows(a, k, n, rowNo + 1);
    } else {
        cout << endl;
    }
}

int MinInRow(int** a, const int rowNo, const int n, int colNo, int minVal) {
    if (a[rowNo][colNo] < minVal) {
        minVal = a[rowNo][colNo];
    }
    if (colNo < n - 1) {
        return MinInRow(a, rowNo, n, colNo + 1, minVal);
    }
    return minVal;
}

int SumMinOddRows(int** a, const int k, const int n, int rowNo) {
    if (rowNo >= k) {
        return 0;
    }
    int minVal = MinInRow(a, rowNo, n, 0, a[rowNo][0]);
    return minVal + SumMinOddRows(a, k, n, rowNo + 2);
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

    CreateRows(a, k, n, Low, High, 0);
    PrintRows(a, k, n, 0);

    int S = SumMinOddRows(a, k, n, 1);
    cout << "S = " << S << endl;

    for (int i = 0; i < k; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}