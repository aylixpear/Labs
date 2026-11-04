#include <iostream>
#include <cassert>
#include <cmath>

// Тестована функція h(a, b)
double h(const double a, const double b) {
    return (a / (b * b + 1)) + (1 / (a * a + b * b));
}

int main() {
    // Автоматична перевірка: h(1, 1) має дорівнювати 1.0
    double res = h(1.0, 1.0);
    assert(std::abs(res - 1.0) < 0.0001);

    std::cout << "Unit Test Passed Successfully!" << std::endl;
    return 0;
}