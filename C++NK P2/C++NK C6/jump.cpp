#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getVal(ll n, ll r, ll c) {
    ll d = r + c - 1;
    if (d <= n) {
        ll base = (d - 1) * d / 2;
        if (d % 2 == 1) return base + c;
        return base + r;
    } else {
        ll base = n * n - (2 * n - d + 1) * (2 * n - d) / 2;
        if (d % 2 == 1) return base + c - (d - n);
        return base + r - (d - n);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("JUMP.INP", "r", stdin);
    freopen("JUMP.OUT", "w", stdout);

    ll n, m; string s;
    cin >> n >> m >> s;

    ll r = 1, c = 1;
    ll ans = 1;

    for (char move : s) {
        if (move == 'U') r--;
        else if (move == 'D') r++;
        else if (move == 'L') c--;
        else if (move == 'R') c++;
        
        ans += getVal(n, r, c);
    }

    cout << ans << "\n";

    return 0;
}