#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

double a(const int i) {
    return (pow(sin(1.0 * i), 2) + pow(cos(1.0 / i), 2)) / (1.0 * i * i);
}

double P0(const int K, const int N) {
    double p = 1.0;
    for (int i = K; i <= N; i++) {
        p *= a(i);
    }
    return p;
}

double P1(const int K, const int N, const int i) {
    if (i > N)
        return 1.0;
    else
        return a(i) * P1(K, N, i + 1);
}

int main() {

    double res_iter = P0(1, 15);
    double res_rec = P1(1, 15, 1);

    assert(abs(res_iter - res_rec) < 1e-10);

    cout << "Unit Test Passed Successfully!" << endl;
    return 0;
}