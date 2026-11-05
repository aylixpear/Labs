#include <iostream>
#include <iomanip>

using namespace std;


int Q(int m, int n, int level, int &depth) {

    if (level > depth) {
        depth = level;
    }


    if (m == 1 || n == 1) {
        return 1;
    }


    if (m < n) {
        return Q(n, m, level + 1, depth);
    }


    if (m == n) {
        return 1 + Q(m, m - 1, level + 1, depth);
    }


    return Q(m, n - 1, level + 1, depth) + Q(m - n, n, level + 1, depth);
}

int main() {
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;

    int depth = 0;
    int res = Q(m, n, 1, depth);

    cout << "Q(" << m << ", " << n << ") = " << res << endl;
    cout << "Depth of recursion = " << depth << endl;

    return 0;
}