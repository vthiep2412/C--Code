#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("NODK.INP", "r", stdin);
    freopen("NODK.OUT", "w", stdout);

    ll l, r, k;
    cin >> l >> r >> k;

    ll sum = (l + r) * (r - l + 1) / 2;

    ll f1 = (l + k - 1) / k * k;
    if (f1 > r) {
        cout << sum;
        return 0;
    }
    ll f2 = r / k * k;
    ll cnt = (f2 - f1) / k + 1;
    ll sumDiv = (f1 + f2) * cnt / 2;

    cout << sum - sumDiv;
    return 0;
}
