#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int i = 2, t = 1, j = 0;
    if (n == 1) {
        return 1;
    }
    while (i <= n) {
        t = t + j;
        j = i * t;
        i++;
    }
    return j;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}