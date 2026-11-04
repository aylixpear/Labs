#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main() {
    double xp, xk, dx, eps, s;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "--------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(16) << "ln((1+x)/(1-x))" << " |"
         << setw(12) << "S" << " |"
         << setw(5) << "n" << " |" << endl;
    cout << "--------------------------------------------------------" << endl;

    double x = xp;
    while (x <= xk) {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(16) << setprecision(5) << log((1 + x) / (1 - x)) << " |"
             << setw(12) << setprecision(5) << s << " |"
             << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "--------------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int &n, double &s) {
    n = 0;
    double a = x;
    s = a;
    while (abs(a) >= eps) {
        n++;
        A(x, n, a);
        s += a;
    }
    s *= 2; // Множник 2 перед сумою
}

void A(const double x, const int n, double &a) {
    double R = (x * x) * (2 * n - 1) / (2 * n + 1); // Рекурентний множник
    a *= R;
}