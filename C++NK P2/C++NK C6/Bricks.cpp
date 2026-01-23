#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BRICKS.INP", "r", stdin);
    freopen("BRICKS.OUT", "w", stdout);
    ll G, Y;
    cin >> G >> Y;

    ll S = (G + 4) / 2;     // n + m
    ll P = G + Y;           // n * m

    ld D = (ld)S * S - (ld)4 * P;
    ll sqrtD = (ll)(sqrt(D) + 0.5);

    ll n = (S + sqrtD) / 2;
    ll m = (S - sqrtD) / 2;

    if (m > n) swap(m, n);
    cout << m << " " << n;

    return 0;
}