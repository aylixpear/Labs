#include <iostream>
#include <cassert>

#define main lab_main
#include "Lab_7_1_2.cpp"
#undef main

using namespace std;

int main() {
    const int rows = 2;
    const int cols = 3;
    int** R = new int*[rows];
    for (int i = 0; i < rows; i++) {
        R[i] = new int[cols];
    }

    R[0][0] = -4; R[0][1] = -2; R[0][2] = 5;
    R[1][0] = -3; R[1][1] = 0;  R[1][2] = 10;

    int S = 0;
    int k = 0;
    CalcRows(R, rows, cols, 0, S, k);

    assert(k == 5);
    assert(S == 10);
    assert(R[0][0] == -4);
    assert(R[0][1] == 0);
    assert(R[1][2] == 0);

    for (int i = 0; i < rows; i++) {
        delete[] R[i];
    }
    delete[] R;

    const int sRows = 4;
    const int sCols = 3;
    int** M = new int*[sRows];
    for (int i = 0; i < sRows; i++) {
        M[i] = new int[sCols];
    }

    M[0][0] = 5; M[0][1] = 2; M[0][2] = 9;
    M[1][0] = 8; M[1][1] = 1; M[1][2] = 4;
    M[2][0] = 5; M[2][1] = 2; M[2][2] = 3;
    M[3][0] = 5; M[3][1] = 7; M[3][2] = 1;

    SortRows(M, sRows, sCols, 0);

    assert(M[0][0] == 8);
    assert(M[1][1] == 7);
    assert(M[2][2] == 3);
    assert(M[3][2] == 9);

    for (int i = 0; i < sRows; i++) {
        delete[] M[i];
    }
    delete[] M;

    cout << "All tests passed!" << endl;
    return 0;
}