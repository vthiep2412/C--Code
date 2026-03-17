#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CLIMB.inp", "r", stdin);
    freopen("CLIMB.out", "w", stdout);
    ll n;
    cin >> n;
    vc<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll maxi = 0;
    ll start = 0;
    for (ll i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
        } else {
            if (i - 1 > start) {
                maxi = max(maxi, a[i - 1] - a[start]);
            }
            start = i;
        }
    }
    if (n - 1 > start) {
        maxi = max(maxi, a[n - 1] - a[start]);
    }
    cout << maxi << "\n";
    return 0;
}
