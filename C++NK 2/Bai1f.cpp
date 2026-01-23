#include <bits/stdc++.h>
using namespace std;

double solve(int n) {
    double s = 0, i = n;
    while (i >= 2) {
        s = 1 / (i + s);
        i--;
    }
    return s+1;
}
int main() {
    int n;
    cin >> n;
    double ketqua = solve(n);
    cout << ketqua;
    return 0;
}