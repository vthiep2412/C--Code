#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("ESUM.inp", "r", stdin);
    // freopen("ESUM.out", "w", stdout);
    int l,r;
    cin >> l >> r;
    long long sum = 0;
    for (int i = l; i <= r; ++i) {
        if (i % 2 == 0) sum += i;
    }
    cout << sum;
    return 0;
}