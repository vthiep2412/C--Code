#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll lcmll(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("find.inp", "r", stdin);
    freopen("find.out", "w", stdout);

    ll a, b, n;
    cin >> a >> b >> n;

    ll L = lcmll(a, b);
    if (L > n) {
        cout << -1;
        return 0;
    }

    cout << (n / L) * L;
    return 0;
}
