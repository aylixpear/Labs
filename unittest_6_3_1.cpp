#include <iostream>
#include <cassert>
#include <cmath>

#define LINK_TEST
#include "Lab_6_3_1.cpp"

using namespace std;

void TestSortInt() {
    const int size = 6;
    int arr[size] = {3, -5, 10, 3, 0, 8};
    int expected[size] = {10, 8, 3, 3, 0, -5};

    Sort(arr, size);

    for (int i = 0; i < size; i++) {
        assert(arr[i] == expected[i]);
    }
}

void TestSortDoubleTemplate() {
    const int size = 5;
    double arr[size] = {1.5, -2.3, 4.8, 1.5, 0.0};
    double expected[size] = {4.8, 1.5, 1.5, 0.0, -2.3};

    Sort(arr, size);

    for (int i = 0; i < size; i++) {
        assert(fabs(arr[i] - expected[i]) < 1e-6);
    }
}

int main() {
    TestSortInt();
    TestSortDoubleTemplate();

    cout << "All unit tests passed!" << endl;
    return 0;
}