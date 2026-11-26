#include <iostream>
#include <cassert>

#define main lab_main
#include "Lab_7_2_1.cpp"
#undef main

using namespace std;

int main() {
    const int k = 4;
    const int n = 3;
    int** a = new int*[k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    a[0][0] = 100; a[0][1] = 200; a[0][2] = 300;
    a[1][0] = 5;   a[1][1] = -3;  a[1][2] = 8;
    a[2][0] = -50; a[2][1] = -60; a[2][2] = -70;
    a[3][0] = 12;  a[3][1] = 4;   a[3][2] = 9;

    assert(MinInRow(a, 1, n) == -3);
    assert(MinInRow(a, 3, n) == 4);
    assert(SumMinOddRows(a, k, n) == 1);
    assert(SumMinOddRows(a, 1, n) == 0);

    for (int i = 0; i < k; i++) {
        delete[] a[i];
    }
    delete[] a;

    cout << "All tests passed!" << endl;
    return 0;
}