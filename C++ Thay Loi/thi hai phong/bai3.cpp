#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);

    ll n, tar;
    cin >> n >> tar;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    unordered_map<ll, ll> m;
    long long res = 0;

    for (ll x : a) {
        ll rem = tar - x;
        if (m.count(rem)) res += m[rem];
        m[x]++;
    }
    cout << res << "\n";

    return 0;
}