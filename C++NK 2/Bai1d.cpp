#include <bits/stdc++.h>
using namespace std;

double solve(int n) {
    double s = 0;
    int i = 0;
    while (i < n) {
        s = sqrt(2 + s);
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