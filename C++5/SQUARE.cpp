#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SQUARE.inp", "r", stdin);
    freopen("SQUARE.out", "w", stdout);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum = (sum + 1LL * i * i) % 2022;
    }
    cout << sum;
    return 0;
}

