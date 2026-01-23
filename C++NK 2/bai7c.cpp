#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int s = 0, b = n % 10, a = 0;
    while (n > 0) {
        a = n % 10;
        s = s + abs(a - b);
        b = a;
        n = n / 10;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}