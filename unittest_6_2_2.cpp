#include <iostream>
#include <cassert>
#include <cmath>

#define LINK_TEST
#include "Lab_6_2_2.cpp"

using namespace std;

void TestMixedElements() {
    const int size = 7;
    int arr[size] = {-4, 3, 2, 5, 8, -1, 10};

    // Непарні: 3, 5, -1 -> сума = 7, кількість = 3
    assert(fabs(AverageOdd(arr, size) - (7.0 / 3.0)) < 1e-6);
}

void TestNoOddElements() {
    const int size = 5;
    int arr[size] = {-4, -2, 0, 6, 8};

    assert(fabs(AverageOdd(arr, size) - 0.0) < 1e-6);
}

void TestAllOddElements() {
    const int size = 4;
    int arr[size] = {1, -3, 5, 7};

    // Сума = 10, кількість = 4 -> середнє = 2.5
    assert(fabs(AverageOdd(arr, size) - 2.5) < 1e-6);
}

int main() {
    TestMixedElements();
    TestNoOddElements();
    TestAllOddElements();

    cout << "All unit tests passed!" << endl;
    return 0;
}