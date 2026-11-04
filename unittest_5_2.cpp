#include <iostream>
#include <cassert>
#include <cmath>

void A(const double x, const int n, double &a) {
    double R = (x * x) * (2 * n - 1) / (2 * n + 1);
    a *= R;
}

void S(const double x, const double eps, int &n, double &s) {
    n = 0;
    double a = x;
    s = a;
    while (std::abs(a) >= eps) {
        n++;
        A(x, n, a);
        s += a;
    }
    s *= 2;
}

int main() {
    double s;
    int n;
    S(0.5, 0.0001, n, s);

    double expected = std::log((1.0 + 0.5) / (1.0 - 0.5)); // ln(3)
    assert(std::abs(s - expected) < 0.001);

    std::cout << "Unit Test Passed Successfully!" << std::endl;
    return 0;
}