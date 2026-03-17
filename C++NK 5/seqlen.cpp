#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SEQLEN.INP", "r", stdin);
    freopen("SEQLEN.OUT", "w", stdout);
    long long n;
    cin >> n;
    long long ans = 0, a = 1;
    int d = 1;
    while (a <= n) {
        long long b = a * 10 - 1;
        if (b > n) b = n;
        ans += (b - a + 1) * d;
        a *= 10;
        d++;
    }
    cout << ans;
    return 0;
}
