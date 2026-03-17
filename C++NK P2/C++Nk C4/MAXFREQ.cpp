#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MAXFREQ.INP", "r", stdin);
    freopen("MAXFREQ.OUT", "w", stdout);

    ll n;
    cin >> n;
    umap<ll, ll> map;
    ll res = LLONG_MAX, maxi = 0;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        map[x]++;
        if (map[x] > maxi) {
            maxi = map[x];
            res = x;
        } else if (map[x] == maxi && x < res) {
            res=x;
        }
    }

    cout << res << "\n";
    return 0;
}
