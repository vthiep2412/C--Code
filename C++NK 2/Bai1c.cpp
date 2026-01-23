#include <bits/stdc++.h>
using namespace std;

double solve(int n) {
    double s = 0, t = 1;
    int i = 1;
    while (i <= n) {
        t *= i;
        if (i % 2 == 0) {
            s -= 1 / t;
        } else {
            s += 1 / t;
        }
        i++;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    double ketqua = solve(n);
    cout << ketqua;
    return 0;
}