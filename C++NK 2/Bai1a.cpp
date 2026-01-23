#include <bits/stdc++.h>
using namespace std;

double solve(int n) {
    double s = 0;
    for (int i = 1; i <= n; ++i) {
        s += sqrt(i);
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