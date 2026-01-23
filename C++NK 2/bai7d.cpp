#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int a = 0, b = 0, x = 0, y = 0;
    b = n % 10;
    while (n > 0) {
        a = n % 10;
        x = x + abs(a - b);
        b = a;
        n = n / 10;
        if (x > y) {
            y = x;
        }
    }
    return y;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}