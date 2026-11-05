#include <iostream>
#include <cmath>
#include <iomanip>

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

double P2(const int K, const int N, const int i) {
    if (i < K)
        return 1.0;
    else
        return a(i) * P2(K, N, i - 1);
}

double P3(const int K, const int N, const int i, double t) {
    t = t * a(i);
    if (i >= N)
        return t;
    else
        return P3(K, N, i + 1, t);
}

double P4(const int K, const int N, const int i, double t) {
    t = t * a(i);
    if (i <= K)
        return t;
    else
        return P4(K, N, i - 1, t);
}

int main() {
    int K = 1;
    int N = 15;

    cout << fixed << setprecision(10);
    cout << "(iter)        P0 = " << P0(K, N) << endl;
    cout << "(rec up ++)   P1 = " << P1(K, N, K) << endl;
    cout << "(rec up --)   P2 = " << P2(K, N, N) << endl;
    cout << "(rec down ++) P3 = " << P3(K, N, K, 1.0) << endl;
    cout << "(rec down --) P4 = " << P4(K, N, N, 1.0) << endl;

    return 0;
}