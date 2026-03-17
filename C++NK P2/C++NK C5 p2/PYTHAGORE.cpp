#include <bits/stdc++.h>
using namespace std;

int countRightTriangles(int P) {
    if (P % 2 != 0) return 0;

    int count = 0;

    for (int m = 2; m * m < P; m++) {
        for (int n = 1; n < m; n++) {
            if (((m - n) % 2 == 1) && __gcd(m, n) == 1) {
                int a = m * m - n * n;
                int b = 2 * m * n;
                int c = m * m + n * n;
                int PP = a + b + c;

                if (P % PP == 0) {
                    int k = P / PP;
                    int A = k * a;
                    int B = k * b;
                    int C = k * c;
                    (void)A; (void)B; (void)C;
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PYTHAGORE.INP", "r", stdin);
    freopen("PYTHAGORE.OUT", "w", stdout);
    int t, P;
    cin >> t;
    while (t--) {
        cin >> P;
        cout << countRightTriangles(P) << "\n";
    }
    return 0;
}
