#include <bits/stdc++.h>
using namespace std;

double solve(int n, double x) {
    double s = 0,t = 1;
    int i = 1;
    while (i <= n) {
        t = t * i;
        s = s * x + 1 / t;
        i++;
    }
    return s;
}

int main() {
    int n;
    double x;
    cin >> n >> x;
    double ketqua = solve(n, x);
    cout << ketqua;
    return 0;
}