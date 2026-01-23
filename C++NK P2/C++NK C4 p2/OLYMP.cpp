#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("OLYMP.inp", "r", stdin);
    freopen("OLYMP.out", "w", stdout);
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> costs;
    ll oi = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a >= k) {
            oi++;
        } else if (b > 0) {
            ll need = k - a;
            ll t = (need + b - 1) / b;
            costs.push_back(t);
        }
    }
    sort(costs.begin(), costs.end());
    ll q = 0, p = 0;
    for (ll t : costs) {
        if (q + t > c) break;
        q += t;
        p++;
    }
    cout << (oi + p) << "\n";
    return 0;
}
