#include <bits/stdc++.h>
using namespace std;

double solve(int a, double b, int n) {
    double TyLe = 1 + b / 100.0;
    double h = a;
    for (int i = 0; i < n; i++) {
        h *= TyLe;         
    }
    return h;
}

int main() {
    int a, n;
    double b;
    cin >> a >> b >> n;
    double result = solve(a, b, n);
    cout << result << "\n";
    return 0;
}
