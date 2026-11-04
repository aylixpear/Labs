// Грушка Олександр

#include <iostream>
#include <cassert>
#include <cmath>

// Функція h(x, y, z) з твоєї лабораторної 5.1
double h(const double x, const double y, const double z) {
    return (x * x + x * z - y * z + y * y) / (x * x + std::abs(x * y * z) + y * z);
}

int main() {
    // Автоматична перевірка: викликаємо h(1, -3, 1) і звіряємо з 14.0
    double res = h(1, -3, 1);
    assert(std::abs(res - 14.0) < 0.0001);

    std::cout << "Unit Test Passed Successfully!" << std::endl;
    return 0;
}