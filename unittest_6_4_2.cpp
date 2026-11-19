#include <iostream>
#include <cassert>
#include <cmath>

#define LINK_TEST
#include "Lab_6_4_2.cpp"

using namespace std;

void TestMaxElement() {
    const int size = 5;
    double arr[size] = {-4.5, 2.1, 9.8, 0.0, -1.2};
    assert(fabs(MaxElement(arr, size) - 9.8) < 1e-6);
}

void TestSumBeforeLastPositive() {
    const int size1 = 5;
    double arr1[size1] = {-3.0, 4.5, -1.5, 2.0, -5.0};
    assert(fabs(SumBeforeLastPositive(arr1, size1) - 0.0) < 1e-6);

    const int size2 = 4;
    double arr2[size2] = {1.5, -2.0, 3.5, 4.0};
    assert(fabs(SumBeforeLastPositive(arr2, size2) - 3.0) < 1e-6);

    const int size3 = 3;
    double arr3[size3] = {-1.0, -2.5, 0.0};
    assert(fabs(SumBeforeLastPositive(arr3, size3) - 0.0) < 1e-6);
}

void TestCompress() {
    const int size = 6;
    double arr[size] = {-1.5, 3.0, -4.5, 6.2, 2.0, 0.5};
    double expected[size] = {-1.5, 6.2, 0.5, 0.0, 0.0, 0.0};

    Compress(arr, size, 2.0, 5.0);

    for (int i = 0; i < size; i++) {
        assert(fabs(arr[i] - expected[i]) < 1e-6);
    }
}

int main() {
    TestMaxElement();
    TestSumBeforeLastPositive();
    TestCompress();

    cout << "All unit tests passed!" << endl;
    return 0;
}