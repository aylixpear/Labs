// Lab_4_7.cpp
// Грушка Олександр
// Лабораторна робота № 4.7
// Обчислення суми нескінченного ряду (Варіант 5)

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double xp, xk, dx, eps, x, s, atan_exact, a;
  int n;

  // Введення початкових даних
  cout << "xp = ";
  cin >> xp;
  cout << "xk = ";
  cin >> xk;
  cout << "dx = ";
  cin >> dx;
  cout << "eps = ";
  cin >> eps;

  // Шапка таблиці
  cout << fixed;
  cout << "--------------------------------------------------------" << endl;
  cout << "|" << setw(8) << "X"
       << " |" << setw(12) << "arcctg(x)"
       << " |" << setw(12) << "S (Series)"
       << " |" << setw(8) << "N"
       << " |" << endl;
  cout << "--------------------------------------------------------" << endl;

  const double PI = atan(1.0) * 4.0; // Число Пі

  x = xp;
  while (x <= xk + dx / 2.0) {
    // Точне значення arcctg(x)
    atan_exact = PI / 2.0 - atan(x);

    // Початкові значення для суми ряду при n = 0
    n = 0;
    a = -x;           // перший член ряду
    s = PI / 2.0 + a; // початкова сума

    // Накопичення суми ряду із заданою точністю eps
    while (fabs(a) >= eps) {
      n++;
      // Рекурентна формула: R = -x^2 * (2n - 1) / (2n + 1)
      double R = -x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
      a *= R;
      s += a;
    }

    // Вивід рядка таблиці
    cout << "|" << setw(8) << setprecision(2) << x << " |" << setw(12)
         << setprecision(5) << atan_exact << " |" << setw(12) << setprecision(5)
         << s << " |" << setw(8) << n + 1 << " |" << endl;

    x += dx;
  }

  cout << "--------------------------------------------------------" << endl;

  return 0;
}