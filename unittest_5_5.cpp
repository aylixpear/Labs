#include <iostream>
#include <cassert>

using namespace std;

int Q(int m, int n, int level, int &depth) {
    if (level > depth) depth = level;
    if (m == 1 || n == 1) return 1;
    if (m < n) return Q(n, m, level + 1, depth);
    if (m == n) return 1 + Q(m, m - 1, level + 1, depth);
    return Q(m, n - 1, level + 1, depth) + Q(m - n, n, level + 1, depth);
}

int main() {
    int depth = 0;
    

    assert(Q(4, 4, 1, depth) == 5);
    

    depth = 0;
    assert(Q(5, 3, 1, depth) == 5);

    cout << "Unit Test Passed Successfully!" << endl;
    return 0;
}