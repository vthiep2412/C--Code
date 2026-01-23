#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    double s = 0;
    int x = 0;
    while (s < n) {
        x++;
        s += sqrt(x);
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    double ketqua = solve(n);
    cout << ketqua;
    return 0;
}