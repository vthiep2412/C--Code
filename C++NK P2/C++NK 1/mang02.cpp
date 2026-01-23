#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("mang02.inp", "r", stdin);
    freopen("mang02.out", "w", stdout);
    ll n;
    cin >> n;
    vc<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll maxi = LLONG_MAX;
    for (ll i = 1; i < n; i++) {
        maxi = min(maxi, abs(arr[i] - arr[i - 1]));
    }
    cout << maxi;
    return 0;
}
