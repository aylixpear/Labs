#include <iostream>
#include <cassert>
#include <cmath>

double h(const double x) {
    if (std::abs(x) >= 1 || x == 0) {
        return (std::cos(x) + 1) / std::exp(x);
    } else {
        double a = x * x;
        double s = a;
        for (int n_idx = 1; n_idx <= 6; n_idx++) {
            double R = (x * x * x * x) / (2 * n_idx * (2 * n_idx + 1));
            a *= R;
            s += a;
        }
        return (1 / std::sin(x * x)) * s;
    }
}

int main() {
    // Тест 1: при x = 0 перша гілка h(0) = (cos(0)+1)/e^0 = 2.0
    double res1 = h(0.0);
    assert(std::abs(res1 - 2.0) < 0.0001);

    // Тест 2: при x = 0.5 друга гілка (сума ряду)
    double res2 = h(0.5);
    assert(std::abs(res2 - 1.02105) < 0.0001);

    std::cout << "Unit Test Passed Successfully!" << std::endl;
    return 0;
}