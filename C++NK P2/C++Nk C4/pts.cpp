#include <bits/stdc++.h>
using namespace std;

#define ll long long

int smallerNearest(const vector<ll>& v, int x) {
    if (v.empty()) return -1;
    int l = 0, r = v.size() - 1, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] < x) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("pts.inp", "r", stdin);
    freopen("pts.out", "w", stdout);
    ll n, m, sumofKEO = 0;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < m; i++) {
        ll x = b[i];
        ll oi = smallerNearest(a, x);
        if (oi != -1) {
            sumofKEO += oi + 1;
        }
    }
    cout << sumofKEO;
    return 0;
}
