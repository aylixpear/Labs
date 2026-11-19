#include <iostream>
#include <cassert>

#define LINK_TEST
#include "Lab_6_1_1.cpp"

using namespace std;

void TestMixedElements() {
    const int size = 7;
    int arr[size] = {-4, 0, 2, 5, 8, -2, 10};

    assert(Count(arr, size) == 3);
    assert(Sum(arr, size) == 20);

    Zero(arr, size);
    int expected[size] = {-4, 0, 0, 5, 0, -2, 0};
    for (int i = 0; i < size; i++) {
        assert(arr[i] == expected[i]);
    }
}

void TestNoMatchingElements() {
    const int size = 5;
    int arr[size] = {-6, -1, 0, 3, 7};

    assert(Count(arr, size) == 0);
    assert(Sum(arr, size) == 0);

    Zero(arr, size);
    int expected[size] = {-6, -1, 0, 3, 7};
    for (int i = 0; i < size; i++) {
        assert(arr[i] == expected[i]);
    }
}

void TestAllMatchingElements() {
    const int size = 4;
    int arr[size] = {2, 4, 6, 30};

    assert(Count(arr, size) == 4);
    assert(Sum(arr, size) == 42);

    Zero(arr, size);
    int expected[size] = {0, 0, 0, 0};
    for (int i = 0; i < size; i++) {
        assert(arr[i] == expected[i]);
    }
}

int main() {
    TestMixedElements();
    TestNoMatchingElements();
    TestAllMatchingElements();

    cout << "All unit tests passed!" << endl;
    return 0;
}