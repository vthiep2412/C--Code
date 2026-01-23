#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

vector<ll> solve(ll n) {
    vector<ll> div;
    ll x = sqrt(n);
    for (ll i = 1; i <= x; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) {
                div.push_back(n / i);
            }
        }
    }

    sort(div.begin(), div.end());
    return div;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("kthdiv.inp", "r", stdin);
    freopen("kthdiv.out", "w", stdout);
    ll n,k;
    cin >> n >> k;
    vector<ll> div = solve(n);
    if (k > 0 && k <= div.size()) {
        cout << div[k-1];
        // cout << "-1";
    } else {
        cout << "-1";
    }
    return 0;
}