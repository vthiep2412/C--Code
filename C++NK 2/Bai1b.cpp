#include <bits/stdc++.h>
using namespace std;

double solve(int n) {
    double s = 0, i = 2;
    while (i <= n) {
        s += (i - 1) / i;
        i += 1;
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