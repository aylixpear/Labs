#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double h(const double x);

int main() {
    double rPoch, rKin;
    int n;

    cout << "rPoch = "; cin >> rPoch;
    cout << "rKin  = "; cin >> rKin;
    cout << "n     = "; cin >> n;

    double dr = (rKin - rPoch) / n;

    cout << fixed;
    cout << "----------------------------------" << endl;
    cout << "|" << setw(10) << "r" << " |"
         << setw(18) << "y" << " |" << endl;
    cout << "----------------------------------" << endl;

    double r = rPoch;
    while (r <= rKin) {
        double y = h(r + 1) + pow(h(r * r + 1), 2) + 1;
        cout << "|" << setw(10) << setprecision(2) << r << " |"
             << setw(18) << setprecision(5) << y << " |" << endl;
        r += dr;
    }
    cout << "----------------------------------" << endl;

    return 0;
}

double h(const double x) {
    if (abs(x) >= 1 || x == 0) {
        return (cos(x) + 1) / exp(x);
    } else {
        double a = x * x; // перший доданок при n = 0
        double s = a;
        for (int n_idx = 1; n_idx <= 6; n_idx++) {
            double R = (x * x * x * x) / (2 * n_idx * (2 * n_idx + 1)); // Рекурентний множник
            a *= R;
            s += a;
        }
        return (1 / sin(x * x)) * s;
    }
}